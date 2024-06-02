/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:11:40 by qdo               #+#    #+#             */
/*   Updated: 2024/06/02 19:49:24 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
bool bsp(Point const& a, Point const& b, Point const& c, Point const& point);

int main( void )
{
	Point const a(Fixed(-9.86f), Fixed(-1.57f));
	Point const b(Fixed(-1.3f), Fixed(3.01f));
	Point const c(Fixed(9.6f), Fixed(5.17f));
	Point const point(Fixed(7.0f), Fixed(4.5f));
	if (bsp(a, b, c, point) == true)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	return (0);
}
