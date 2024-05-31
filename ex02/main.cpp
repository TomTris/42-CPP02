/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:11:40 by qdo               #+#    #+#             */
/*   Updated: 2024/05/31 17:55:00 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << "\n"<<std::endl;

	Fixed a2 = (Fixed) b;
	Fixed const b2 = (Fixed const) a;
	std::cout << Fixed::max( a, a2 ) << std::endl;
	std::cout << Fixed::min( a, a2 ) << std::endl;
	std::cout << Fixed::max( b, b2 ) << std::endl;
	std::cout << Fixed::min( b, b2 ) << std::endl;

	Fixed c(4.5f);
	Fixed d(0.1f);
	std::cout << "\n"<< c / d << std::endl;
	return 0;
}