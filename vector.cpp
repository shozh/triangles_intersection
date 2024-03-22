#include "vector.h"
#include "point.h"
#include "addition.h"
#include <iostream>

Vector::Vector(): x(0), y(0) {}

Vector::Vector(double x, double y): x(x), y(y) {}

Vector::Vector(Point P, Point Q): x(P.x - Q.x), y(P.y - Q.y) {}

void Vector::println() {
	std::cout << x << " " << y << std::endl; 
}

Vector operator+ (const Vector& self) {
	return {self.x, self.y};
}

Vector operator- (const Vector& self) {
	return {-self.x, -self.y};
}

Vector operator+ (const Vector& lhs, const Vector& rhs) {
	return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Vector operator- (const Vector& lhs, const Vector& rhs) {
	return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Vector operator* (double num, const Vector& self) {
	return {num * self.x, num * self.y};
}
Vector operator/ (const Vector& self, double num) {
	if (num == 0) {
		throw std::string{"ZeroDivisionError"};
	}
	return {self.x / num, self.y / num};
}

bool operator== (const Vector& lhs, const Vector& rhs) {
	return feq(lhs.x, rhs.x) && feq(lhs.y, rhs.y);
}
bool operator!= (const Vector& lhs, const Vector& rhs) {
	return !(lhs == rhs);
}



VC collinear(const Vector& lhs, const Vector& rhs) {
	if ((lhs.x == 0 && lhs.y == 0) || (rhs.x == 0 && rhs.y == 0))
		return VC::same;

	if ((rhs.x == 0 || rhs.y == 0) && (lhs.x != 0 && lhs.y != 0))
		return VC::non;
	if ((lhs.x == 0 || lhs.y == 0) && (rhs.x != 0 && rhs.y != 0))
		return VC::non;
	if (lhs.x == 0 && rhs.x == 0) {
		if ((lhs.y < 0 && rhs.y > 0) || (lhs.y > 0 && rhs.y < 0))
			return VC::opp;
		else
			return VC::same;
	}
	if (lhs.y == 0 && rhs.y == 0) {
		if ((lhs.x < 0 && rhs.x > 0) || (lhs.x > 0 && rhs.x < 0))
			return VC::opp;
		else
			return VC::same;
	}
	if ((lhs.x == 0 && rhs.y == 0) || (lhs.y == 0 && rhs.x == 0))
		return VC::non;
	// Мы проверили все случаи с нулём
	double f = rhs.x / lhs.x;
	double s = rhs.y / lhs.y;
	if (feq(f, s)) {
		if (f > 0)
			return VC::same;
		else
			return VC::opp;
	} else {
		return VC::non;
	}

}


Vector operator-(const Point &lhs, const Point& rhs)
{
	return Vector(lhs, rhs);;
}
