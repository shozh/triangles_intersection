#ifndef __POLYGON_H__
#define __POLYGON_H__

#pragma once

#include "point.h"

struct ConvexQuadrilateral {
	Point A, B, C, D;

	ConvexQuadrilateral();
	ConvexQuadrilateral(Point A, Point B, Point C, Point D);

//	double perimeter;
	double area();
};

struct ConvexPentagon {
	Point A, B, C, D, E;

	ConvexPentagon();
	ConvexPentagon(Point a, Point b, Point c, Point d, Point e);
	
	void println();

	double area();
};

struct ConvexHexagon {
    Point A, B, C, D, E, F;

    ConvexHexagon();
    ConvexHexagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6);

    void println();

    double area();
};


#endif // __POLYGON_H__