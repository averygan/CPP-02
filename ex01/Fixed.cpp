/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:29:35 by agan              #+#    #+#             */
/*   Updated: 2024/03/28 15:59:21 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* 
Multiplies integer by 2 raised to the power of fractionalBits
to convert integer to fixed point representation 
 */
Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(integer << this->__fractionalBits);
}

/*
- x = floating_input * 2^(fractional_bits)
- Round x to the nearest whole number
- Store x in an integer container to ensure result of conversion 
adheres to constraints of fixed point representation
*/
Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits((int)roundf(floating_point * (1 << this->__fractionalBits)));
}

/* Copy constructor */
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/* Copy assignment operator overload */
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = other.getRawBits();
	return *this;
}

/* Destructor */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* Function to get raw bits */
int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

/* Function to set raw bits */
void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

/* Converts fixed-point value to a floating-point value 
bitwise operation represents scaling factor to convert fixed point to floating point
static_cast: explicit type conversion
division scales fixed point back to floating point */
float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->value) / (1 << __fractionalBits);
}

/* Converts fixed-point value to an integer value 
bitwise right shift to truncate fractional part */
int Fixed::toInt( void ) const
{
	return this->value >> __fractionalBits;
}

std::ostream& operator <<(std::ostream& os, Fixed const &val)
{
	os << val.toFloat();
	return (os);
}
