
/* chsht - console cheatsheet viewer
 * instructions.cpp
 * desc: functions to manipulate chsht files
 * vers: 0.0.1
 */

 #include <iostream>

#include "project/instructions.hpp"

#define SYSTEM_ERROR 256

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
 * desc: currently clear but open to memory clearing to prevent memory leaks
 */
void create_new (){

}
