#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "Base.h"

class Connector : public Base
{
    protected:
        Base *left;
        Base *right;

    public:
        Connector() : Base(){};
        Connector(Base *l, Base *r) : Base()
        {
          this->left = l;
          this->right = r;
        }
        virtual void execute()=0; 
};

#endif
