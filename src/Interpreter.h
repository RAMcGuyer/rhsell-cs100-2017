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
        vector<Base*> executables;
        vector<string>* connectors;

    public:
        Interpreter(vector<Base*> exe, vector<string>* conn)
        {
          this->executables = exe;
          this->connectors = conn;
        }
        ~Interpreter() {}

        

  void interpret()
  {

    if(connectors->empty())
    {
        executables.front()->execute();
    }
    else
    {
        unsigned i = 0;
        while (i < connectors->size())
        {
            if(!(executables.at(i)->getDidRun())) //check if cmd already ran
            {
                executables.at(i)->execute();
            }
            if(connectors->at(i) == "&&") //check and logic
            {
             // cout << "getFail@&&: " << executables.at(i)->getFail() << endl;
		          if(executables.at(i)->getFail() == false)
              {
                executables.at(i+1)->execute();
              }
              else
              {
                executables.at(i+1)->setDidRun(true);
                executables.at(i+1)->setFail(true);
              }
            }
            else if(connectors->at(i) == "||") // check or logic
            {
              //cout << "getFail@||: " << executables.at(i)->getFail() << endl;
		          if(executables.at(i)->getFail() == true)
              {
                executables.at(i+1)->execute();
              }               
              else
              {
                executables.at(i+1)->setDidRun(true);
                executables.at(i+1)->setFail(true);
              }
            }
            else if(connectors->at(i) == "#") //check comments
            {
                break;
            }
            i++;
        } 
        if(!(executables.at(i)->getDidRun()) && connectors->at(i-1) != "#")
        {
          executables.at(i)->execute();
        }
    }
   }

};

#endif
