/* chsht - console cheatsheet viewer
 * manager.hpp
 * desc: header for manager class
 * vers: 0.0.1
 */

#ifndef PROJECT_MANAGER_
#define PROJECT_MANAGER_

#include "setup.hpp"

extern std::string terminal_stdout(std::string cmd);

class Manager {
private:
        char *input;
        char const *sheet_dir;
public:
        Manager(char *, Setup);
        ~Manager();
        void print();
        int checkFile();
};

#endif
