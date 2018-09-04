
/* chsht - console cheatsheet viewer
 * instructions.cpp
 * desc: functions to manipulate chsht files
 * vers: 0.0.1
 */

 #include <iostream>

#include "project/instructions.hpp"


/* class - Instructions constructor
 * desc: allocates memory to store console arguments
 */
Instructions::Instructions (char *n) {
        input = n;
}

/* class - Instructions deconstructor
 * desc: currently clear but open to memory clearing to prevent memory leaks
 */
Instructions::~Instructions() {
}

/* class - create_new
 * desc: copies default sheets into sheets directory and renames from user input
 *        and replaces *default* text with user input
 */
void Instructions::create_new(){
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "cp .\\/docs\\/default.chsht .\\/docs\\/sheets\\/%s.chsht", input);
        system(buf);
        snprintf(buf ,sizeof(buf), "sed -i 's/default/%s/' .\\/docs\\/sheets\\/%s.chsht", input, input);
        system(buf);
}
