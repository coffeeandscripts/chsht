
#include "project/vector.hpp"
#include <stdlib.h>

int main () {
  Vector a(1,2,3), b(3,2,1), c(0,0,0);
  a = a + b;
  a.print();
  a = a * b;
  a.print();
  a = a * c;
  a.print();
//run the bash file from chsht directory
  system("./src/test.sh");
  return 0;
}
