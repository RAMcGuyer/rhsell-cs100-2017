#ifndef __AND_H__
#define __AND_H__

#include "Connector.h"

class And : public Connector
{
            
    public:
         And(): Connector() {};
         And(Base *left, Base *right): Connector(left, right){};
         void execute();
};

#endif
