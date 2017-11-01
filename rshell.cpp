#include "rshell.h"
#include <boost/tokenizer.hpp>
using namespace boost;

int main()
{
    string input;

    cout << "Enter your command: ";
    getline(cin, input);
 
    tokenizer<> tok(input);

    for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg)
    {
       cout << *beg << "\n";
    }

}
