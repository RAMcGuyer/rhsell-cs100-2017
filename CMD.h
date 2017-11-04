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
	CMD(string s) : Base() 
	{
		this->createStatement(s);
	};
	
  void createStatement(string s)
  {
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	  boost::char_separator<char> sep(" ");
 	  tokenizer tokens(s, sep);
		
	  //iterating through your tokenizer and putting it into a vector
	  for (tokenizer::iterator tok_iter = tokens.begin();
	  	 tok_iter != tokens.end(); ++tok_iter)
	  {
	  	this->statement.push_back(*tok_iter);
	  }
  }

  void execute() //MAKE SURE TO SET didFail bool when execvp runs 
	{
   pid_t pid;
   int status;
   string temp;
   char* args[80];
   
   cout << statement.at(0) << " " << statement.at(1) << endl;
   for(unsigned i = 0; i < statement.size(); i++)
   {
     statement.at(i).erase(statement.at(i).find_last_not_of(" \n\t\r")+1);
     args[i] = (char*) statement.at(i).c_str();
     cout << i << " "<< args[0] << endl;
   }
   cout << args[0] << " " << args[1] << endl;
   args[statement.size()] = NULL;
   if ((pid = fork()) < 0) //fork failed
   {
     printf("*** ERROR: fork failed\n");
     exit(1);
   }
   else if (pid ==0) //fork to child
   {
     cout << "in child" << endl;
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
