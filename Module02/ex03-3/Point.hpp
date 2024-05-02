/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotorral <jotorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:54:38 by babreton          #+#    #+#             */
/*   Updated: 2024/01/25 17:19:47 by jotorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_HPP_
#define _POINT_HPP_

#include "Fixed.hpp"
#include <iostream>

class Point {
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &src);
		~Point();

		Point &	operator=(Point const &rSym);
		Point	operator-(Point const &rSym);
		
		Fixed const	getX() const;
		Fixed const	getY() const;
		
	private:
		Fixed const	x;
		Fixed const	y;
};

std::ostream &	operator<<(std::ostream &o, Point const &rSym);

#endif
