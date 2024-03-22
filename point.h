#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

struct Point {
	double x;
	double y;

	Point();

	Point(double x, double y);

	void set(double x, double y);

	void println();
};

bool operator== (const Point& lhs, const Point& rhs);
bool operator!= (const Point& lhs, const Point& rhs);

double dist(const Point& A, const Point& B);

bool is_point_between(const Point& A, const Point& B, const Point& P);

bool is_section_intersected(const Point P1, const Point P2, const Point Q1, const Point Q2, Point& R);

bool segment_same(Point A, Point B, Point P, Point Q);

std::ostream& operator<< (std::ostream& out, const Point& P);

#endif