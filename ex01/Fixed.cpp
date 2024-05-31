/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:50:07 by qdo               #+#    #+#             */
/*   Updated: 2024/05/31 16:23:01 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _nbr(0) {std::cout << "Default constructor called" << std::endl;}
Fixed::~Fixed() {std::cout << "Deconstructor called" << std::endl;}


Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(src.getRawBits());
}

Fixed::Fixed(int nbr_int)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nbr_int << _fraction_bits);
}

Fixed::Fixed(float nbr_float)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(nbr_float * (1 << _fraction_bits)));
}



int Fixed::toInt(void) const
{
	std::cout << "toInt called" << std::endl;
	return (getRawBits() >> _fraction_bits);
}

float Fixed::toFloat(void) const
{
	std::cout << "toFloat called" << std::endl;
	float f;
	f = (float)this->getRawBits() / (1 << this->_fraction_bits);
	return (f);
}





Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Coppy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}


std::ostream &operator<<( std::ostream & o, Fixed const & src)
{
	std::cout << "operator<< called" << std::endl;
	o << src.toFloat();
	return (o);
}





int		Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return _nbr;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_nbr = raw;
}

