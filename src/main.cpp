/* chsht - console cheatsheet viewer
 * main.cpp
 * desc: main function to interpret console commands
 * vers: 0.0.1
 */

#include <stdlib.h>

#include <iostream>

#include "project/interpreter.hpp"
#include "project/manager.hpp"

std::string terminal_stdout(std::string cmd);


int main (int argc, char *argv[]) {
        Interpreter c(argc, argv);
        if (c.check_args()) {
                if(c.eval_args()) {
                        Manager m(c.get_input());
                        m.print();
                }
        }
        return 0;
}

std::string terminal_stdout (std::string cmd){
      std::string data;
      FILE * stream;
      const int max_buffer = 256;
      char buffer[max_buffer];
      cmd.append(" 2>&1");

      stream = popen(cmd.c_str(), "r");
      if (stream) {
          while (!feof(stream))
          if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
          pclose(stream);
      }
      return data;
}
