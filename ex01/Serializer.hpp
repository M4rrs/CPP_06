#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

typedef struct Data {
	
	std::string name;
	size_t age;

}	Data;

class Serializer {
	public:
		Serializer( void );
		Serializer( const Serializer &copy );
		Serializer &operator=( const Serializer &assign );
		~Serializer( void );

		uintptr_t serialize( Data *ptr );
		Data *deserialize( uintptr_t raw );
};

#endif