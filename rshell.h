#ifndef __RSHELL_H__
#define __RSHELL_H__

#include <iostream>
#include <cstring>
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <queue>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include "Base.h"
#include "CMD.h"
#include "Interpreter.h"

using namespace std;

vector<string>* seperateConnectors(vector<string> &inputs)
{
    vector<string> *connectors = new vector<string>;
    for(unsigned ctr = 0; ctr < inputs.size(); ctr++)
    {
        if((inputs.at(ctr)) == ";")
        {
            connectors->push_back(";");
            ctr++;
        }
        if((inputs.at(ctr)) == "&")
        {

            connectors->push_back("&&");
            ctr++;
        }
        else if((inputs.at(ctr)) == "|")
        {
            connectors->push_back("||");
            ctr++;
        }
        else if((inputs.at(ctr) == "#"))
        {
            connectors->push_back("#");
            ctr++;
        }
    }
    return connectors;
}

vector<string>* seperateCmds(vector<string> &inputs)
{
    vector<string> *cmds = new vector<string>;
    for(unsigned ctr = 0; ctr < inputs.size(); ctr++)
    {
        if((inputs.at(ctr)) == ";" || (inputs.at(ctr) == "#"))
        {
            ctr++;
        }
        if((inputs.at(ctr)) == "&")
        {

            ctr++;
        }
        else if((inputs.at(ctr)) == "|")
        {

         ctr++;
        }
        else
        {
            cmds->push_back(inputs.at(ctr));
        }
    }
    return cmds;
}


#endif
