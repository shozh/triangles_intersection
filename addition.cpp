#include "point.h"
#include "vector.h"
#include "line.h"
#include <cmath>

bool feq(double a, double b) {
	return std::fabs(a - b) < 1e-9;
}

double det2(double a, double b, double c, double d) {
	return a*d - b*c;
}

// Box::Box(Point P, Point Q) {
// 	p = P;
// 	q = Q;
// 	v = Vector(P, Q);
// 	l = Line(P, Q);
// }