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
        ~CMD() {};
	
 /* CREATESTATEMENT
   Takes the string passsed into the constructor and creates a vector<string> for 
   later use in the execute function.
 */
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
  
  /* VOID EXECUTE()
    Creates an array of char* from the vector<string> statement. The program then
    forks, and execvp() is called in the child using the array of char* as arguments.
    If the child process execvp() fails, status equals -1 and a boolean is set to true
    to indicate the failure. 
  */
  void execute() 
  {
       pid_t pid;
       int status;
       string temp;
       char* args[80];

       if(statement.size() == 1 && (statement.at(0) == "exit" || statement.at(0) == "Exit"))
       {
          cout << "exiting program" << endl;
          exit(0);
       }
   
       for(unsigned i = 0; i < statement.size(); i++)
       {
           statement.at(i).erase(statement.at(i).find_last_not_of(" \n\t\r")+1);
           args[i] = (char*) statement.at(i).c_str();
       }
       args[statement.size()] = NULL;
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
		exit(1);
           } 
       } 
       else
       {
           while (wait(&status) != pid);

           this->setDidRun(true);

           if(WEXITSTATUS(status) != 0)
           {
               this->Base::setFail(true);
           }
       }

   }
	
  bool getFail()
  {
      return Base::getFail();
  }
  
  bool getDidRun()
  {
      return Base::getDidRun();
  }

  void setDidRun(bool didRun)
  {
      return Base::setDidRun(didRun);
  }
 
};

#endif
