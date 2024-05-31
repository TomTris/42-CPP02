/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:37:40 by qdo               #+#    #+#             */
/*   Updated: 2024/05/31 06:50:05 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{

private:
	int					_nbr;
	static const int	_fraction_bits = 8;

public:

	//Default constructor
	Fixed();
	
	//Copy constructor
	Fixed(Fixed & src);
	//Deconstructor
	~Fixed();
	
	
	//Assignment constructor
	Fixed & operator=(Fixed const & src);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

};

#endif
