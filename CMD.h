#ifndef __CMD_H__
#define __CMD_H__

#include <iostream>
#include "Base.h"

class CMD : public Base
{
	private:
		vector<string>* statement;
	public:
	
	CMD() : Base() {};
	CMD(vector<string> *prompt) : Base() 
	{
		statement = prompt;
	};
	

	/*void execute() //MAKE SURE TO SET didFail bool when execvp runs 
	{
             pid_t pid;
             int status;

             if ((pid = fork()) < 0) //fork failed
             {
                 printf("*** ERROR: exec failed\n");
                 exit(1);
             }
             else if (pid ==0) //fork to child
             {
                 if (execvp(statement->at(0).c_str(), statement->c_str) < 0) //if execvp failed
                 {
                    this->setFail(true); 
                 } 
             }
             else
             {
                 while (wait(&status) != pid);
             }
	}*/
	bool getFail()
	{
		return Base::getFail();
	}
};

#endif
