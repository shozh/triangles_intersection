#include "point.h"
#include "line.h"
#include "addition.h"
#include <iostream>
#include <cmath>

Point::Point(): x(0), y(0) {}

Point::Point(double x, double y): x(x), y(y) {}

void Point::set(double x, double y) {
	this->x = x;
	this->y = y;
}

void Point::println() {
	std::cout << x << " " << y << std::endl;
}

bool operator== (const Point& lhs, const Point& rhs) {
	return feq(lhs.x, rhs.x) && feq(lhs.y, rhs.y);
}

bool operator!= (const Point& lhs, const Point& rhs) {
	return !(lhs == rhs);
}

double dist(const Point& A, const Point& B) {
	return sqrt( (B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y) );
}

bool is_point_between(const Point& A, const Point& B, const Point& P) {
	double distAB = dist(A, B);
	double distAP = dist(A, P);
	double distPB = dist(P, B);
	return feq(distAP + distPB, distAB);
}

bool segment_same(Point A, Point B, Point P, Point Q) {
	if (is_point_between(A, B, P) && is_point_between(A, B, Q))
		return true;
	
	if (is_point_between(P, Q, A) && is_point_between(P, Q, B))
		return true;

	return false;
}

bool is_section_intersected(const Point P1, const Point P2, const Point Q1, const Point Q2, Point& R) {
	Line lP(P1, P2), lQ(Q1, Q2);
	
	line_intersection(lP, lQ, R);

	bool is_R_in_lineP = false;
	bool is_R_in_lineQ = false;

	if (is_point_between(P1, P2, R))
		is_R_in_lineP = true;
	
	if (is_point_between(Q1, Q2, R))
		is_R_in_lineQ = true;

	if (is_R_in_lineP && is_R_in_lineQ)
		return true;
	return false;
}

std::ostream& operator<< (std::ostream& out, const Point& P) {
	out << '(' << P.x << ", " << P.y << ')';
	return out;
}