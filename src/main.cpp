
#include "project/vector.hpp"
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;



int main (int argc, char *argv[]) {
  //Cant take command line inputs of just ./chsht. otherwise argv[1] wills segfault
  if (argc <= 1){
    cout << "Invalid Selection" << endl;
    return 0;
  }

  //takes the second argument in the command line and stores it to a string
  //could be done without this by referencing as a 2x2 array
  char *input = argv[1];
  //checking that the input format is correct: "-x"
  if ((input[0] != '-') || (strlen(input) != 2) ){
    cout << "Invalid Selection" << endl;
    return 0;
  }

  //using switch command to run various functions
  char command = input[1];
  switch (command){
    case 'h' :
      cout << "Listing available commands:" << endl;
      system("less -FX ./src/help.txt");
      break;
    case 'n' :
      cout << "Creating new entry..." << endl;
      break;
    default :
      cout << "Invalid Selection" << endl;
      return 0;
  }


  return 0;
}
