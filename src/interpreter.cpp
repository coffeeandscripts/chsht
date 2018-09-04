/* chsht - console cheatsheet viewer
 * interpreter.cpp
 * desc: functions to evaluate and react to given commands
 * vers: 0.0.1
 */

#include <iostream>
#include <cstring>
#include <stdio.h> //this is for the snprintf function
#include <stdlib.h>

#include "project/interpreter.hpp"
#include "project/instructions.hpp"

#define FAIL_CASE "Type chsht -h for available commands"



/* class - Interpreter constructor
 * desc: allocates memory to store console arguments
 */
Interpreter::Interpreter (int _n_arg, char *_args[]) {
        n_arg = _n_arg;
        args = _args;
        //figures out which default editor to use. Do we want this as a seperate function
        //or just leave it as is?. Will we need to actively figure out the default editor anywhere else?
        //i dont think it is needed, but check with you first
        int check_default = stoi(terminal_stdout("[ -z $EDITOR ] && echo 1 || echo 0"));
        if( check_default == 0 ){
                default_editor = "$EDITOR";
                std::cout << "$EDITOR set as default editor" << std::endl;
        }else {
                default_editor = "vi";
                std::cout << default_editor <<" set as default editor" << std::endl;
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
char *Interpreter::get_input() {
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

/* func - interpret_args
 * desc: takes descriptor and returns an output
 */
void Interpreter::interpret_args(char descriptor) {
        switch (descriptor) {
        case 'h':
                std::cout << "Listing available commands:" << std::endl;
                system("less -FX ./docs/help.txt");
                break;
        case 'l':
                // list all sheets current in docs/sheets/
                break;
        default:
                std::cout << FAIL_CASE << std::endl;
                break;
        }
}

/* func - interpret_args
 * desc: takes descriptor and the adjacent query and returns an output
 */
void Interpreter::interpret_args(char descriptor, char *query) {
        Instructions A(query);
        switch (descriptor) {
        case 'n':
                std::cout << "Creating new entry for " << query << std::endl;
                A.create_new();
                break;
        case 'l':
                // list all sheets current in docs/sheets/ using a "fuzzy-find" of query
                break;
        case 'a':
                // adds the given file to docs/sheets/ after converting to .chsht file
                break;
        case 'e':
                //opens sheet for editing  in default editor


                break;
        default:
                std::cout << FAIL_CASE << std::endl;
                break;
        }
        A.~Instructions();
}

/* func - eval_args
 * desc: evaluates the meaning of given args (whether -x or raw statement)
 */
int Interpreter::eval_args() {
        for(int n = 1; n < n_arg; n++) {
                if (args[n][0] == '-' && (strlen(args[n]) == 2)) {
                        if (n < n_arg - 1) {
                                interpret_args(args[n][1], args[n+1]);
                                n++;
                        } else {
                                interpret_args(args[n][1]);
                        }
                } else {
                        input = args[n];
                        return 1;
                }
        }
        return 0;
}
