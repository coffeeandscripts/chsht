#ifndef PROJECT_INTERPRETER_
#define PROJECT_INTERPRETER_

class Interpreter{
        char *input;
        int n_arg;
        char *args[];
public:
        Interpreter(int _n_arg, char *_args[]);
        int check_args(int n_arg);
        int eval_args(char *args[]);
}

#endif
