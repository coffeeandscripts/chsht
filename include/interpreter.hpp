/* chsht - console cheatsheet viewer
 * interpreter.hpp
 * desc: header for interpreter class
 * vers: 0.0.1
 */

#ifndef PROJECT_INTERPRETER_
#define PROJECT_INTERPRETER_

#include "setup.hpp"

extern std::string terminal_stdout(std::string cmd);

class Interpreter {
private:
        char *input;
        int n_arg;
        char **args;
        char const *default_editor;
        char const *editor;
        char const *sheets_dir;
        Setup setup_engine;
public:
        Interpreter(int _n_arg, char *_args[], Setup);
        ~Interpreter();
        char *get_input();
        int check_args();
        void interpret_args();
        int eval_args();
        void new_sheet(char const *);
        void list_sheets();
        void list_sheets(char const *);
        void add_sheet(char const *);
        void set_editor(char const *);
        void edit_sheet(char const *);
        void remove_sheet(char const *);
        void help();
        void reset();
        void check_slash(char []);
};

#endif
