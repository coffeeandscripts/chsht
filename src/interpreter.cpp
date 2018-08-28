#include <iostream>

#include "project/interpreter.hpp"

#define FAIL_CASE "Type chsht -h for available commands"

Interpreter::Interpreter (int _n_arg, char *_args[]) {
        n_arg = _n_arg;
        args[] = _args[];
}

int Interpreter::check_args() {
        if (n_arg <= 1) {
                std::cout << FAIL_CASE << std::endl;
                return 0;
        } else {
                return 1;
        }
}

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
                return 0;
                }
        } else if (n_arg > 2) {
                std::cout << FAIL_CASE << std::endl;
                return 0;
        } else {
                return 1;
        }
}
