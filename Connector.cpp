#include "Connector.h"

Connector::Connector() : Base()
{
    this->left = NULL;
    this->right = NULL;
}

Connector::Connector(Base* left, Base* right) : Base()
{
    this->left = left;
    this->right = right;
}
