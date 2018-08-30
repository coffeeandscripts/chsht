/* chsht - console cheatsheet viewer
 * main.cpp
 * desc: main function to interpret console commands
 * vers: 0.0.1
 */

#include <stdlib.h>

#include <iostream>

#include "project/interpreter.hpp"

int main (int argc, char *argv[]) {
        Interpreter c(argc, argv);
        if (c.check_args()) {
                if(c.eval_args()) {
                        //
                }
        }
        return 0;
}
