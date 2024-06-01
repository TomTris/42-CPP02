/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:11:40 by qdo               #+#    #+#             */
/*   Updated: 2024/06/01 17:17:27 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point const a(Fixed(0), Fixed(0));
	Point const b(Fixed(1), Fixed(0.1f));
	Point const c(Fixed(0.1f), Fixed(1));
	Point const point(Fixed(0.5f), Fixed(0.2f));
	if (bsp(a, b, c, point) == true)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	return (0);
}
