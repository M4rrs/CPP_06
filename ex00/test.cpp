#include <iostream>
#include <limits>

int main( void ) {
	int i = 130;

	char c = static_cast<unsigned char>(i);

	std::cout << c << std::endl;
}