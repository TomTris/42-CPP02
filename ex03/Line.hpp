/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:23:46 by qdo               #+#    #+#             */
/*   Updated: 2024/06/02 18:29:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_HPP
#define LINE_HPP

#include "Fixed.hpp"

class Line
{
private:
	Fixed _a;
	Fixed _b;
	Fixed _c;

public:

	Line();
	Line(Fixed const &a, Fixed const &b, Fixed const &c);
	Line(Line const & src);
	~Line();
	Line & operator=(Line const & src);

	void  seta(Fixed const &x);
	void  setb(Fixed const &y);
	void  setc(Fixed const &x);

	Fixed geta(void) const;
	Fixed getb(void) const;
	Fixed getc(void) const;
	// bool operator==(Line const &src) const;
};

#endif
