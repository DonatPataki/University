#include<iostream>
#include<vector>
#include<fstream>

struct charLeetPair
{
	char chr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	std::string chrLeet[26] = {"4", "8", "<", "|)", "3", "|=", "[", "4", "1", "_|", "|<", "|_", "44", "|\\|", "0", "|o", "O_", "|2", "5", "7", "|_|", "\\/", " \\/\\/", "%", "`/", "2"};
} leet;

int main(int argc, char *argv[])
{
	std::string arg = argv[1];
	std::vector<std::string> args;
	switch(arg[0])
	{
		case '-' :
		{
			if(arg == "--help")
			{
				std::cout << "./a.out [string|-i input file]\n";
				break;
			}
			if(arg == "-i")
			{
				arg = argv[2];
				std::string line;
				int lines =0;
				std::ifstream myfile (arg);
				if (myfile.is_open())
				{
				    while ( getline (myfile,line) )
				    {
				    	args.push_back(line);
				    	lines++;
				    }
				    myfile.close();
				}
				for (int i = 0; i < lines; ++i)
				{
					for (int x = 0; x < args[i].length(); x++)
					{
						for (int y = 0; y < 26; y++)
						{
							if(tolower(args[i][x]) == leet.chr[y])
								args[i].replace(x, 1, leet.chrLeet[y]);
						}
					}
					std::cout << args[i] << std::endl;
				}
			}

		}
		break;
		default:
		{
			for (int i = 1; i < argc; i++)
			{
				args.push_back(argv[i]);
				for (int x = 0; x < args[i-1].length(); x++)
				{
					for (int y = 0; y < 26; y++)
					{
						if(tolower(args[i-1][x]) == leet.chr[y])
						args[i-1].replace(x, 1, leet.chrLeet[y]);
					}
				}
				std::cout << args[i-1] << " ";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}