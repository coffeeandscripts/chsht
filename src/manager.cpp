/* chsht - console cheatsheet viewer
 * manager.cpp
 * desc: functions to manipulate chsht files
 * vers: 0.0.1
 */

 #include <iostream>

#include "project/manager.hpp"

/* class - Manager constructor
 * desc: allocates memory to store console arguments
 */
Manager::Manager (char *n) {
        input = n;
}

/* class - Manager deconstructor
 * desc: currently clear but open to memory clearing to prevent memory leaks
 */
Manager::~Manager() {
}

void Manager::print() {
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "sed -i '2s/.*/less -FX .\\/docs\\/sheets\\/%s.chsht/' ./docs/sheets/open.sh | ./docs/sheets/open.sh", input);
        system(buf);
}
