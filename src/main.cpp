
#include <stdlib.h>
#include <cstring>
#include <iostream>     //remove when files moved

#include "project/interpreter.hpp"

//currently no functionality for "--help"
#define FAIL_CASE "Type chsht -h or *--help* for available commands"

// PLACE IN project/interpreter.hpp
#ifndef PROJECT_INTERPRETER_
#define PROJECT_INTERPRETER_

class Interpreter{
        char *input;
        int n_arg;
        char *args[];
public:
        Interpreter(n_args, args);
        int check_args(int n_arg);
        int eval_args(char *args[]);
}

#endif
// END

// PLACE IN src/interpreter.cpp
#include <iostream>

#include "project/interpreter.hpp"

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
// END

int main (int argc, char *argv[]) {
        Interpreter c(argc, argv);
        if (c.check_args()) {
                if(c.eval_args()) {
                        system("sed -i '2s/.*/less -FX .\/docs\/sheets\/vim.chsht/' ./docs/sheets/open.sh" | ./docs./sheets/open.sh );              // look at you using pipes

                }
        }
        return 0;
}



  return 0;
}
