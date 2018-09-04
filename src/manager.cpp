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

/* function - print
 * desc: Prints sheet onto terminal, gives warning if file does not exist
 */
void Manager::print() {
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "less -FX .\\/docs\\/sheets\\/%s.chsht 2>/dev/null", input);
        if (system(buf)== SYSTEM_ERROR){
            std::cout << "File does not exist. Type -h for help" << std::endl;
        }
}

/* function - check_file
 * desc: checks if file exists in sheets directory, returns 1 or 0 (true or false)
 */
int Manager::check_file(){
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "[ -f \"./docs/sheets/%s.chsht\" ] && echo 1 || echo 0", input);
        int check_default = stoi(terminal_stdout(buf));
        if( check_default == 1 ){
                return 1;
        }else {
                return 0;
        }
}
