#include "rshell.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <queue>
using namespace boost;

int main()
{
    string input;
    vector<string> inputs;
    queue<string> cmds;

    cout << "Enter your command: ";
    getline(cin, input);

    //creating a tokenizer and what delimiters the seperate
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep("", "&|;", boost::drop_empty_tokens);
    tokenizer tokens(input, sep);

    //iterating through your tokenizer and putting it into a vector
    for (tokenizer::iterator tok_iter = tokens.begin();
         tok_iter != tokens.end(); ++tok_iter)
    {
        inputs.push_back(*tok_iter);
    }
    
    //iterating through vector and pushing into a queue
    for(int i = 0; i < inputs.size(); i++)
    {
        trim(inputs[i]);
        cmds.push(inputs[i]);
        cout << "Index [" << i << "]: " << inputs[i] << endl;
    }

}
