/* chsht - console cheatsheet viewer
 * manager.cpp
 * desc: functions to manipulate chsht files
 * vers: 0.0.1
 */

 #include <iostream>

#include "project/manager.hpp"
#include "project/setup.hpp"

#define SYSTEM_ERROR 256

/* class - Manager constructor
 * desc: allocates memory to store console arguments
 */
Manager::Manager (char *n, Setup s_engine) {
        input = n;
        sheet_dir = s_engine.read_conf("directory");
}

/* class - Manager deconstructor
 * desc: currently clear but open to memory clearing to prevent memory leaks
 */
Manager::~Manager() {
}

/* function -
 * desc:
 */
void Manager::print() {
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "less -FX .\\/docs\\/sheets\\/%s.chsht 2>/dev/null", input);
        if (system(buf)== SYSTEM_ERROR){
            std::cout << "File does not exist. Type -h for help" << std::endl;
        }
}

/* function -
 * desc:
 */
int Manager::checkFile(){
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "[ -f \"./docs/sheets/%s.chsht\" ] && echo 1 || echo 0", input);
        int check_default = stoi(terminal_stdout(buf));
        if( check_default == 1 ){
                std::cout << "File Exists" << std::endl;
                return 1;
        }else {
                std::cout <<" File Does Not Exist" << std::endl;
                return 0;
        }
}
