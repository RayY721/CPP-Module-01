#include "Replace.hpp"
#include <iostream>
#include <fstream>
#include <string>

Replace::Replace(const std::string& filename, 
				const std::string& s1, 
				const std::string& s2)
			: _filename(filename), _s1(s1), _s2(s2)
{

}

void Replace::process( void )
{
	if (this->_s1.empty())
	{
		std::cout << "s1 is empty, nothing to replace." << std::endl;
		return ;
	}
	std::ifstream inFile(this->_filename.c_str());
	if (!inFile.is_open())
	{
		std::cout << "Error: Could not open input file " << this->_filename << std::endl;
		return ;
	}

	std::ofstream outFile((this->_filename + ".replace").c_str());
	if (!inFile.is_open())
	{
		std::cout << "Error: Could not open output file " << this->_filename << std::endl;
		return ;
	}

	std::string line;
	while (getline(inFile, line))
	{
		std::string result;
		size_t pos = 0;
		size_t found;

		while ((found = line.find(this->_s1, pos)) != std::string::npos)
		{
			result += line.substr(pos, found - pos);
			result += this->_s2;
			pos = found + this->_s1.length();
		}
		result += line.substr(pos);
		outFile << result;
		if (!inFile.eof())
			outFile << std::endl;
	}
}
