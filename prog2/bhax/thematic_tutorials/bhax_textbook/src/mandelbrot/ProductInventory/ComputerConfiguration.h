#ifndef COMPUTERCONFIGURATION_H
#define COMPUTERCONFIGURATION_H

#include <iostream>
#include "CompositeProduct.h"

class ComputerConfiguration : public CompositeProduct {
public:
    ComputerConfiguration() : CompositeProduct()
    {

    }
    virtual ~ComputerConfiguration()
    {

    }
    std::string getType() const
    {
    	return "ComputerConfiguration";
    }
    char getCharCode() const
    {
    	return charCode;
    }
    static const char charCode = 'c';
};
#endif /* COMPUTERCONFIGURATION_H */