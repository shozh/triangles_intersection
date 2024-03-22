#include "polygon.h"
#include "point.h"
#include "line.h"
#include "vector.h"
#include "triangle.h"
#include "addition.h"
#include "triangle_intersect.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>

// enum class SE {on, non_end_intersected, end_intersected, non};

seg::seg(): A(0, 0), B(1, 1) {}
seg::seg(Point A, Point B): A(A), B(B) {}

// struct comparePoints {
// 	bool operator()(const Point & a, const Point & b) {
// 		return ( a.x<b.x && a.y<b.y );
// 	}
// };

namespace std {
	template <>
	struct hash<Point> {
		size_t operator()(const Point& p) const {
			size_t h1 = std::hash<double>()(p.x);
			size_t h2 = std::hash<double>()(p.y);
			return h1 ^ (h2 << 1); // Простое комбинирование хэшей для Point
		}
	};
}


bool intersect(Triangle T, Triangle Y) {
	if (T.A == Y.A && T.B == Y.B && T.C == Y.C) {
		std::cout << "Треугольники совпадают" << std::endl;
		return true;
	}

	seg S1 = seg(T.A, T.B), S2 = seg(T.B, T.C), S3 = seg(T.C, T.A);
	seg W1 = seg(Y.A, Y.B), W2 = seg(Y.B, Y.C), W3 = seg(Y.C, Y.A);

	std::unordered_set<Point> main_points;

	std::vector<seg> Ts = {S1, S2, S3};
	std::vector<seg> Ys = {W1, W2, W3};

	for (seg S: Ts) {
		for (seg W: Ys) {
			if (is_point_between(S.A, S.B, W.A) && is_point_between(S.A, S.B, W.B)) {
				main_points.insert(W.A);
				main_points.insert(W.B);
			}
			else if (is_point_between(W.A, W.B, S.A) && is_point_between(W.A, W.B, S.B)) {
				main_points.insert(S.A);
				main_points.insert(S.B);
			}
			else if (collinear(W.B - W.A, S.B - S.A) != VC::non) {
				if (is_point_between(S.A, S.B, W.A))
					main_points.insert(W.A);
				if (is_point_between(S.A, S.B, W.B))
					main_points.insert(W.B);
				if (is_point_between(W.A, W.B, S.A))
					main_points.insert(S.A);
				if (is_point_between(W.A, W.B, S.B))
					main_points.insert(S.B);
			}
			else {
				Point intersection_point;
				if (is_section_intersected(S.A, S.B, W.A, W.B, intersection_point))
					main_points.insert(intersection_point);
			}
		}
	}
	
	std::vector<Point> Tp = {T.A, T.B, T.C};
	std::vector<Point> Yp = {Y.A, Y.B, Y.C};

	for (Point p: Tp) {
		if (Y.where_point(p) != TPP::outside)
			main_points.insert(p);
	}
	
	for (Point p: Yp) {
		if (T.where_point(p) != TPP::outside)
			main_points.insert(p);
	}

	if (main_points.size() == 0) {
		std::cout << "Треугольники не пересекаются!" << std::endl;
		return false;
	}

	if (main_points.size() == 1) {
		std::cout << "Треугольники пересекаются только в одной точке: " << *main_points.begin() << std::endl;
        return true;
	}

    if (main_points.size() == 2) {
        auto it = main_points.begin();
        auto elem1 = *it;
        it++;
        auto elem2 = *it;
        std::cout << "Треугольники пересекаются только по отрезку, концы которого равны: " << elem1 << "; " << elem2 << std::endl;
        return true;
    }

    if (main_points.size() == 3) {
        auto it = main_points.begin();
        auto p1 = *it;
        it++;
        auto p2 = *it;
        it++;
        auto p3 = *it;
        Triangle t(p1, p2, p3);
        std::cout << "Треугольники пересекаются и в пересечении получается треугольник с точками: " << p1 << "; " << p2 << "; " << p3 << std::endl;
        std::cout << "Площадь пересечения равна: " << t.area() << std::endl;
        return true;

    }

    if (main_points.size() == 4) {
        auto it = main_points.begin();
        auto p1 = *it;
        it++;
        auto p2 = *it;
        it++;
        auto p3 = *it;
        it++;
        auto p4 = *it;

        ConvexQuadrilateral cq(p1, p2, p3, p4);

        std::cout << "Треугольники пересекаются и в пересечении получается выпуклый четырёхугольник" << std::endl;
        std::cout << "Точки четырёхугольника равны: " << p1 << "; " << p2 << "; " << p3 << "; " << p4 << std::endl;
        std::cout << "Площадь пересечения равна: " << cq.area() << std::endl;

    }

    if (main_points.size() == 5) {
        auto it = main_points.begin();
        auto p1 = *it;
        it++;
        auto p2 = *it;
        it++;
        auto p3 = *it;
        it++;
        auto p4 = *it;
        it++;
        auto p5 = *it;

        ConvexPentagon cp(p1, p2, p3, p4, p5);

        std::cout << "Треугольники пересекаются и в пересечении получается выпуклый пятиугольник" << std::endl;
        std::cout << "Точки пятиугольника равны: " << p1 << "; " << p2 << "; " << p3 << "; " << p4 << "; " << p5 << std::endl;
        std::cout << "Площадь пересечения равна: " << cp.area() << std::endl;

    }

    if (main_points.size() == 6) {
        auto it = main_points.begin();
        auto p1 = *it;
        it++;
        auto p2 = *it;
        it++;
        auto p3 = *it;
        it++;
        auto p4 = *it;
        it++;
        auto p5 = *it;
        it++;
        auto p6 = *it;

        ConvexHexagon ch(p1, p2, p3, p4, p5, p6);

        std::cout << "Треугольники пересекаются и в пересечении получается выпуклый шестиугольник" << std::endl;
        std::cout << "Точки шестиугольника равны: " << p1 << "; " << p2 << "; " << p3 << "; " << p4 << "; " << p5 << "; " << p6 << std::endl;
        std::cout << "Площадь пересечения равна: " << ch.area() << std::endl;

    }

	return true;

}