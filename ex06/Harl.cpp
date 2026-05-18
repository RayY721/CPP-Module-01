#include "Harl.hpp"
#include <iostream>

void Harl::debug( void )
{
	std::cout << "[ DEBUG ] " << std::endl;
	std::cout << "This is a debug message." << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ] " << std::endl;
	std::cout << "This is an info message." << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ] " << std::endl;
	std::cout << "This is a warning message." << std::endl;	
}

void Harl::error( void )
{
	std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is an error message." << std::endl;
}

void Harl::complain( std::string level )
{
	// new implementation
	int levelIndex = -1;
	
	if (level == "DEBUG")
		levelIndex = 0;
	else if (level == "INFO")
		levelIndex = 1;
	else if (level == "WARNING")
		levelIndex = 2;
	else if (level == "ERROR")
		levelIndex = 3;
	
	switch (levelIndex)
	{
		case 0:
			debug();
			std::cout << std::endl;
			// fall through
		case 1:
			info();
			std::cout << std::endl;
			// fall through
		case 2:
			warning();
			std::cout << std::endl;
			// fall through
		case 3:
			error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}

/*

	// // void (Harl::*ptr[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	// typedef void (Harl::*funcPtr)( void );
	// funcPtr ptr[4] = {
	// 	&Harl::debug,
	// 	&Harl::info,
	// 	&Harl::warning,
	// 	&Harl::error
	// };
	// std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// for (int i = 0; i < 4; i++)
	// {
	// 	if (level == levels[i])
	// 	{
	// 		for (int j = i; j < 4; j++)
	// 		{
	// 			(this->*ptr[j])();
	// 			std::cout << std::endl;
	// 		}
	// 		return ;
	// 	}
	// }
	// std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;


*/