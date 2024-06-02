/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:24:00 by qdo               #+#    #+#             */
/*   Updated: 2024/06/02 19:45:19 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Line.hpp"

Line::Line() {}
Line::Line(Fixed const &a, Fixed const &b, Fixed const &c)	{ seta(a); setc(c); setb(b);}
Line::Line(Line const & src)
{
	this->seta(src.geta());
	this->setb(src.getb());
	this->setc(src.getc());
}
Line::~Line() {}

Line & Line::operator=(Line const &src)
{
	this->seta(src.geta());
	this->setb(src.getb());
	this->setc(src.getc());
	return (*this);
}

// bool Line::operator==(Line const &src) const
// {
// 	if (   this->geta() == src.geta()
// 		&& this->getc() == src.getc()
// 		&& this->getb() == src.getb())
// 		return (true);
// 	return (false);
// }

Fixed Line::geta(void) const { return _a;}
Fixed Line::getc(void) const { return _c;}
Fixed Line::getb(void) const { return _b;}

void Line::seta(Fixed const &a) {_a = a;}
void Line::setb(Fixed const &b) {_b = b;}
void Line::setc(Fixed const &c) {_c = c;}
