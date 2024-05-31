/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:50:07 by qdo               #+#    #+#             */
/*   Updated: 2024/05/31 06:56:19 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _nbr(0) {std::cout << "Default constructor called" << std::endl;}
Fixed::Fixed( Fixed &src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_nbr = src.getRawBits();
}

Fixed::~Fixed() {std::cout << "Deconstructor called" << std::endl;}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Coppy assignment constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
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
