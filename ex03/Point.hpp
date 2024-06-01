/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:58:20 by qdo               #+#    #+#             */
/*   Updated: 2024/06/01 17:12:42 by qdo              ###   ########.fr       */
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

	Fixed getX(void) const;
	Fixed getY(void) const;
	void  setX(Fixed const &x);
	void  setY(Fixed const &y);
	bool operator==(Point const &src) const;
};

typedef struct s_linie
{
	Fixed a;
	Fixed b;	
} t_linie;

#endif
