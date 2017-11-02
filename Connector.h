#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "Base.h"

class Connector : public Base
{
    private:
        Base *left;
        Base *right;

    public:
        Connector();
        Connector(Base *left, Base *right);
        virtual void exec()=0;
};

#endif
