//g++ filelisting.cpp -lboost_system -lboost_filesystem
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
    	std::cout << "Usage: ./a.out [path] [extension]\n";
    	return 1;
    }

    boost::filesystem::path p = argv[1];
    std::string ext = argv[2];
    if(ext[0] != '.')
    	ext.insert(0, ".");

    if(is_directory(p)) {
        std::cout << "Searching for " << ext << " extension in " << p << std::endl;

        for(auto& file : boost::make_iterator_range(boost::filesystem::recursive_directory_iterator(p), {}))
            if (boost::filesystem::extension(file) == ext)
            	std::cout << file << "\n";
    }

    return 0;
}
