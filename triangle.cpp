#include "triangle.h"
#include "point.h"
#include "line.h"
#include "vector.h"
#include "addition.h"
#include <iostream>
#include <string>
#include <cmath>

Triangle::Triangle() {
	A = Point(0, 0);
	B = Point(0, 1);
	C = Point(1, 0);
}

// Неравенство треугольника
Triangle::Triangle(Point A, Point B, Point C) {
	double AB = dist(A, B);
	double BC = dist(B, C);
	double AC = dist(A, C);
	if ((AB + BC > AC) && (AB + AC > BC) && (BC + AC > AB)) {
		this->A = A;
		this->B = B;
		this->C = C;
	}
	else {
		throw std::string{"It is not a triangle!"};
	}
}

Triangle::Triangle(Line L, Line R, Line T) {
	Point A, B, C;
	LIC LR = line_intersection(L, R, A);
	if (LR != LIC::intersected)
		throw std::string{"It is not a triangle!"};
	LIC LT = line_intersection(L, T, B);
	if (LT != LIC::intersected)
		throw std::string{"It is not a triangle!"};
	LIC RT = line_intersection(R, T, C);
	if (RT != LIC::intersected)
		throw std::string{"It is not a triangle!"};

	Triangle(A, B, C);
}

double Triangle::perimeter() {
	double AB = dist(A, B);
	double BC = dist(B, C);
	double AC = dist(A, C);
	return AB + BC + AC;
}

// Формула Герона
double Triangle::area() {
	double p = perimeter() / 2;
	double a = dist(A, B);
	double b = dist(B, C);
	double c = dist(A, C);
	return sqrt(p * (p - a) * (p - b) * (p -c) );
}
TPP Triangle::where_point(const Point P) {
	if (P == A || P == B || P == C)
		return TPP::on;

	Line AB(A, B), BC(B, C), CA(C, A);

	LPP ABP = AB.where_point(P);
	LPP BCP = BC.where_point(P);
	LPP CAP = CA.where_point(P);

	LPP ABC = AB.where_point(C);
	LPP BCA = BC.where_point(A);
	LPP CAB = CA.where_point(B);

    // Неправиьлное решение, точка может лежать на продолжении прямой
//	if (ABP == LPP::onto || BCP == LPP::onto || CAP == LPP::onto )
//		return TPP::on;

    // Будем использовать сегменты, я бы переписал код, но так лень, может позже
    if (is_point_between(A, B, P) || is_point_between(B, C, P) || is_point_between(C, A, P))
        return TPP::on;

	if (ABP == ABC && BCP == BCA && CAP == CAB)
		return TPP::inside;
	else
		return TPP::outside;

}