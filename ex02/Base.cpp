/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:24:30 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/14 15:33:10 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Classes.hpp"

Base::~Base( void ) {
	std::cout << "Base destructed." << std::endl;
}

Base *Base::generate( void ) {
	srand((unsigned) time(NULL));
	int random = rand() % 3;

	switch (random) {
		case 0:
			std::cout << "Type A" << std::endl;
			return new A;
		case 1:
			std::cout << "Type B" << std::endl;
			return new B;
		case 2:
			std::cout << "Type C" << std::endl;
			return new C;
		default:
			std::cout << "Error generating." << std::endl;
	}
	return 0;
}

void Base::identify( Base *p ) {
	std::cout << "Identify *: Object is type ";
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

	static int i;
	char classes[] = {'A', 'B', 'C'};

	while (i < 3) {
		void *empty = NULL;
		Base &temp = (Base &)empty;
		try {
			if (i == 0)
				temp = dynamic_cast<A &>(p);
			else if (i == 1)
				temp = dynamic_cast<B &>(p);
			else if (i == 2)
				temp = dynamic_cast<C &>(p);
			else
				std::cout << "Unknown Type." << std::endl;
			(void) temp;
		}
		catch (std::exception &e) {
			i++;
			identify(p);
			return;
		}
		std::cout << "Identify &: Object is type " << classes[i]
				<< std::endl;
		i = 0;
		break ;
	}
}
