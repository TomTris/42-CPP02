/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:15:06 by qdo               #+#    #+#             */
/*   Updated: 2024/06/02 07:19:15 by qdo              ###   ########.fr       */
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


// return project of point on line_ab
Point ft_on_line(Point a, Point b, Point line_ab, Point const & point)
{
	Point	perpendicular;
	Point	ret;

	if (a.getX() == b.getX())
	{
		ret.setX(a.getX());
		ret.setY(point.getY());
		return (ret);
	}
	if (a.getY() == b.getY())
	{
		ret.setX(point.getX());
		ret.setY(a.getY());
		return (ret);
	}

	perpendicular.setX(Fixed(-1.0f) / line_ab.getX());
	perpendicular.setY(point.getY() - (point.getX() * perpendicular.getX()));

	ret.setX(Fixed((line_ab.getY()  - perpendicular.getY()) / (perpendicular.getX() - line_ab.getX())));
	ret.setY(Fixed((line_ab.getX() * ret.getX()) + line_ab.getY()));
	return (ret);
}

bool	ft_in_out(Point const &a, Point const &b, Point const &point)
{
	std::cout << " aX " << a.getX() << std::ends;
	std::cout << " aY " << a.getY() << std::endl;
	std::cout << " bX " << b.getX() << std::ends;
	std::cout << " bY " << b.getY() << std::endl;
	std::cout << " pX " << point.getX() << std::ends;
	std::cout << " pY " << point.getY() << std::endl;
	
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
	if (a == b || b == c || a == c || a == point || b == point || c == point)
		return (false);

	Point line_ab = ft_make_linie(a, b);
	Point line_bc = ft_make_linie(b, c);
	Point line_ac = ft_make_linie(a, c);

	if (ft_check_vertex(a, b, line_ab, point) == true
	|| ft_check_vertex(b, c, line_bc, point) == true
	|| ft_check_vertex(a, c, line_ac, point) == true)
		return (false);

	//projection of the "point" on the line
	Point on_linie1 = ft_on_line(a, b, line_ab, point);
	Point on_line_bc = ft_on_line(b, c, line_bc, point);
	Point on_line_ac = ft_on_line(a, c, line_ac, point);

	//if "point" on the line is out of scope -> wrong.
	if (ft_in_out(a, b, on_linie1) == false || ft_in_out(b, c, on_line_bc) == false || ft_in_out(a, c, on_line_ac) == false)
		return (false);
		std::cout << "12112" << std::endl;
	if (ft_correct_side(a, b, line_ab, c, point) == false
	|| ft_correct_side(a, c, line_ac, b, point) == false
	|| ft_correct_side(b, c, line_bc, a, point) == false)
		return (false);
	return (true);
}
