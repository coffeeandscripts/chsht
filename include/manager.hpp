/* chsht - console cheatsheet viewer
 * manager.hpp
 * desc: header for manager class
 * vers: 0.0.1
 */

#ifndef PROJECT_MANAGER_
#define PROJECT_MANAGER_

#include <cstring>

#include "setup.hpp"

#define CMD_SIZE 16

extern std::string terminal_stdout(std::string cmd);

class Manager {
private:
        char *input;
        char const *sheet_dir;
        int title;
        std::string cmd;
        int n_cmd;
public:
        Manager(char *, Setup);
        ~Manager();
        void print_cmd(std::string);
        void mode_set(char);
        void interpret_file();
        void print();
        int checkFile();
};

#endif
