#include "And.h"

And::And() : Connector() {}

And::And(Base *left, Base *right) : Connector(left, right) {}

void And::execute()
{
    left->execute();

    if (left->getFail() == false)
    {
        right->execute();
    }
}
