#include "rshell.h"
#include "CmdQueues.h"
using namespace boost;

queue<string>* seperateCmds(vector<string> &inputs)
{
    queue<string> *cmds = new queue<string>;
    for(unsigned ctr = 0; ctr < inputs.size(); ctr++)
    {    
        if((inputs.at(ctr)) == ";")
        {
            ctr++;
        }
        if((inputs.at(ctr)) == "&")
        {

            ctr++;    
        }
        else if((inputs.at(ctr)) == "|")
        {
   
         ctr++;   
        }
        else
        {
            cmds->push(inputs.at(ctr));
        }
    }
    return cmds;
}

queue<string>* seperateConnectors(vector<string> &inputs)
{
    queue<string> *connectors = new queue<string>;
    for(unsigned ctr = 0; ctr < inputs.size(); ctr++)
    {
        if((inputs.at(ctr)) == ";")
        {
            connectors->push(";");
            ctr++;
        }
        if((inputs.at(ctr)) == "&")
        {

            connectors->push("&&");
            ctr++;
        }
        else if((inputs.at(ctr)) == "|")
        {
            connectors->push("||");
            ctr++;
        }
    }
    return connectors;
}



int main()
{
	string input, joined;
        vector<string> inputs;
        queue<string> *cmds;
        queue<string> *connectors;
	cout << "$ ";
	getline(cin, input);

		//creating a tokenizer and what delimiters the seperate
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep("", ";&|");
	tokenizer tokens(input, sep);
		
	//iterating through your tokenizer and putting it into a vector
	for (tokenizer::iterator tok_iter = tokens.begin();
		 tok_iter != tokens.end(); ++tok_iter)
	{
		inputs.push_back(*tok_iter);
	}

        connectors = seperateConnectors(inputs);
        cmds = seperateCmds(inputs);

        while(!(cmds->empty()))
        {
            cout << "In cmd queue: " << cmds->front() << endl;
            cmds->pop();
        }
        cout << endl;

        while(!(connectors->empty()))
        {
            cout << "In connector queue: " << connectors->front() << endl;
            connectors->pop();
        }
  	
	return 0;  
	
}

