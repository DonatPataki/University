#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main()
{
	std::string line;
	std::ifstream file;
	std::vector<int> indexes;
	indexes.push_back(0);
	file.open("coord.txt");
	int i = 0;
	std::ofstream output;
	output.open("vertecies.txt");
	while (std::getline(file, line))
	{
		i++;
		if (line == "")
		{
			indexes.push_back(--i);
			indexes.push_back(i + 1);
			continue;
		}
		output << line << std::endl;
	}
	file.close();
	std::ofstream output2;
	output2.open("indexes.txt");
	for (int j = 0; j < indexes.size(); j++)
	{
		output2 << indexes[j] << std::endl;
	}
	output2.close();

}