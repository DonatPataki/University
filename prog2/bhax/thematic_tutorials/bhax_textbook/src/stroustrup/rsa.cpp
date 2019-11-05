#include <iostream>
#include <fstream>
#include <cmath>

int p1 = 53, p2 = 59;
int n = p1 * p2;
int pin = (--p1) * (--p2);
int e = 3;
int d = (2 * pin + 1) / e;

void encrypt(const std::string& message)
{
	std::ofstream output;
	output.open("encrypted", std::ios::app);
	for (int i = 0; i < message.length(); i++)
	{
		output << (int)pow((double)message[i], e) % n;
		output << "\n";
	}
	output.close();
}

int main(int argc, char* argv[])
{
	std::ifstream text;
	text.open(argv[1]);
	std::string line;
	while (std::getline(text, line))
	{
		encrypt(line);	
	}
	text.close();

	return 0;
}