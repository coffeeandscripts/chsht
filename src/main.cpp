/* chsht - console cheatsheet viewer
 * main.cpp
 * desc: main function to interpret console commands
 * vers: 0.0.1
 */

#include <stdlib.h>

#include <iostream>

#include "project/interpreter.hpp"
#include "project/manager.hpp"
#include "project/setup.hpp"

//std::string terminal_stdout(std::string cmd);


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
