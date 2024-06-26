/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:58:20 by qdo               #+#    #+#             */
/*   Updated: 2024/06/02 18:29:31 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed _x;
	Fixed _y;

public:

	Point();
	Point(Fixed const &x, Fixed const &y);
	Point(Point const & src);
	~Point();
	Point & operator=(Point const & src);

	void  setX(Fixed const &x);
	void  setY(Fixed const &y);

	Fixed getX(void) const;
	Fixed getY(void) const;
	bool operator==(Point const &src) const;
};

#endif
