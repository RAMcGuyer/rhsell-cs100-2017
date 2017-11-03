#ifndef __BASE_H__
#define __BASE_H__

#include <vector>
#include <string>
using namespace std;
class Base
{
    
    private:
        bool failed; // to check if the execvp function failed or not in execute	
    
    public:
        Base()
        {
            failed = false;
        };
		
        virtual void execute() = 0;
        
        bool getFail()
        {
            return this->failed;
        }
        void setFail(bool didFail)
        {
            this->failed = didFail;
        }	
};

#endif
