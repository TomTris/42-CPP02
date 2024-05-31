/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:37:40 by qdo               #+#    #+#             */
/*   Updated: 2024/05/31 16:06:41 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{

private:
	int					_nbr;
	static const int	_fraction_bits = 8;

public:

	//Default constructor
	Fixed();
	
	//Copy constructor
	Fixed(Fixed const& src);
	//Deconstructor
	~Fixed();

	Fixed(int const nbr_int);
	Fixed(float const nbr_float);

	int 	toInt(void) const;
	float	toFloat(void) const;
	//Assignment constructor
	Fixed & operator=(Fixed const & src);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

};

std::ostream &operator<<( std::ostream & o, Fixed const & src);

#endif
