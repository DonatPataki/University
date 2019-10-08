#include <fstream>
#include "ProductInventory.h"
#include "ProductFactory.h"
#include "ComputerProductFactory.h"
#include "Display.h"
#include "HardDisk.h"


using namespace std;

void ReadInvFromFileTest(ProductInventory& inv);
void WriteInvTofileTest(ProductInventory& inv);

int main(int argc, char* argv[])
{
	try
	{
		ProductFactory::Init(new ComputerProductFactory());

		cout << "Test1: creating inventory and printing it to the sceen." << endl;
		time_t currentTime;
		time(&currentTime);
		ProductInventory inv1;
		inv1.addProduct(new Display("TFT1", 30000, currentTime, 13, 12));
		inv1.addProduct(new HardDisk("WD", 25000, currentTime, 7500));
		inv1.printProducts(cout);
	}
	catch(...)
	{
		// ;(
	}
}