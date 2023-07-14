/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:24:33 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/14 14:24:34 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
	public:
		virtual ~Base( void );

		Base *generate( void );
		void identify( Base *p );
		void identify( Base &p );
};

#endif