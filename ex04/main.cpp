
#include "Replace.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	Replace replace(argv[1], argv[2], argv[3]);
	replace.process();
	return (0);
}