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
    ifstream ifs("input.txt");

	Point A;
    Point B;
    Point C;
    Point a;
    Point b;
    Point c;

    A.set(0, 0);
    B.set(6, 2);
    C.set(4, 8);

    a.set(4, 0);
    b.set(0, 4);
    c.set(6, 6);



	Triangle T(A, B, C), Y(a, b, c);

	intersect(T, Y);


	ifs.close();
	return 0;
}