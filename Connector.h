#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "Base.h"

class Connector : public Base
{
    protected:
        Base *left;
        Base *right;

    public:
        Connector();
        Connector(Base *left, Base *right);
        virtual void execute()=0; 
};

#endif
