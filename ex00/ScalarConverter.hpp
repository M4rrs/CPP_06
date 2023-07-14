/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:24:06 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/14 14:24:08 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <climits>

enum types {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NAN_INF,
	ERROR
};

class ScalarConverter {
	private:
		const std::string _literal;
		int _dataType;
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

		int setInputType( const std::string lit );
		void convert( void );
		void typeC( void );
		void typeI( void );
		void typeF( void );
		void typeD( void );
		void printResults( void ) const;

		class Exception : std::exception {
			public:
				virtual const char* what() const throw();
		};
};
#endif