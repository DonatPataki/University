#include "ComputerProductFactory.h"
#include "Display.h"
#include "HardDisk.h"
#include "ComputerConfiguration.h"

Product* ComputerProductFactory::createProduct(char typeCode) const 
{
    switch(typeCode) 
    {
    case 'd':
        return new Display();
    case 'h':
        return new HardDisk();
    case 'c':
        return new ComputerConfiguration();
    }

    return NULL;
}