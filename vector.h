#ifndef __VECTOR_H__
#define __VECTOR_H__

#pragma once

#include "point.h"

// VC - Vector collinear
// same - same direction
// opp - opposite direction
// non - non-collinear
enum class VC {same=1, opp=-1, non=0};

struct Vector {
	double x;
	double y;

	Vector();

	Vector(double x, double y);

	Vector(Point P, Point Q);

	void println();
};


Vector operator+ (const Vector& self);
Vector operator- (const Vector& self);

Vector operator+ (const Vector& lhs, const Vector& rhs);
Vector operator- (const Vector& lhs, const Vector& rhs);

Vector operator* (double num, const Vector& self);
Vector operator/ (const Vector& self, double num);

bool operator== (const Vector& lhs, const Vector& rhs);
bool operator!= (const Vector& lhs, const Vector& rhs);

VC collinear(const Vector& lhs, const Vector& rhs);

Vector operator- (const Point& lhs, const Point& rhs);

#endif // __VECTOR_H__