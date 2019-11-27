#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<utility>

struct nodeData {
	std::string ID;
	std::string lat;
	std::string lon;
};

std::string extract(const std::string& input, const std::string& search)
{
	std::string output;
	std::size_t from = input.find(search) + search.length() - 1;
	while (input[++from] != '"')
	{
		output += input[from];
	}
	return output;
}

void getPointIndex(const std::string& ref, const std::vector<nodeData> search, std::string& outputLat, std::string& outputLon)
{
	unsigned int i = 0;
	for (; i < search.size(); i++)
	{
		if (ref == search[i].ID)
		{
			break;
		}
	}
	if (i < search.size())
	{
		outputLat = search[i].lat;
		outputLon = search[i].lon;
	}
	else
	{
		outputLat = "NOT FOUND";
		outputLon = "NOT FOUND";
	}
}

int main()
{
	std::ifstream raw("src\\Debrecen.osm");
	std::vector<nodeData> points;
	std::vector<std::vector<std::string>> references;
	std::vector<std::string> tempv;
	std::string line;
	while (getline(raw, line))
	{
		if (line.find("node id") != std::string::npos)
		{
			points.push_back({ extract(line, "\""), extract(line, "lat=\""), extract(line, "lon=\"") });
		}
		else if (line.find("nd ref") != std::string::npos)
		{
			tempv.push_back(extract(line, "nd ref=\""));
		}
		else if (!(tempv.empty()))
		{
			references.push_back(tempv);
			tempv.clear();
		}
	}
	raw.close();

	/*
	std::cout << points.size() << std::endl;
	for (unsigned int i = 0; i < points.size(); i++)
	{
		std::cout << points[i].ID << " " << points[i].lan << " " << points[i].lon << std::endl;
	}
	for (unsigned int i = 0; i < references.size(); i++)
	{
		for (unsigned int j = 0; j < references[i].size(); j++)
		{
			std::cout << references[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/
	std::ofstream coordinates;
	coordinates.open("cord.dat");
	std::string lat, lon;
	for (unsigned int i = 0; i < references.size(); i++)
	{
		for (unsigned int j = 0; j < references[i].size(); j++)
		{
			getPointIndex(references[i][j], points, lat, lon);
			coordinates << lat << " " << lon << std::endl;
		}
		coordinates << "\n";
	}
	coordinates.close();
}
