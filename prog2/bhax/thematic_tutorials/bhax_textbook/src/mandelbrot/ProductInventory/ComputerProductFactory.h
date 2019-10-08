#ifndef COMPUTERPRODUCTFACTORY_H
#define COMPUTERPRODUCTFACTORY_H

#include "ProductFactory.h"

class ComputerProductFactory : public ProductFactory
{
public:
    Product* createProduct(char typeCode) const;
};
#endif /* COMPUTERPRODUCTFACTORY_H */