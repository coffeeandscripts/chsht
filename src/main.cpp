/* chsht - console cheatsheet viewer
 * main.cpp
 * desc: main function to interpret console commands
 * vers: 0.0.1
*/

#include <stdlib.h>
#include <stdio.h> //this is for the snprintf function
#include <iostream>

#include "project/interpreter.hpp"

int main (int argc, char *argv[]) {
        Interpreter c(argc, argv);
        if (c.check_args()) {
                if(c.eval_args()) {
                        char a[] = "vim";
                        char buf[BUFSIZ];
                        snprintf(buf ,sizeof(buf), "sed -i '2s/.*/less -FX .\\/docs\\/sheets\\/%s.chsht/' ./docs/sheets/open.sh | ./docs/sheets/open.sh", a);
                        system(buf);
                }
        }
        return 0;
}
