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
                        std::cout << "Worked" << std::endl;
                        //just testing with a set input first, then can take arg input
                        //if testing using the commandline arguments, replace a with Interpreter::input
                        //i found this on the internet, so not 100% on what this does
                        //char a[] = "vim";
                        //char buf[150];
                        //for snprintf??? char buf[BUFSIZ]
                        // or use snprintf to prevent buffer being too small??? snprintf(buf, sizeof(buf) , "text %s", a)
                        //sprintf(buf, "sed -i '2s/.*/less -FX .\/docs\/sheets\/%s.chsht/' ./docs/sheets/open.sh" | ./docs./sheets/open.sh", a);
                        //want to check if this got stored correctly
                        //std::cout << "buffer is:   " << buf << endl;
                        //theoreticall this should work?
                        //system(buf);
                }
        }
        return 0;
}
