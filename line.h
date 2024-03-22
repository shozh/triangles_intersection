#ifndef __LINE_H__
#define __LINE_H__

#pragma once

#include "point.h"
#include "vector.h"

// Line intersection coords
enum class LIC {intersected, parallel, same};

// Line Point position
enum class LPP {lower=-1, onto=0, upper=1};


struct Line {
	double A, B, C;
	
	Line();

	Line(double A, double B, double C);

	Line(Point P, Point Q);
	
	void println();

	LPP where_point(Point P);

};

LIC line_intersection(const Line& L, const Line& R, Point& P);
#endif // __LINE_H__
