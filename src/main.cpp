/* chsht - console cheatsheet viewer
 * main.cpp
 * desc: main function to interpret console commands
 * vers: 0.0.1
 */

#include <stdlib.h>

#include <iostream>

#include "project/interpreter.hpp"
#include "project/manager.hpp"
#include "project/instructions.hpp"
//std::string terminal_stdout(std::string cmd);


int main (int argc, char *argv[]) {
        Interpreter c(argc, argv);
        if (c.check_args()) {
                if(c.eval_args()) {
                        Manager m(c.get_input());
                        m.print();
                        m.~Manager();

                }
        }
        c.~Interpreter();
        return 0;
}

std::string terminal_stdout (std::string cmd){
      std::string data;
      FILE * stream;
      //how can i optimise the memory used here.
      //just realised i misinterpreted stuff. BUFSIZ is giving it the maximum
      //space so that we dont run out of space in the buffer for the temrinal command
      //dynamically allocated memory?
      //although this will get wiped once functiosn done anyways
     //const int max_buffer = 256;
      char buffer[BUFSIZ];
      //2>&1 combines stderr and stdout into stdout
      cmd.append(" 2>&1");

      stream = popen(cmd.c_str(), "r");
      if (stream) {
          while (!feof(stream))
          if (fgets(buffer, BUFSIZ, stream) != NULL) data.append(buffer);
          pclose(stream);
      }
      return data;
}
