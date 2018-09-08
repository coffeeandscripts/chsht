/* chsht - console cheatsheet viewer
 * main.cpp
 * desc: main function to interpret console commands
 * vers: 0.0.1
 */

#include <stdlib.h>
#include <iostream>

#include "interpreter.hpp"
#include "manager.hpp"
#include "setup.hpp"

int main (int argc, char *argv[]) {
        Setup s_engine;
        Interpreter c(argc, argv, s_engine);
        if (c.check_args() && s_engine.run()) {
                if(c.eval_args()) {
                        Manager m(c.get_input(), s_engine);
                        m.print();
                        m.checkFile();
                }
        }
        return 0;
}

std::string terminal_stdout (std::string cmd){
      std::string data;
      FILE * stream;
      char buffer[BUFSIZ];
      cmd.append(" 2>&1");
      stream = popen(cmd.c_str(), "r");
      if (stream) {
          while (!feof(stream))
          if (fgets(buffer, BUFSIZ, stream) != NULL) data.append(buffer);
          pclose(stream);
      }
      return data;
}
