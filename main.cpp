#include <iostream>
#include "Sorting.h"

using namespace std;

int main(int argc, char** argv)
{
  Sorting s;

  if (argc < 2) //if no file given in command line argument
  {
      cout << "ERROR: Please Enter Valid File Input\n" << endl;
  }
  else if (argc >= 2) //if commandline argument is given
  {
      string file = argv[1]; //set file equal to argv
      s.setInputFile(file);
  }
  return 0;
}
