/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:50:07 by qdo               #+#    #+#             */
/*   Updated: 2024/05/31 17:54:44 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _nbr(0) {
	// std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() {
	// std::cout << "Deconstructor called" << std::endl;
}
Fixed::Fixed(Fixed const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	setRawBits(src.getRawBits());
}

Fixed::Fixed(int nbr_int)
{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nbr_int << _fraction_bits);
}
Fixed::Fixed(float nbr_float)
{
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(nbr_float * (1 << _fraction_bits)));
}



int Fixed::toInt(void) const
{
	std::cout << "toInt called" << std::endl;
	return (getRawBits() >> _fraction_bits);
}
float Fixed::toFloat(void) const
{
	// std::cout << "toFloat called" << std::endl;
	float f;
	f = (float)this->getRawBits() / (1 << this->_fraction_bits);
	return (f);
}

int		Fixed::getRawBits(void) const 
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _nbr;
}
void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_nbr = raw;
}



Fixed & Fixed::operator=(Fixed const & src)
{
	// std::cout << "Coppy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}
std::ostream &operator<<( std::ostream & o, Fixed const & src)
{
	// std::cout << "operator<< called" << std::endl;
	o << src.toFloat();
	return (o);
}


Fixed & Fixed::operator++(void)
{
	setRawBits(getRawBits() + 1);
	return (*this);
}
Fixed Fixed::operator++(const int)
{
	Fixed temp = *this;

	this->setRawBits(getRawBits() + 1);
	return (temp);
}
Fixed &Fixed::operator--(void)
{
	setRawBits(getRawBits() - 1);
	return (*this);
}
Fixed Fixed::operator--(const int)
{
	Fixed temp = *this;
	setRawBits(getRawBits() - 1);
	return (temp);
}

bool Fixed::operator>(Fixed const & src){	return (getRawBits() > src.getRawBits() ? true : false); }
bool Fixed::operator<(Fixed const & src){	return (getRawBits() < src.getRawBits() ? true : false); }
bool Fixed::operator>=(Fixed const & src){	return (getRawBits() >= src.getRawBits() ? true : false); }
bool Fixed::operator<=(Fixed const & src){	return (getRawBits() <= src.getRawBits() ? true : false); }
bool Fixed::operator==(Fixed const & src){	return (getRawBits() == src.getRawBits() ? true : false); }
bool Fixed::operator!=(Fixed const & src){	return (getRawBits() != src.getRawBits() ? true : false); }

Fixed Fixed::operator+(Fixed const & src)
{
	Fixed temp = *this;

	temp.setRawBits(temp.getRawBits() + src.getRawBits());
	return (temp);
}
Fixed Fixed::operator-(Fixed const & src)
{
	Fixed temp = *this;

	temp.setRawBits(temp.getRawBits() - src.getRawBits());
	return (temp);
}
Fixed Fixed::operator*(Fixed const & src)
{
	Fixed temp = *this;

	temp.setRawBits((temp.getRawBits() * src.getRawBits()) >> _fraction_bits);
	return (temp);
}
Fixed Fixed::operator/(Fixed const & src)
{
	// Fixed temp = Fixed(this->toFloat() / src.toFloat());
	Fixed temp;
	
	temp.setRawBits((this->getRawBits() << _fraction_bits) / src.getRawBits());
	return (temp);
}

Fixed &Fixed::min(Fixed & a, Fixed & b){	return (a.getRawBits() < b.getRawBits() ? a : b); }
Fixed &Fixed::max(Fixed & a, Fixed & b){	return (a.getRawBits() > b.getRawBits() ? a : b); }
Fixed const &Fixed::min(Fixed const & a, Fixed const & b) {	return (a.getRawBits() < b.getRawBits() ? a : b); }
Fixed const &Fixed::max(Fixed const & a, Fixed const & b) {	return (a.getRawBits() > b.getRawBits() ? a : b); }
