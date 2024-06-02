/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:11:40 by qdo               #+#    #+#             */
/*   Updated: 2024/06/02 07:24:02 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
bool bsp(Point const& a, Point const& b, Point const& c, Point const& point);

int main( void )
{
	Point const a(Fixed(-2.0f), Fixed(3.0f));
	Point const b(Fixed(2.5f), Fixed(5.0f));
	Point const c(Fixed(4.0f), Fixed(-4.0f));
	Point const point(Fixed(-1.5f), Fixed(3.0f));
	if (bsp(a, b, c, point) == true)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	return (0);
}
