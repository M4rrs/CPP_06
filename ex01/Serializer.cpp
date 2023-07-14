/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:24:23 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/14 14:24:24 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {
	std::cout << "Serializer constructed." << std::endl;
}

Serializer::~Serializer( void ) {
	std::cout << "Serializer destructed." << std::endl;
}

Serializer::Serializer( const Serializer &copy ) {
	*this = copy;
	std::cout << "Serializer cloned." << std::endl;
}

Serializer &Serializer::operator=( const Serializer &assign ) {
	// return (this == &assign ? *this : *this);
	(void) assign;
	return *this;
}

/*=============================================================*/

uintptr_t Serializer::serialize( Data *ptr ) {
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize( uintptr_t raw ) {
	Data *recast = new Data;

	recast = reinterpret_cast<Data *>(raw);
	return (recast);
}