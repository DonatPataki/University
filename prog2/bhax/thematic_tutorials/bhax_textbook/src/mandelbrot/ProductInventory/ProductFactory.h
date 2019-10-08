#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include <iostream>
#include "Product.h"

class ProductFactory 
{
    static ProductFactory* instance;
public:
    virtual ~ProductFactory()
    {
     
    }
    Product* readAndCreateProduct(std::istream& is);
    virtual Product* createProduct(char typeCode) const = 0;
    static ProductFactory* getInstance();
    static void Init(ProductFactory* pf);
};
#endif /* PRODUCTFACTORY_H */