#ifndef __CMDS_H__
#define __CMDS_H__

class CMDS : public Base
{
        private:
            vector<Base> commands;

        public:
            CMDS(queue &q) : Base()
            {
                fillCommands(q)
            }

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
            
            void execute()
            {
                for(int i = 0; i < commands.size(); i++
                {
                    commands[i] -> execute();
                }
            }

            
};

#endif

