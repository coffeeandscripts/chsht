#include <stdlib.h>
#include <cstring>

#include "project/interpreter.hpp"

int main (int argc, char *argv[]) {
        Interpreter c(argc, argv[]);
        if (c.check_args()) {
                if(c.eval_args()) {
                        system("sed -i '2s/.*/less -FX .\/docs\/sheets\/vim.chsht/' ./docs/sheets/open.sh" | ./docs./sheets/open.sh );
                }
        }
        return 0;
}
