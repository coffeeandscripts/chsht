/* chsht - console cheatsheet viewer
 * interpreter.hpp
 * desc: header for interpreter class
 * vers: 0.0.1
*/

#ifndef PROJECT_INTERPRETER_
#define PROJECT_INTERPRETER_

class Interpreter {
        char *input;
        int n_arg;
        char **args;
public:
        Interpreter(int _n_arg, char *_args[]);
        int check_args();
        int eval_args();
};

#endif
