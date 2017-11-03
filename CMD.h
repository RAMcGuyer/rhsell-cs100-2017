#ifndef __CMD_H__
#define __CMD_H__

#include <iostream>
#include "Base.h"

class CMD : public Base
{
	private:
		vector<string> statement;
	public:
	
	CMD() : Base() {};
	CMD(vector<string> &prompt) : Base() 
	{
		statement = prompt;
	};
	

  void execute() //MAKE SURE TO SET didFail bool when execvp runs 
	{
   pid_t pid;
   int status;
   string temp;
   char* args[this->statement.size()+1];
   int i = 0;
   
   for(i; i < this->statement.size(); i++)
   {
     temp = this->statement.at(i);
     args[i] = (char*) temp.c_str();
   }
   
   args[i+1] = NULL;

   if ((pid = fork()) < 0) //fork failed
   {
     printf("*** ERROR: fork failed\n");
     exit(1);
   }
   else if (pid ==0) //fork to child
   {
     if (execvp(args[0], args) == -1) //if execvp failed
     {
        perror("exec");
        Base::setFail(true); 
     } 
   } 
   else
   {
      while (wait(&status) != pid);
   }
}
	
    bool getFail()
	{
		return Base::getFail();
	}
};

#endif
