#include "rshell.h"
#include <boost/tokenizer.hpp>

int main()
{
  const int MAX_CHAR = 100;
  char input[MAX_CHAR];

  cout << "Enter your command: ";
  cin.getline(input, MAX_CHAR);

  cout << input << endl;

}
