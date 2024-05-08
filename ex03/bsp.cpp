/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:48:39 by agan              #+#    #+#             */
/*   Updated: 2024/04/03 16:48:40 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/* Function to calculate area of triangle formed by (x1,y1) (x2,y2) (x3,y3)
Using shoelace formula/method of triangulation 
- Calculates signed area of the triangle formed by vertex and two other vertices
	Given area = 1/2 * base * height
	- Base = difference in y coords
	- Height = distance from vertex to opp side
- Sums up the signed areas of three triangles and takes abs value */
float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3-y1) + x3 * (y1-y2)) / 2.0);
}

/* Check if point lies within triangle ABC */
bool point_inside(float ax, float ay, float bx, float by, float cx, float cy, float x, float y)
{
	/* Triangle ABC */
	float abc = area(ax, ay, bx, by, cx, cy);

	/* Triangle PBC */
	float pbc = area(x, y, bx, by, cx, cy);

	/* Triangle PAC*/
	float pac = area(ax, ay, x, y, cx, cy);

	/* Triangle PAB */
	float pab = area(ax, ay, bx, by, x, y);

	return (abc == (pbc + pac + pab));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (point_inside(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), \
		b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat(), point.getX().toFloat(), \
		point.getY().toFloat()));
}