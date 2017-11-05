#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include "rshell.h"
#include <vector>
#include <iostream>
#include "Base.h"
#include "CMD.h"

using namespace std;

class Interpreter
{

    private:
        vector<CMD> executables;
        vector<string>* connectors;

    public:
        Interpreter(vector<CMD> &exe, vector<string>* conn)
        {
          this->executables = exe;
          this->connectors = conn;
        }

        

  void interpret()
  {

    for(unsigned i = 0; i < connectors->size(); i++)
    {
        if(!(executables.at(i).getDidRun())) //check if cmd already ran
        {
            executables.at(i).execute();
        }
        if(connectors->at(i) == "&&") //check and logic
        {
            if(executables.at(i).getFail() == false)
            {
                executables.at(i+1).execute();
            }
        }
        else if(connectors->at(i) == "||") // check or logic
        {
            if(executables.at(i).getFail() == true)
            {
                executables.at(i+1).execute();
            }
        }
        else if(connectors->at(i) == "#") //check comments
        {
            break;
        }
    }
   }

};

#endif
