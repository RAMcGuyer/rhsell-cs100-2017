#include "rshell.h"

using namespace boost;

void execute()
{
	string ls = "ls";
	string semi = "-a";
	
	char* args[3];
	args[0] = (char*) ls.c_str();
	args[1] = (char*) semi.c_str();
	args[2] = NULL;
	
	if(execvp(args[0], args))
	{
		perror("exec");
	}
}
int main()
{
	string input;
	vector<string> inputs;
	cout << "Enter your command: ";
	getline(cin, input);

		//creating a tokenizer and what delimiters the seperate
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep(" ", ";");
	tokenizer tokens(input, sep);
		
	//iterating through your tokenizer and putting it into a vector
	for (tokenizer::iterator tok_iter = tokens.begin();
		 tok_iter != tokens.end(); ++tok_iter)
	{
		inputs.push_back(*tok_iter);
	}
	
  CMDS coms(inputs);
  coms.execute();
  	
	return 0;  
	
}

