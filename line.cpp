#include "line.h"
#include "point.h"
#include <iostream>
#include "addition.h"

Line::Line(): A(1), B(1), C(0) {}

Line::Line(double A, double B, double C) {
		this->A = A;
		this->B = B;
		this->C = C;
		if (A == 0 and B == 0)
			throw std::string{"It is not a line!"};
	}

// Прямая по двум точкам
Line::Line(Point P, Point Q) {
		A = P.y - Q.y;
		B = Q.x - P.x;
		C = P.x * Q.y - Q.x * P.y;
		
		if (A == 0 and B == 0)
			throw std::string{"It is not a line!"};
	}
	
void Line::println() {
	std::cout << A << ' ' << B << ' ' << C << '.' << std::endl;
}

LIC line_intersection(const Line& L, const Line& R, Point& P) {
	double tmp = det2(L.A, L.B, R.A, R.B);
	double rmp = det2(L.B, L.C, R.B, R.C);
	if (tmp) {
		double x = rmp / tmp;
		double y = det2(L.C, L.A, R.C, R.A) / tmp;
		P.set(x, y);
		//std::cout << "Прямые пересекаются в точке: (" << x << ", " << y << ")." << std::endl;
		return LIC::intersected;
	} else {
		if (tmp == rmp) {
		//	std::cout << "Прямые совпадают." << std::endl;
			return LIC::same;
		}
			
		else {
		//	std::cout << "Прямые параллельны." << std::endl;
			return LIC::parallel;
		}
	}
}

// Линейные неравенства по отношению к прямой
LPP Line::where_point(Point P) {
	double res = A * P.x + B * P.y + C;

	if (res > 0)
		return LPP::upper;
	else if (res == 0)
		return LPP::onto;
	else
		return LPP::lower;
}