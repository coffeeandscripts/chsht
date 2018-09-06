/* chsht - console cheatsheet viewer
 * interpreter.hpp
 * desc: header for interpreter class
 * vers: 0.0.1
 */

#ifndef PROJECT_INTERPRETER_
#define PROJECT_INTERPRETER_

#include "project/setup.hpp"

extern std::string terminal_stdout(std::string cmd);

class Interpreter {
private:
        char *input;
        int n_arg;
        char **args;
        char const *default_editor;
        char *editor;
        char const *sheets_dir;
public:
        Interpreter(int _n_arg, char *_args[], Setup);
        ~Interpreter();
        char *get_input();
        int check_args();
        void interpret_args(char descriptor);
        void interpret_args(char descriptor, char *query);
        int eval_args();

//friend std::string terminal_stdout(std::string cmd);
//doesnt need to be friend, since its taking in a striaght string only.
};

#endif
