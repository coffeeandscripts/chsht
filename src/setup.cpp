/* chsht - console cheatsheet viewer
 * setup.cpp
 * desc: functions to prepare and setup the environment on run
 * vers: 0.0.1
 */

#include <iostream>

#include "project/setup.hpp"

#define INITIAL_SETUP "Running initial setup procedures..."



/* class - Setup constructor
 * desc:
 */
Setup::Setup() {
}

/* class - Setup deconstructor
 * desc: currently clear but open to memory clearing to prevent memory leaks
 */
Setup::~Setup() {
}

/* function - exists
 * desc: checks to see if directory or file exists
 */
int Setup::exists(char const *dir_or_file) {
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "test -e %s", dir_or_file);
        if (!system(buf)) {
                return 1;
        }
        return 0;
}

/* function - run
 * desc: at startup to check integrity of directories
 */
int Setup::run() {
        if (!exists("~/.chsht")) {
                system("mkdir ~/.chsht");
        }
        if (!exists("~/.chsht/sheets")) {
                system("mkdir ~/.chsht/sheets");
        }
        if (!exists("~/.chsht/chsht.conf")) {
                system("cp docs/chsht.conf ~/.chsht/chsht.conf");
        }
        return 1;
}

/* function - reset
 * desc: deletes ~/.chsht and runs run()
 */
void Setup::reset() {
        system("rm -rf ~/.chsht");
        run();
}

/* class - read_conf
 * desc: given term to look up in conf and returns result
 */
char const *Setup::read_conf(char const *term) {
        return term;
}
