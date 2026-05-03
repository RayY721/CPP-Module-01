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
	// void (Harl::*ptr[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	typedef void (Harl::*funcPtr)( void );
	funcPtr ptr[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*ptr[i])();
			return ;
		}
	}

	std::cout << "Invalid level" << std::endl;
}