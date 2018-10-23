/* chsht - console cheatsheet viewer
 * interpreter.cpp
 * desc: functions to evaluate and react to given commands
 * vers: 0.0.1
 */

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#include "interpreter.hpp"
#include "setup.hpp"
#include "cxxopts.hpp"

#define FAIL_CASE "Type chsht -h for available commands"

/* class - Interpreter constructor
 * desc: allocates memory to store console arguments
 */
Interpreter::Interpreter (int _n_arg, char *_args[], Setup s_engine) {
        n_arg = _n_arg;
        args = _args;
        editor = NULL;
        sheets_dir = s_engine.read_conf("~/.chsht/sheets");
        setup_engine = s_engine;
        int check_default = stoi(terminal_stdout("[ -z $EDITOR ] && echo 1 || echo 0"));
        if( check_default == 0 ){
                default_editor = "$EDITOR";
        }else {
                default_editor = "vi";
        }
}

/* class - Interpreter deconstructor
 * desc: currently clear but open to memory clearing to prevent memory leaks
 */
Interpreter::~Interpreter() {
}

/* func - get_input
 * desc: returns the value of input that is stored in eval_args()
 */
std::string Interpreter::get_input() {
        return input;
}

/* func - check_args
 * desc: checks to see if there are any args given
 */
int Interpreter::check_args() {
        if (n_arg <= 1) {
                std::cout << FAIL_CASE << std::endl;
        } else {
                return 1;
        }
        return 0;
}

/* func - new_sheet
 * desc: copies default sheet to set location
 */
void Interpreter::new_sheet(char const *new_val) {
        char buf[BUFSIZ];
        std::cout << "Creating new entry for " << new_val << std::endl;
        strcpy(buf, "cp ~/.chsht/default.chsht ");
        strcat(buf, sheets_dir);
        check_slash(buf);
        strcat(buf, new_val);
        strcat(buf, ".chsht");
        system(buf);
        edit_sheet(new_val);
}

/* func - list_sheets
 * desc: lists all the sheets in set location
 */
void Interpreter::list_sheets() {
        char buf[BUFSIZ];
        std::cout << "Listing all sheets:" << std::endl;
        strcpy(buf, "ls -R ");
        strcat(buf, sheets_dir);
        system(buf);
}

/* func - interpret_args
 * desc: runs regex to find sheets in set location
 */
void Interpreter::list_sheets(char const *list_reg) {
        char buf[BUFSIZ];
        std::cout << "Listing sheets with regex: " << list_reg << std::endl;
        strcpy(buf, "ls -R ");
        strcat(buf, sheets_dir);
        check_slash(buf);
        strcat(buf, " | grep  -i ");
        strcat(buf, list_reg);
        system(buf);
}

/* func - add_sheet
 * desc: copies prebuilt sheet and changes file type
 */
void Interpreter::add_sheet(char const *add_val) {
        char buf[BUFSIZ];
        std::cout << "Adding " << add_val << std::endl;
        strcpy(buf, "filename=$(basename -- ");
        strcat(buf, add_val);
        strcat(buf, ") && cp ");
        strcat(buf, add_val);
        strcat(buf, " ");
        strcat(buf, sheets_dir);
        check_slash(buf);
        strcat(buf, "${filename/.*}.chsht");
        system(buf);
}

/* func - set_editor
 * desc: allows for custom text editor to be set
 */
void Interpreter::set_editor(char const *editor_val) {
        std::cout << "Setting text editor as " << editor_val << std::endl;
        editor = editor_val;
}

/* func - edit_sheet
 * desc: edits given sheet using default editor or set editor
 */
void Interpreter::edit_sheet(char const *edit_val) {
        char buf[BUFSIZ];
        std::cout << "Editting " << edit_val << std::endl;
        if(editor) {
                strcpy(buf, editor);
                strcat(buf, " ");
                strcat(buf, sheets_dir);
                check_slash(buf);
                strcat(buf, edit_val);
                strcat(buf, ".chsht");
        } else {
                strcpy(buf, default_editor);
                strcat(buf, " ");
                strcat(buf, sheets_dir);
                check_slash(buf);
                strcat(buf, edit_val);
                strcat(buf, ".chsht");
        }
        system(buf);
}

/* func - remove_sheet
 * desc: removes a sheet from set location
 */
void Interpreter::remove_sheet(char const *remove_val) {
        char buf[BUFSIZ];
        std::cout << "Removing " << remove_val << std::endl;
        strcpy(buf, "rm ");
        strcat(buf, sheets_dir);
        check_slash(buf);
        strcat(buf, remove_val);
        strcat(buf, ".chsht");
        system(buf);
}

/* func - help
 * desc: prints help commands
 */
void Interpreter::help() {
        std::cout << "Listing available commands:" << std::endl;
        system("less -FX ~/.chsht/help.txt");
}

void Interpreter::reset() {
        setup_engine.reset();
}

/* func - check_slash
 * desc: makes sure there is a slash at the end of a string
 */
void Interpreter::check_slash(char buf[BUFSIZ]) {
        if (!(*buf && buf[strlen(buf + 1)] == '/')) {
                strcat(buf, "/");
        }
}

/* func - eval_args
 * desc: evaluates the meaning of given args (whether -x or raw statement)
 */
int Interpreter::eval_args() {
        cxxopts::Options options("chsht", "terminal cheatsheet");
        options.add_options()
                ("n,new", "New sheet", cxxopts::value<std::string>())
                ("l,list", "List sheets", cxxopts::value<std::string>())
                ("list-all", "List all sheets")
                ("a,add", "Add sheet", cxxopts::value<std::string>())
                ("set-editor", "Set editor", cxxopts::value<std::string>())
                ("e,edit", "Edit sheet", cxxopts::value<std::string>())
                ("r,remove", "Remove sheet", cxxopts::value<std::string>())
                ("v,view", "View sheet", cxxopts::value<std::string>())
                ("reset", "Delete ~/.chsht directory")
                ("h,help", "Help")
                ;
        auto result = options.parse(n_arg, args);
        if (result.count("new")) {
                new_sheet(result["new"].as<std::string>().c_str());
        }
        if (result.count("list")) {
                list_sheets(result["list"].as<std::string>().c_str());
        }
        if (result.count("list-all")) {
                list_sheets();
        }
        if (result.count("add")) {
                add_sheet(result["add"].as<std::string>().c_str());
        }
        if (result.count("set-editor")) {
                set_editor(result["set-editor"].as<std::string>().c_str());
        }
        if (result.count("edit")) {
                edit_sheet(result["edit"].as<std::string>().c_str());
        }
        if (result.count("help")) {
                help();
        }
        if (result.count("remove")) {
                remove_sheet(result["remove"].as<std::string>().c_str());
        }
        if (result.count("reset")) {
                reset();
        }
        if (result.count("view")) {
                input = result["view"].as<std::string>();
                return 1;
        }
        return 0;
}
