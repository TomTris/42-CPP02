/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:13:31 by qdo               #+#    #+#             */
/*   Updated: 2024/06/01 18:36:57 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()									{ *this = Point(Fixed(0), Fixed(0)); }
Point::Point(Fixed const &x, Fixed const &y)	{ setX(x); setY(y); setb(0);}
Point::Point(Point const & src)
{
	this->setX(src.getX());
	this->setY(src.getY());
	this->setb(src.getb());
}
Point::~Point() {}

Point & Point::operator=(Point const &src)
{
	this->setX(src.getX());
	this->setY(src.getY());
	this->setb(src.getb());
	return (*this);
}

bool Point::operator==(Point const &src) const
{
	if (   this->getX() == src.getX()
		&& this->getY() == src.getY()
		&& this->getb() == src.getb())
		return (true);
	return (false);
}

Fixed Point::getX(void) const { return _x;}
Fixed Point::getY(void) const { return _y;}
Fixed Point::getb(void) const { return _b;}

void Point::setX(Fixed const &x) {_x = x;}
void Point::setY(Fixed const &y) {_y = y;}
void Point::setb(Fixed const &b) {_b = b;}
