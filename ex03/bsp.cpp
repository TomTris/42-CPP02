/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:15:06 by qdo               #+#    #+#             */
/*   Updated: 2024/06/02 19:43:50 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Line.hpp"

Line ft_make_linie(Point const &a, Point const &b)
{
	Line ret;

	if (a.getX() == b.getX())
	{
		ret.seta(1);
		ret.setb(0);
		ret.setc(Fixed(-1) * a.getX());
		return (ret);
	}
	if (a.getY() == b.getY())
	{
		ret.seta(0);
		ret.setb(1);
		ret.setc(Fixed(-1) * a.getY());
		return (ret);
	}
	ret.seta(1);
	ret.setb(    (b.getX() - a.getX())  /  (a.getY() - b.getY())     );
	ret.setc(    (a.getX() + (ret.getb() * a.getY()))    * Fixed(-1)   );
	return (ret);
}

bool ft_check_vertex(Line const &linie, Point const &point)
{
	Fixed ret = (point.getX() * linie.geta()) + (point.getY() * linie.getb()) + linie.getc();
	if (ret == Fixed(0))
		return (true);
	return (false);
}


bool	ft_in_out(Point const &b, Point const &c, Point const &inter)
{	
	if 	  ((b.getX() - c.getX() > 0) != (b.getX() - inter.getX() > 0)
		|| (b.getY() - c.getY() > 0) != (b.getY() - inter.getY() > 0)
		|| (b.getX() - c.getX() == 0) != (b.getX() - inter.getX() == 0)
		|| (b.getY() - c.getY() == 0) != (b.getY() - inter.getY() == 0))
		return (false);
	return (true);
}

bool	ft_intersection(Point b, Point c, Line ap, Line bc)
{
	Point inter;
	if ((ap.geta() == 0 && bc.geta() == 0)
	 || (ap.getb() == 0 && bc.getb() == 0)
	 || (ap.geta() == bc.geta() && ap.getb() == bc.getb()))
	 	return (false);

	if (ap.geta() == 0)
	{
		inter.setY(Fixed(-1) * ap.getc() / ap.getb());
		inter.setX(Fixed(-1) * ( (bc.getb() * inter.getY()) + bc.getc() )  / bc.geta()  );
	}
	if (bc.geta() == 0)
	{
		inter.setY(Fixed(-1) * bc.getc() / bc.getb());
		inter.setX(Fixed(-1) * ( (ap.getb() * inter.getY()) + ap.getc() )  / ap.geta()  );
	}
	else
	{
		inter.setY(    (ap.getc() - bc.getc()) / (bc.getb() - ap.getb())      );
		inter.setX(     Fixed(-1) * ( ap.getb() * inter.getY() + ap.getc())  );
	}
	std::cout << "xb = " << b.getX() << std::endl;
	std::cout << "yb = " << b.getY() << std::endl;
	std::cout << "xc = " << c.getX() << std::endl;
	std::cout << "yc = " << c.getY() << std::endl;
	std::cout << "xinter = " << inter.getX() << std::endl;
	std::cout << "xyinter = " << inter.getY() << std::endl;
	return (ft_in_out(b, c, inter));
}

bool bsp(Point const& a, Point const& b, Point const& c, Point const& point)
{
	if (a == b || b == c || a == c || a == point || b == point || c == point)
		return (false);

	Line line_ab = ft_make_linie(a, b);
	Line line_bc = ft_make_linie(b, c);
	Line line_ac = ft_make_linie(a, c);

	std::cout << "a = " << line_ab.geta() << " b = " << line_ab.getb() << " c = " << line_ab.getc() << std::endl;
	std::cout << "a = " << line_bc.geta() << " b = " << line_bc.getb() << " c = " << line_bc.getc() << std::endl;
	std::cout << "a = " << line_ac.geta() << " b = " << line_ac.getb() << " c = " << line_ac.getc() << std::endl;
	if (ft_check_vertex(line_ab, point)
	 || ft_check_vertex(line_bc, point)
	 || ft_check_vertex(line_ac, point))
		return (false);
std::cout << 3 << std::endl;
	Line line_ap = ft_make_linie(a, point);
	Line line_bp = ft_make_linie(b, point);
	Line line_cp = ft_make_linie(c, point);

	if (!ft_intersection(b, c, line_ap, line_bc) || !ft_intersection(a, c, line_bp, line_ac) || !ft_intersection(a, b, line_cp, line_ab) )
		return (false);
	//if "point" on the line is out of scope -> wrong.
	return (true);
}
