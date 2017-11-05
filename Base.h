#ifndef __BASE_H__
#define __BASE_H__

#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/trim.hpp>
using namespace std;
class Base
{
    
    private:
        bool failed; // to check if the execvp function failed or not in execute
        bool didRun;	
    
    public:
        Base()
        {
            failed = false;
            didRun = false;
        };
        virtual ~Base() {};
		
        virtual void execute() = 0;
        
        bool getFail()
        {
            return this->failed;
        }
        void setFail(bool didFail)
        {
            this->failed = didFail;
        }
        bool getDidRun()
        {
            return this->didRun;
        }
        void setDidRun(bool didRun)
        {
            this->didRun = didRun;
        }	
};

#endif
