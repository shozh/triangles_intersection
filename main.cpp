#include <iostream>
#include <fstream>
#include <cmath>
#include <numeric>
#include "point.h"
#include "vector.h"
#include "line.h"
#include "triangle.h"
#include "addition.h"
#include "polygon.h"
#include "triangle_intersect.h"
#include <vector>
using namespace std;

int main() {
	// данные для входа
	Point A(0, 0), B(6, 2), C(4, 8);
	Point a(0, 4), b(4, 0), c(6, 6);


	Triangle T(A, B, C), Y(a, b, c);

	intersect(T, Y);
	return 0;
}