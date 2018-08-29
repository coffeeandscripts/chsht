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
        char const *default_editor;
        char *editor;
public:
        Interpreter(int _n_arg, char *_args[]);
        ~Interpreter();
        char *get_input();
        int check_args();
        void interpret_args(char descriptor);
        void interpret_args(char descriptor, char *query);
        int eval_args();
};

#endif
