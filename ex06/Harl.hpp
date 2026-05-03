#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

// A better way to declare the function. 
// void complain( const std::string& level );
class Harl
{
    public:
		void complain( std::string level );

    private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif