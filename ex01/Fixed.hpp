/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:29:32 by agan              #+#    #+#             */
/*   Updated: 2024/03/28 15:59:17 by agan             ###   ########.fr       */
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
	Fixed();
	Fixed(const int integer);
	Fixed(const float floating_point);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int	getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int	toInt( void ) const;
};

std::ostream& operator <<(std::ostream& os, const Fixed& val);

#endif
