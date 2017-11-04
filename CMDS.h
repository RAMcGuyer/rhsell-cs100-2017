#ifndef __CMDS_H__
#define __CMDS_H__

#include "CMD.h"
/*
class CMDS : public Base
{
        private:
            vector<Base*> commands;
            
<<<<<<< Updated upstream
            vector<string> makeNewCMD(unsigned ctr, vector<string> &input)
=======
            //helper function
            vector<string> makeNewCMD(int ctr, vector<string> &input)
>>>>>>> Stashed changes
            {
              vector<string> vec;
              vector<string>::iterator it; 
              for(unsigned i = 0; i < ctr; i++)
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
              unsigned ctr = 0;
              vector<string> tempVec;
              while(ctr < input.size())
              {
                if((input.at(ctr) == ";") || (ctr == input.size()-1))
                {
                  tempVec = this->makeNewCMD(ctr, input);
                  CMD *tempCMD = new CMD(tempVec); 
                  this->add(tempCMD);
                }
<<<<<<< Updated upstream
              }  
            }

            void fillCommands(vector<string> *v)
            {
                vector<string> *parsedStr;
                vector<string> *parsedStr2;                

                for(int i = 0; i < v->size(); i++)
=======
                else if((input.at(ctr) == "&&"))
>>>>>>> Stashed changes
                {
                    tempVec = this->makeNewCMD(ctr, input); //create new cmd for left side of connector
                    CMD tempCMD(tempVec);
                    
                    int newCtr = ctr;
                    vector<string> secTempVec;

                    while(newCtr < input.size()) //iterate through 
                    {
                        if((input.at(newCtr) == ";" || input.at(newCtr) == "&&" || input.at(newCtr) == "||"))
                        {
                            
                        }
                    }
                }
                
                
              }  
            }
            
            void execute()
<<<<<<< Updated upstream
            {
                for(unsigned i = 0; i < commands.size(); i++)
=======
            {                for(int i = 0; i < commands.size(); i++)
>>>>>>> Stashed changes
                {
                    commands[i] -> execute();
                }
            }

            
};
*/
#endif

