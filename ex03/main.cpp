/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:48:20 by agan              #+#    #+#             */
/*   Updated: 2024/04/03 16:48:21 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	std::string green = "\033[0;32m";
	std::string red = "\033[0;31m";
	std::string white = "\033[0;37m";

	std::cout << "Point inside triangle\n";
	std::cout << "\n---------------------------------------------------------------------\n" << std::endl;
	
	Point a1(10, 30);
	Point b1(0, 0);
	Point c1(20, 0);
	Point p1(15, 5);

	Point a2(10, 30);
	Point b2(0, 0);
	Point c2(20, 0);
	Point p2(12, 8);

	Point a3(10, 30);
	Point b3(0, 0);
	Point c3(20, 0);
	Point p3(18, 3);

	std::cout << "Test Case 1: " << (bsp(a1, b1, c1, p1) ? green + "Correct" : red + "Incorrect") << white << std::endl;
	std::cout << "Test Case 2: " << (bsp(a2, b2, c2, p2) ? green + "Correct" : red + "Incorrect") << white << std::endl;
	std::cout << "Test Case 3: " << (bsp(a3, b3, c3, p3) ? green + "Correct" : red + "Incorrect") << white << std::endl;

	Point a4(10, 30);
	Point b4(0, 0);
	Point c4(20, 0);
	Point p4(20, -1);

	Point a5(2, 30);
	Point b5(0, 0);
	Point c5(20, 0);
	Point p5(-3, 0);

	Point a6(3, 30);
	Point b6(0, 0);
	Point c6(20, 0);
	Point p6(-2, 3);

	std::cout << std::endl << "Point outside triangle\n";
	std::cout << "\n---------------------------------------------------------------------\n" << std::endl;

	std::cout << "Test Case 4: " << (bsp(a4, b4, c4, p4) ? red + "Incorrect" : green + "Correct") << white << std::endl;
	std::cout << "Test Case 5: " << (bsp(a5, b5, c5, p5) ? red + "Incorrect" : green + "Correct") << white << std::endl;
	std::cout << "Test Case 6: " << (bsp(a6, b6, c6, p6) ? red + "Incorrect" : green + "Correct") << white << std::endl;
}

