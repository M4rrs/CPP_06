/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:24:41 by nnorazma          #+#    #+#             */
/*   Updated: 2023/07/14 14:24:42 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <unistd.h>

int main( void ){
	Base test1;

	for (int i = 0; i < 5; i++) {
		Base *temp = test1.generate();
		test1.identify(temp);
		delete temp;
		std::cout << std::endl;
		sleep(2);
	}
}

/*rand() on its own is pretty unreliable, not exactly "random"
using time() does make it a bit more random but running it in a loop
would somewhat give them all the same result, because program run fast, time run
not so fast. I just used sleep to slow down processing so the results do show
a little more randomly.*/