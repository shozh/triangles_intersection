#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "line.h"
#include "point.h"
#include "vector.h"

// where point lies in triangle
enum class TPP {
	outside, inside, on
};

struct Triangle {
	Point A {0, 0}, B {0, 1}, C {1, 0};

	Triangle();
	Triangle(Point A, Point B, Point C);
	Triangle(Line L, Line R, Line T);

	double perimeter();
	double area();
	TPP where_point(const Point P);
};




#endif // __TRIANGLE_H__