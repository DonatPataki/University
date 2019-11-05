#include <iostream>
#include <fstream>
#include <map>
#include <vector>

int main(int argc, char* argv[])
{
	std::map<char, int> numOfChars;
	std::pair<std::map<char, int>::iterator, bool> check;
	std::ifstream text;
	text.open("uncrypted");
	std::string line;
	while (std::getline(text, line))
	{
		for (int i = 0; i < line.length(); i++)
		{	
			check = numOfChars.insert(std::pair<char,int>(line[i], 1));
			if (check.second == false)
			{
				check.first->second++;
			}
		}
	}
	text.close();

	std::map<int, int> encrypted;
	std::pair<std::map<int, int>::iterator, bool> check2;
	text.open("encrypted");
	std::vector<int> asd;
	while (std::getline(text, line))
	{
		check2 = encrypted.insert(std::pair<int,int>(std::stoi(line), 1));
		if (check2.second == false)
		{
			check2.first->second++;
		}
		asd.push_back(std::stoi(line));
	}
	text.close();

	std::map<int, char> reverse;
	std::map<char, int>::iterator itr;
	for (itr = numOfChars.begin(); itr != numOfChars.end(); itr++)
	{
		reverse.insert(std::pair<int, char>(itr->second, itr->first));
	}	

	std::ofstream output;
	output.open("decrypted");
	for (std::vector<int>::iterator it = asd.begin(); it != asd.end(); it++)
	{
		output << reverse[encrypted[*it]];
	}
	output.close();

	for (itr = numOfChars.begin(); itr != numOfChars.end(); itr++)
	{
		std::cout << itr->first << '\t' << itr->second << '\n';
	}

	std::map<int, int>::iterator itr2;
	for (itr2 = encrypted.begin(); itr2 != encrypted.end(); itr2++)
	{
		std::cout << itr2->first << '\t' << itr2->second << '\n';
	}

	return 0;
}