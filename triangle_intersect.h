#ifndef __TRIANGLE_INTERSECT_H__
#define __TRIANGLE_INTERSECT_H__

#include "polygon.h"
#include "point.h"
#include "line.h"
#include "vector.h"
#include "triangle.h"
#include "addition.h"

struct seg {
	Point A;
	Point B;

	seg();
	seg(Point A, Point B);
};

bool intersect(Triangle T, Triangle Y);

#endif // __TRIANGLE_INTERSECT_H__