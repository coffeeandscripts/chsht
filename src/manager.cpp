/* chsht - console cheatsheet viewer
 * manager.cpp
 * desc: functions to manipulate chsht files
 * vers: 0.0.1
 */

#include <iostream>

#include "project/manager.hpp"

#define SYSTEM_ERROR 256

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
        snprintf(buf ,sizeof(buf), "less -FX ./docs/sheets/%s.chsht 2>/dev/null", input);
        if( system(buf) == SYSTEM_ERROR ){
            std::cout << "There are no sheets available for " << input << "."<< std::endl;
            std::cout << "Use chsht -n " << input << " to create a new sheet" << std::endl;
        }
}
