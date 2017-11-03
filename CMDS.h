#ifndef __CMDS_H__
#define __CMDS_H__

#include "CMD.h"

class CMDS : public Base
{
        private:
            vector<Base*> commands;
            
            vector<string> makeNewCMD(int ctr, vector<string> &input)
            {
              vector<string> vec;
              vector<string>::iterator it; 
              for(int i = 0; i < ctr; i++)
              {
                it = vec.begin();
                if(input.at(0) != ";")
                {
                  vec.push_back(input.at(0));
                }
                input.erase(it);
              }
              
              return vec;
            }

        public:
            CMDS(vector<string> &input) : Base()
            {
                fillCommands(input);
            }
            
            void add(Base *b)
            {
              this->commands.push_back(b);
            }
            
            void fillCommands(vector<string> &input)
            {
              int ctr = 0;
              vector<string> tempVec;
              while(ctr < input.size())
              {
                if((input.at(ctr) == ";") || (ctr == input.size()-1))
                {
                  tempVec = this->makeNewCMD(ctr, input);
                  CMD tempCMD(tempVec); 
                  this->add(tempCMD);
                }
              }  
            }
/*
            void fillCommands(vector<string> *v)
            {
                vector<string> *parsedStr;
                vector<string> *parsedStr2;                

                for(int i = 0; i < v->size(); i++)
                {
                    if(v->at(i) != ";" && v->at(i) != "&&" && v->at(i) != "||" && v->at(i) != "exit")
                    {
                        parsedStr->push_back(v->at(i));
                    }
                    else if(v->at(i) == ";")
                    {
                        CMD newCmd(parsedStr);
                        commands.push_back(newCmd);
                        parsedStr->clear();
                    }
                    else if(v->at(i) == "&&")
                    {
                         CMD newCmd(parsedStr);
     for(int j = i; j < v->size(); j++) //run through the vector to get the command to the right
                         {
     if(v->at(j) != ";" && v->at(j) != "&&" && v->at(j) != "||" && v->at(j) != "exit")
                             {
                                 parsedStr2->push_back(v->at(j));
                             }
                             else
                             {
                                 CMD newCmd2(parsedStr2);
                                 And newAnd(parsedStr, parsedStr2);
                                 commands.push_back(newAnd);
                                 parsedStr->clear();
                                 parsedStr2->clear();
                             }    
                         }
                    }
 
                }

            }
       */     
            void execute()
            {
                for(int i = 0; i < commands.size(); i++)
                {
                    commands[i] -> execute();
                }
            }

            
};

#endif

