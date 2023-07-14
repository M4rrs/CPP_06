/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:24:26 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/14 14:24:27 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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