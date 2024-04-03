/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:30:58 by agan              #+#    #+#             */
/*   Updated: 2024/04/03 14:30:59 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed()
{
	value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

/* 
Multiplies integer by 2 raised to the power of fractionalBits
to convert integer to fixed point representation 
 */
Fixed::Fixed(const int integer)
{
	// std::cout << "Int constructor called" << std::endl;
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
	// std::cout << "Float constructor called" << std::endl;
	setRawBits((int)roundf(floating_point * (1 << this->__fractionalBits)));
}

/* Copy constructor */
Fixed::Fixed(Fixed const &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	value = other.getRawBits();
}

/* Copy assignment operator overload */
Fixed& Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->value = other.getRawBits();
	return *this;
}

/* Destructor */
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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

/* Converts fixed-point value to a floating-point value */
float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->value) / (1 << __fractionalBits);
}

/* Converts fixed-point value to an integer value */
int Fixed::toInt( void ) const
{
	return this->value >> __fractionalBits;
}

std::ostream& operator <<(std::ostream& os, const Fixed& val)
{
	os << val.toFloat();
	return (os);
}

/*
	// comparison operators
	bool operator> (const Fixed &val) const;
	bool operator< (const Fixed &val) const;
	bool operator>= (const Fixed &val) const;
	bool operator<= (const Fixed &val) const;
	bool operator== (const Fixed &val) const;
	bool operator!= (const Fixed &val) const;

	// arithmetic operators
	Fixed operator+ (const Fixed &val) const;
	Fixed operator- (const Fixed val) const;
	Fixed operator* (const Fixed val) const;
	Fixed operator/ (const Fixed val) const;
	
	// increment/decrement operators
	Fixed operator++ (int); // postincrement
	Fixed operator-- (int);
	Fixed &operator++ (); // preincrement
	Fixed &operator-- (); 
*/

bool Fixed::operator> (const Fixed &val) const
{
	return (this->value > val.value);
}

bool Fixed::operator< (const Fixed &val) const
{
	return (this->value < val.value);
}

bool Fixed::operator>= (const Fixed &val) const
{
	return (this->value >= val.value);
}

bool Fixed::operator<= (const Fixed &val) const
{
	return (this->value <= val.value);
}

bool Fixed::operator== (const Fixed &val) const
{
	return (this->value == val.value);
}

bool Fixed::operator!= (const Fixed &val) const
{
	return (this->value != val.value);
}

Fixed Fixed::operator+ (const Fixed &val) const
{
	Fixed tmp;
	tmp.value = (this->value +val.value) >> __fractionalBits;
	return tmp;
}

Fixed Fixed::operator- (const Fixed &val) const
{
	Fixed tmp;
	tmp.value = (this->value - val.value) >> __fractionalBits;
	return tmp;
}

Fixed Fixed::operator* (const Fixed &val) const
{
	Fixed tmp;
	tmp.value = (long long) (this->value * val.value) >> __fractionalBits;
	return tmp;
}

Fixed Fixed::operator/ (const Fixed &val) const
{
	Fixed tmp(toFloat() / val.toFloat());
	return tmp;
}

/* post increment operator returns copy of fixed before increment */
Fixed Fixed::operator++ (int)
{
	Fixed tmp;
	tmp = *this;
	this->value++;
	return tmp;
}

/* post decrement operator returns copy of fixed before decrement */
Fixed Fixed::operator-- (int)
{
	Fixed tmp;
	tmp = *this;
	this->value--;
	return tmp;
}

Fixed& Fixed::operator++ ()
{
	++this->value;
	return *this;
}

Fixed& Fixed::operator-- ()
{
	--this->value;
	return *this;
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1.value < f2.value) ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1.value < f2.value) ? f1 : f2;
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1.value > f2.value) ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1.value > f2.value) ? f1 : f2;
}