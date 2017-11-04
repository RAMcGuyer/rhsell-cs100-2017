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
	cout << "$ ";
	getline(cin, input);

	CMD *com1 = new CMD("ls -a");
  CMD *com2 = new CMD("git status");
  And and1(com1, com2);
  and1.execute();
  
	return 0;  
	
}

