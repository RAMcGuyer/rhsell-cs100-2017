#include "rshell.h"
using namespace boost;


int main()
{
  while(true) //infinite loop util user enters "exit" or "Exit"
  {
	  string input;
    vector<string> inputs;
    vector<string> *cmds;
    vector<string> *connectors;
    vector<Base*> actualCmds;
	  cout << "$ ";
	  getline(cin, input);

        //creating a tokenizer and what delimiters the seperate
	  typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	  boost::char_separator<char> sep("", ";&|#()");
	  tokenizer tokens(input, sep);
		
	  //iterating through your tokenizer and putting it into a vector
	  for (tokenizer::iterator tok_iter = tokens.begin();
		 tok_iter != tokens.end(); ++tok_iter)
	  {
		  inputs.push_back(*tok_iter);
	  }

	  for(unsigned i = 0; i < inputs.size(); i++)
    {
       cout << inputs.at(i) << endl;
    }

    connectors = seperateConnectors(inputs);
    cmds = seperateCmds(inputs);
	
	  for(unsigned i = 0; i < cmds->size(); i++)
    {
      cout << cmds->at(i) << endl;
    }

               
    for(unsigned i = 0; i < cmds->size(); i++)
    {
   	  if((cmds->at(i).substr(0,4) == "test") || (cmds->at(i).at(0) == '['))
		  {
			  Test *t = new Test(cmds->at(i));
			  actualCmds.push_back(t);
		  }
		  else
		  {
			  CMD* com = new CMD(cmds->at(i));
 		    actualCmds.push_back(com);
		  }
    }

        Interpreter cmdInterpreter(actualCmds, connectors);
        cmdInterpreter.interpret();

        for(unsigned i = 0; i < actualCmds.size(); i++)
        {
            delete actualCmds.at(i);
        }
        delete cmds;
        delete connectors;
      }	
	return 0;  	
}//end main

