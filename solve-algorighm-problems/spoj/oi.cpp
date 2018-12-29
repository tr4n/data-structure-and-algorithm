// ios::eof example
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
using namespace std; 

int main () {

  std::ifstream is("int.txt");   // open file

  char c;
  while (is.get(c))                  // loop getting single characters
    std::cout << c;

  if (is.eof())                      // check for EOF
    std::cout << "[EoF reached]\n";
  else
    std::cout << "[error reading]\n";

  is.close();                        // close file

  return 0;
}
