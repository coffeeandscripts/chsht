#include <stdlib.h>
#include <cstring>
#include <iostream> #delete later

#include "project/interpreter.hpp"

int main (int argc, char *argv[]) {
        Interpreter c(argc, argv[]);
        if (c.check_args()) {
                if(c.eval_args()) {
                        //just testing with a set input first, then can take arg input
                        //i found this on the internet
                        char a[] = "vim";
                        char buf[150];
                        //for snprintf??? char buf[BUFSIZ]
                        // or use snprintf to prevent buffer being too small??? snprintf(buf, sizeof(buf) , "text %s", a)
                        sprintf(buf, "sed -i '2s/.*/less -FX .\/docs\/sheets\/%s.chsht/' ./docs/sheets/open.sh" | ./docs./sheets/open.sh", a);
                        //want to check if this got stored correctly
                        std::cout << "buffer is:   " << buf << endl;
                        //theoreticall this should work?
                        system(buf);
                }
        }
        return 0;
}
