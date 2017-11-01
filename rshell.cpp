#include "rshell.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/trim.hpp>
using namespace boost;

int main()
{
    string input;
    vector<string> inputs;

    cout << "Enter your command: ";
    getline(cin, input);

    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep("&&||;");
    tokenizer tokens(input, sep);

    for (tokenizer::iterator tok_iter = tokens.begin();
         tok_iter != tokens.end(); ++tok_iter)
    {
        inputs.push_back(*tok_iter);
    }

    for(int i = 0; i < inputs.size(); i++)
    {
        trim(inputs[i]);
        cout << "Index [" << i << "]: " << inputs[i] << endl;
    }

}
