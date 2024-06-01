/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:15:06 by qdo               #+#    #+#             */
/*   Updated: 2024/06/01 20:37:10 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point ft_make_linie(Point const &a, Point const &b)
{
	Point ret;

	if (a.getX() == b.getX() || a.getY() == b.getY())
		return (Point(Fixed(0), Fixed(0)));
	ret.setX((a.getY() -  b.getY()) / (a.getX() - b.getX()));
	ret.setY(a.getY() - (a.getX() * ret.getX()));
	return (ret);
}

Point ft_on_line(Point a, Point b, Point linie1, Point const & point)
{
	Point	linie2;
	Point	ret;

	if (a.getX() == b.getX() || a.getY() == b.getY())
	{
		if (a.getX() == b.getX())
		{
			ret.setX(a.getX());
			ret.setY(point.getY());
			return (ret);
		}
		ret.setX(point.getX());
		ret.setY(a.getY());
		return (ret);
	}

	linie2.setX(Fixed(-1.0f) / linie1.getX());
	linie2.setY(point.getY() - (point.getX() * linie2.getX()));

	ret.setX(Fixed((linie1.getY()  - linie2.getY()) / (linie1.getX() - linie2.getX())));
	ret.setY(Fixed((linie1.getX() * ret.getX()) + linie1.getY()));
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

bool ft_check_vertex(Point const &a, Point const &b, Point const &linie, Point const &point)
{
	if ((a.getX() == b.getX() && a.getX() == point.getX())
	|| (a.getY() == b.getY() && a.getY() == point.getY()))
		return (true);
	if (a.getX() == b.getX() || a.getY() == b.getY())
		return (false);
	if (point.getY() == (linie.getX() * point.getX()) + linie.getY())
		return (true);
	return (false);
}

bool ft_correct_side(Point const &a, Point const &b, Point const &linie, Point const &c, Point const &point)
{
	if (a.getX() == b.getX())
	{
		Fixed c_dis(c.getX() - a.getX());
		if (c_dis < Fixed(0))
			c_dis = (Fixed(-1) * c_dis);
		Fixed point_dis_c(point.getX() - c.getX());
		if (point_dis_c < Fixed(0))
			point_dis_c = (Fixed(-1) * point_dis_c);
		if (point_dis_c > c_dis)
			return (false);
		return (true);
	}
	if (a.getY() == b.getY())
	{
		Fixed c_dis(c.getY() - a.getY());
		if (c_dis < Fixed(0))
			c_dis = (Fixed(-1) * c_dis);
		Fixed point_dis_c(point.getY() - c.getY());
		if (point_dis_c < Fixed(0))
			point_dis_c = (Fixed(-1) * point_dis_c);
		if (point_dis_c > c_dis)
			return (false);
		return (true);
	}
	
	Point linie_c(linie.getX(), c.getY() - c.getX() * linie.getX());
	Point point_on_linie_c(ft_on_line(a, b, linie_c, point));
	Fixed point_dis_c_x(point.getX() - point_on_linie_c.getX());
	Fixed point_dis_c_y(point.getY() - point_on_linie_c.getY());
	Fixed point_dis_c(point_dis_c_x * point_dis_c_x + point_dis_c_y * point_dis_c_y);

	Point c_on_linie_ab(ft_on_line(a, b, linie, c));
	Fixed c_dis_ab_x(c.getX() - c_on_linie_ab.getX());
	Fixed c_dis_ab_y(c.getY() - c_on_linie_ab.getY());
	Fixed c_dis_ab(c_dis_ab_x * c_dis_ab_x + c_dis_ab_y * c_dis_ab_y);
	if (c_dis_ab > point_dis_c)
		return (true);
	return (false);
}

bool bsp(Point const& a, Point const& b, Point const& c, Point const& point)
{
	// create a linie y=ax + b. a=point.x, b = point.y
	if (a == b || b == c || a == c)
		return (false);
	Point linie1 = ft_make_linie(a, b);
	Point linie2 = ft_make_linie(b, c);
	Point linie3 = ft_make_linie(a, c);

	if (ft_check_vertex(a, b, linie1, point) == true
	|| ft_check_vertex(b, c, linie2, point) == true
	|| ft_check_vertex(a, c, linie3, point) == true)
		return (false);
	//projection of the "point" on the line
	Point on_linie1 = ft_on_line(a, b, linie1, point);
	Point on_linie2 = ft_on_line(b, c, linie2, point);
	Point on_linie3 = ft_on_line(a, c, linie3, point);

	//if "point" on the line is out of scope -> wrong.
	if (ft_in_out(a, b, on_linie1) == false || ft_in_out(b, c, on_linie2) == false || ft_in_out(a, c, on_linie3) == false)
		return (false);

	if (ft_correct_side(a, b, linie1, c, point) == false
	|| ft_correct_side(a, c, linie3, b, point) == false
	|| ft_correct_side(b, c, linie2, a, point) == false)
		return (false);
	return (true);
}
