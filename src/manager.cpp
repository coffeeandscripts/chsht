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

/* function -
 * desc:
 */
void Manager::print() {
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "less -FX .\\/docs\\/sheets\\/%s.chsht", input);
        system(buf);
}

/* function -
 * desc:
 */
int Manager::checkFile(){
        char buf[BUFSIZ];
        std::cout << "checking file..." << std::endl;
        snprintf(buf ,sizeof(buf), "[ -f \"./docs./sheets/vim.chsht\" ] && echo 1 || echo 0");
        int check_default = stoi(terminal_stdout(buf));
        if( check_default == 1 ){
                std::cout << "File Exists" << std::endl;
                return 1;
        }else {
                std::cout <<" File Does Not Exist" << std::endl;
                return 0;
        }
}
