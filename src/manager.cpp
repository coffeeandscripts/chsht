/* chsht - console cheatsheet viewer
 * manager.cpp
 * desc: functions to manipulate chsht files
 * vers: 0.0.1
 */

#include <iostream>
#include <fstream>
#include <cstring>

#include "manager.hpp"
#include "setup.hpp"

#define SYSTEM_ERROR 256


/* class - Manager constructor
 * desc: allocates memory to store console arguments
 */
Manager::Manager (char *n, Setup s_engine) {
        input = n;
        sheet_dir = s_engine.read_conf("directory");
        title = 0;
        cmd[0] = '\0';
        n_cmd = 0;
}

/* class - Manager deconstructor
 * desc: currently clear but open to memory clearing to prevent memory leaks
 */
Manager::~Manager() {
}

void Manager::print_cmd(std::string cmd) {
        if (cmd == "<yellow>") {
                std::cout << "YELLOW";
        } else if (cmd == "</yellow>") {
                std::cout << "CLOSE";
        }
}

void Manager::mode_set(char ch) {
        if (ch == '<') {
                cmd = ch;
                n_cmd++;
        } else if (n_cmd > 0) {
                cmd += ch;
                n_cmd++;
        }
        if (n_cmd == 16) {
                std::cout << cmd;
                cmd = "";
                n_cmd = 0;
        } else if (n_cmd == 0) {
                std::cout << ch;
        }
        if (ch == '>' && n_cmd > 0) {
                print_cmd(cmd);
                n_cmd = 0;
                cmd = "";
        }
}

void Manager::interpret_file() {
        std::ifstream fin;
        fin.open("docs/default.chsht", std::ios::in);
        char ch;
        while (!fin.eof() ) {
        	fin.get(ch);
        	mode_set(ch);
	}
}

/* function -
 * desc:
 */
void Manager::print() {
        char buf[BUFSIZ];
        interpret_file();
        snprintf(buf ,sizeof(buf), "less -FX .\\/docs\\/sheets\\/%s.chsht 2>/dev/null", input);
        if (system(buf)== SYSTEM_ERROR){
            std::cout << "File does not exist. Type -h for help" << std::endl;
        }
}

/* function -
 * desc:
 */
int Manager::checkFile(){
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "[ -f \"./docs/sheets/%s.chsht\" ] && echo 1 || echo 0", input);
        int check_default = stoi(terminal_stdout(buf));
        if( check_default == 1 ){
                std::cout << "File Exists" << std::endl;
                return 1;
        }else {
                std::cout <<" File Does Not Exist" << std::endl;
                return 0;
        }
}
