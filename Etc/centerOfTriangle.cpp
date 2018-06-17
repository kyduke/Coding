#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPSILON = 1.0e-6;

struct Point {
	double x;
	double y;
};

double squareDistance(vector<Point>& points, Point p) {
	double dist, x, y;
	int i;

	dist = 0.0;
	for (i = 0; i < points.size(); i++) {
		x = points[i].x - p.x;
		y = points[i].y - p.y;
		dist += x * x + y * y;
	}

	return dist;
}

void solve(vector<Point>& points) {
	Point p, q;
	double dist, e, temp, x, y;
	int i;
	bool flag;

	if (points.size() < 2) return;

	p.x = points[0].x;
	p.y = points[0].y;
	e = sqrt(squareDistance(points, points[0]));
	while (e > EPSILON) {
		flag = true;
		dist = squareDistance(points, p);

		q.x = p.x - e;
		q.y = p.y;
		temp = squareDistance(points, q);
		if (temp < dist) {
			flag = false;
			dist = temp;
			x = q.x;
			y = q.y;
		}

		q.x = p.x + e;
		q.y = p.y;
		temp = squareDistance(points, q);
		if (temp < dist) {
			flag = false;
			dist = temp;
			x = q.x;
			y = q.y;
		}

		q.x = p.x;
		q.y = p.y - e;
		temp = squareDistance(points, q);
		if (temp < dist) {
			flag = false;
			dist = temp;
			x = q.x;
			y = q.y;
		}

		q.x = p.x;
		q.y = p.y + e;
		temp = squareDistance(points, q);
		if (temp < dist) {
			flag = false;
			dist = temp;
			x = q.x;
			y = q.y;
		}

		if (flag == true) {
			e /= 2.0;
		} else {
			p.x = x;
			p.y = y;
		}

		printf("%.5f, %.5f (%.7f)\n", p.x, p.y, e);
	}

	printf("Center: %.5f, %.5f\n", p.x, p.y);
}

void mathCenter(vector<Point>& points) {
	double x, y;
	int i;

	if (points.size() == 0) return;

	x = 0.0;
	y = 0.0;
	for (i = 0; i < points.size(); i++) {
		x += points[i].x;
		y += points[i].y;
	}

	printf("Math center: %.5f, %.5f\n", x / (double)points.size(), y / (double)points.size());
}

int main(int argc, char** argv) {
	vector<Point> triangle;
	Point p;

	p.x = 0.0;
	p.y = 0.0;
	triangle.push_back(p);
	p.x = 10.0;
	p.y = 0.0;
	triangle.push_back(p);
	p.x = 3.0;
	p.y = 7.0;
	triangle.push_back(p);

	solve(triangle);
	mathCenter(triangle);

	return 0;
}
