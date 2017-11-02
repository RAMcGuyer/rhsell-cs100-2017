#include "Or.h"

Or::Or() : Connector() {}

Or::Or(Base *left, Base *right) : Connector(left, right) {}

void Or::execute()
{
    left -> execute();

    if(left->getFail() == true) //run second command if first fails
    {
        right -> execute();
    }
}
