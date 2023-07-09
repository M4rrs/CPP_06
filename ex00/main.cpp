#include "ScalarConverter.hpp"

int main( int ac, char **av ) {
	if (ac == 2) {
		try {
			ScalarConverter convert(av[1]);
		}
		catch (ScalarConverter::Exception &e) {
			std::cout << e.what() << std::endl;
		}
		return (0);
	}
	std::cout << "Only 1 argument." << std::endl;
}