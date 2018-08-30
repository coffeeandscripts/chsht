/* chsht - console cheatsheet viewer
 * manager.hpp
 * desc: header for manager class
 * vers: 0.0.1
 */

#ifndef PROJECT_MANAGER_
#define PROJECT_MANAGER_

class Manager {
        char *input;
public:
        Manager(char *);
        ~Manager();
        void print();
};

#endif