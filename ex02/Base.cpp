#include "Base.hpp"

Base::~Base( void ) {
	std::cout << "Base destructed." << std::endl;
}

Base *Base::generate( void ) {
	srand((unsigned) time(NULL));
	int random = rand() % 3;

	switch (random) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			std::cout << "Error generating." << std::endl;
	}
	return 0;
}

void Base::identify( Base *p ) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

/*I'm trusting this on the basis that there will never
be an occurence in which it is not 0 - 2 (A, B or C)*/
void Base::identify( Base &p ) {

}
