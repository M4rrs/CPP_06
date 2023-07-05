#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		const std::string _literal;
		char _char;
		int _int;
		float _float;
		double _double;
		ScalarConverter( void );

	public:
		ScalarConverter( std::string lit );
		ScalarConverter( const ScalarConverter &copy );
		ScalarConverter &operator=( const ScalarConverter &assign );
		~ScalarConverter( void );

		void convertInput( std::string str );
		void printResults( void ) const;

		char getChar( void ) const;
		int getInt( void ) const;
		float getFloat( void ) const;
		double getDouble( void ) const;
};
#endif