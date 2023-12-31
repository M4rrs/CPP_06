/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:23:52 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/14 14:23:53 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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