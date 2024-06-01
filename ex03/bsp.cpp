/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:15:06 by qdo               #+#    #+#             */
/*   Updated: 2024/06/01 17:15:50 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point ft_make_linie(Point const &a, Point const &b)
{
	Point ret;

	ret.setX((a.getY() -  b.getY()) / (a.getX() - b.getX()));
	ret.setY(a.getY() - (a.getX() * ret.getX()));
	return (ret);
}

Point ft_on_linie(Point linie1, Point const & point)
{
	Point	linie2;
	Point	ret;

	linie2.setX(Fixed(-1.0f) / linie1.getX());
	linie2.setY(point.getY() - (point.getX() * linie2.getX()));

	ret.setX((Fixed((point.getX() * linie2.getX()) - linie2.getY() - linie1.getY())) / linie1.getX());
	ret.setY(Fixed((linie1.getX() * point.getX()) + linie1.getY()));
	return (ret);
}

bool	ft_in_out(Point const &a, Point const &b, Point const &point)
{
	if 	  ((a.getX() - b.getX() > 0) != (a.getX() - point.getX() > 0)
		|| (a.getY() - b.getY() > 0) != (a.getY() - point.getY() > 0)
		|| (a.getX() - b.getX() == 0) != (a.getX() - point.getX() == 0)
		|| (a.getY() - b.getY() == 0) != (a.getY() - point.getY() == 0))
		return (false);
	return (true);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// create a linie y=ax + b. a=point.x, b = point.y
	if (a == b || b == c || a == c)
		return (false);
	Point linie1 = ft_make_linie(a, b);
	Point linie2 = ft_make_linie(a, b);
	Point linie3 = ft_make_linie(a, b);

	//projection of the "point" on the line
	Point on_linie1 = ft_on_linie(linie1, point);
	Point on_linie2 = ft_on_linie(linie1, point);
	Point on_linie3 = ft_on_linie(linie1, point);

	//if "point" on the line is out of scope -> wrong.
	if (ft_in_out(a, b, point) == false || ft_in_out(b, c, point) == false || ft_in_out(a, c, point) == false)
		return (false);
	return (true);
}
