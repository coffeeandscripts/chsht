/* chsht - console cheatsheet viewer
 * interpreter.cpp
 * desc: functions to evaluate and react to given commands
 * vers: 0.0.1
*/

#include <iostream>
#include <cstring>

#include "project/interpreter.hpp"

#define FAIL_CASE "Type chsht -h for available commands"

/* class - Interpreter constructor
 * desc: allocates memory to store console arguments
*/
Interpreter::Interpreter (int _n_arg, char *_args[]) {
        n_arg = _n_arg;
        args = _args;
}

/* class - Interpreter deconstructor
 * desc: currently clear but open to memory clearing to prevent memory leaks
*/
Interpreter::~Interpreter() {
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

/* func - eval_args
 * desc: evaluates the meaning of given args (whether -x or raw statement)
*/
int Interpreter::eval_args() {
        input = args[1];
        if (input[0] == '-' && (strlen(input) == 2)) {
                switch (input[1]) {
                case 'h':
                        std::cout << "Listing available commands:" << std::endl;
                        system("less -FX ./docs/help.txt");
                        break;
                case 'n':
                        std::cout << "Creating new entry..." << std::endl;
                        break;
                default:
                        std::cout << FAIL_CASE << std::endl;
                        break;
                }
        } else if (n_arg > 2) {
                std::cout << FAIL_CASE << std::endl;
        } else {
                return 1;
        }
        return 0;
}
