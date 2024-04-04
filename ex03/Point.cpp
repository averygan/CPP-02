/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:48:35 by agan              #+#    #+#             */
/*   Updated: 2024/04/03 16:48:36 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) 
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) 
{
	// std::cout << "Float constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "Point destructor called" << std::endl;
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other)
{
	// std::cout << "Overloaded assignment called" << std::endl;
	if (this != &other)
	{
		(Fixed)_x = other.getX();
		(Fixed)_y = other.getY();
	}
	return *this;
}

/* Public member functions */
/* Getters */
const Fixed &Point::getX(void) const 
{
	return (this->_x);
}

const Fixed &Point::getY(void) const 
{
	return (this->_y);
}