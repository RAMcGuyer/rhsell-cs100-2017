/*#include "Interpreter.h"

Interpreter::Interpreter(vector<CMD> &executables, vector<string>* connectors)
{
    this->executables = executables;
    this->connectors = connectors;
}

void Interpreter::interpret()
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
}*/
