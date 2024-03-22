#include "polygon.h"
#include "point.h"
#include "line.h"
#include "vector.h"
#include "triangle.h"
#include "addition.h"
#include <cmath>
#include <iostream>
#include <vector>

ConvexQuadrilateral::ConvexQuadrilateral() {
	A = Point(0, 0);
	B = Point(0, 1);
	C = Point(1, 1);
	D = Point(1, 0);
}

// Подразумевается, что четыре точки образуют выпуклый четырёх угольник, проверки нету.
ConvexQuadrilateral::ConvexQuadrilateral(Point A, Point B, Point C, Point D) {
	//Line L1(A, B), L2(B, C), L3(C, D), L4(D, A), L5(A, C), L6(B, D);
	Point temp;

	// Начали обход с диагонали
	if (is_section_intersected(A, B, C, D, temp)) {
		this->A = A;
		this->B = C;
		this->C = B;
		this->D = D;
	} else {
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
}

double ConvexQuadrilateral::area() {
	Triangle ABC(A, B, C);
	Triangle ACD(A, C, D);
	return ABC.area() + ACD.area();
}

ConvexPentagon::ConvexPentagon(): A(0, 0), B(2, 0), C(2, 1), D(1, 2), E(0, 1) {}


// точки не совпадают и не лежат на одной прямой (8 случаев обхода)
ConvexPentagon::ConvexPentagon(Point a, Point b, Point c, Point d, Point e) {

	//std::vector<Point> order = {a, b, c, d, e};

	Point start = a;
	std::vector<Point> nexts = {b, c, d, e};

	Point second; 
	for (auto it = nexts.begin(); it != nexts.end(); ++it) {
		Point next = *it;
		Line line(start, next);
		LPP data[3];
		size_t i = 0;
		for (Point temp: nexts) {
			if (temp != next)
				data[i++] = line.where_point(temp);
		}
		if (data[0] == data[1] && data[1] == data[2]) {
			second = next;
			nexts.erase(it);
			break;
		}	
	}

	Point third;
	for (auto it = nexts.begin(); it != nexts.end(); ++it) {
		Point next = *it;
		Line line(second, next);
		LPP data[3];
		data[2] = line.where_point(start);
		size_t i = 0;
		for (Point temp: nexts) {
			if (temp != next)
				data[i++] = line.where_point(temp);
		}
		if (data[0] == data[1] && data[1] == data[2]) {
			third = next;
			nexts.erase(it);
			break;
		}	
	}

	Point prev = nexts[0];
	Point last = nexts[1];
	Point temp;

	if (is_section_intersected(third, last, start, prev, temp)) {
		this->A = start;
		this->B = second;
		this->C = third;
		this->D = prev;
		this->E = last;
	} else {
		this->A = start;
		this->B = second;
		this->C = third;
		this->D = last;
		this->E = prev;
	}

}

void ConvexPentagon::println() {
	std::cout << A << " " << B << " " << C << " " << D << " " << E << std::endl;
}

double ConvexPentagon::area() {
	Triangle ABC(A, B, C), ACD(A, C, D), AED(A, E, D);
	return ABC.area() + ACD.area() + AED.area();
}

ConvexHexagon::ConvexHexagon(): A(2, 0), B(4, 0), C(6, 2), D(4, 4), E(2, 4), F(0, 2) {}

ConvexHexagon::ConvexHexagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6) {
    Point start = p1;

    // потенциальный порядок вершин обхода
    std::vector<Point> nexts = {p2, p3, p4, p5, p6};

    Point second;
    for (auto it = nexts.begin(); it != nexts.end(); ++it) {
        Point next = *it;
        Line line(start, next);
        LPP data[4];
        size_t i = 0;
        for (auto p: nexts)
            if (p != next)
                data[i++] = line.where_point(p);

        if (data[0] == data[1] && data[1] == data[2] && data[2] == data[3]) {
            second = next;
            nexts.erase(it);
            break;
        }

    }

    Point third;
    for (auto it = nexts.begin(); it != nexts.end(); ++it) {
        Point next = *it;
        Line line(second, next);
        LPP data[3];
        size_t i = 0;
        for (auto p: nexts)
            if (p != next)
                data[i++] = line.where_point(p);

        if (data[0] == data[1] && data[1] == data[2]) {
            third = next;
            nexts.erase(it);
            break;
        }

    }

    Point fourth;
    for (auto it = nexts.begin(); it != nexts.end(); ++it) {
        Point next = *it;
        Line line(third, next);
        LPP data[4];
        data[0] = line.where_point(start);
        data[1] = line.where_point(second);
        size_t i = 2;
        for (auto p: nexts)
            if (p != next)
                data[i++] = line.where_point(p);

        if (data[0] == data[1] && data[1] == data[2] && data[2] == data[3]) {
            fourth = next;
            nexts.erase(it);
            break;
        }

    }

    Point prev = nexts[0];
    Point last = nexts[1];
    Point temp;

    if (is_section_intersected(fourth, last, start, prev, temp)) {
        this->A = start;
        this->B = second;
        this->C = third;
        this->D = fourth;
        this->E = prev;
        this->F = last;
    } else {
        this->A = start;
        this->B = second;
        this->C = third;
        this->D = fourth;
        this->E = last;
        this->F = prev;
    }
}

void ConvexHexagon::println() {
    std::cout << A << '\n' << B << '\n' << C << '\n' << D << '\n' << E << '\n' << F << std::endl;
}

double ConvexHexagon::area() {
    Triangle ABC(A, B, C), FAC(F, A, C), FCD(F, C, D), FED(F, E, D);
    return ABC.area() + FAC.area() + FCD.area() + FED.area();
}