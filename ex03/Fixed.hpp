/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:48:24 by agan              #+#    #+#             */
/*   Updated: 2024/04/03 16:48:25 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int __fractionalBits = 8;

public:
	// constructors and destructors
	Fixed();
	Fixed(const int integer);
	Fixed(const float floating_point);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	// comparison operators
	bool operator> (const Fixed &val) const;
	bool operator< (const Fixed &val) const;
	bool operator>= (const Fixed &val) const;
	bool operator<= (const Fixed &val) const;
	bool operator== (const Fixed &val) const;
	bool operator!= (const Fixed &val) const;

	// arithmetic operators
	Fixed operator+ (const Fixed &val) const;
	Fixed operator- (const Fixed &val) const;
	Fixed operator* (const Fixed &val) const;
	Fixed operator/ (const Fixed &val) const;
	
	// increment/decrement operators
	Fixed operator++ (int); // postincrement
	Fixed operator-- (int);
	Fixed &operator++ (); // preincrement
	Fixed &operator-- ();

	// minmax functions
	static Fixed &min(Fixed &f1, Fixed &f2);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);

	// member functions
	int	getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int	toInt( void ) const;
};

std::ostream& operator <<(std::ostream& os, const Fixed& val);

#endif
