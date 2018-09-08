/* chsht - console cheatsheet viewer
 * instructions.hpp
 * desc: header for instructions class
 * vers: 0.0.1
 */

#ifndef PROJECT_INSTRUCTIONS_
#define PROJECT_INSTRUCTIONS_

class Instructions {
private:
        char *input;

public:
        Instructions(char *);
        ~Instructions();
        void create_new();
};

#endif
