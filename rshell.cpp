#include "rshell.h"
#include <boost/tokenizer.hpp>
using namespace boost;

int main()
{
    string input;

    cout << "Enter your command: ";
    getline(cin, input);

    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep("&&", "||", boost::keep_empty_tokens);
    tokenizer tokens(input, sep);

    for (tokenizer::iterator tok_iter = tokens.begin();
         tok_iter != tokens.end(); ++tok_iter)
    {
        cout << *tok_iter;
        cout << "\n";
    }

}
