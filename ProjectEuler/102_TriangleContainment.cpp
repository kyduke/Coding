// https://projecteuler.net/problem=102

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Vector2D {
	int x;
	int y;
};

struct Triangle {
	Vector2D a;
	Vector2D b;
	Vector2D c;
};

int getZElementOfCrossProduct(Vector2D a, Vector2D b) {
	return a.x * b.y - a.y * b.x;
}

bool isContainOrigin(Triangle t) {
	int plus, minus, zero, z;

	plus = 0;
	minus = 0;
	zero = 0;

	z = getZElementOfCrossProduct(t.a, t.b);
	if (z > 0) {
		plus++;
	} else if (z < 0) {
		minus++;
	} else {
		zero++;
	}

	z = getZElementOfCrossProduct(t.b, t.c);
	if (z > 0) {
		plus++;
	} else if (z < 0) {
		minus++;
	} else {
		zero++;
	}

	z = getZElementOfCrossProduct(t.c, t.a);
	if (z > 0) {
		plus++;
	} else if (z < 0) {
		minus++;
	} else {
		zero++;
	}

	if (plus + zero == 3 || minus + zero == 3) return true;

	return false;
}


int main(int argc, char* argv[]) {
	ifstream dataFile;
	char buffer[64];
	vector<int> coords;
	char c;
	Triangle t;
	int i, n, sign;
	int containedTriangles;

	containedTriangles = 0;
	
	dataFile.open("D:/workspace/Coding/ProjectEuler_102_TriangleContainment/102_TriangleContainment.txt");
	while (true) {
		dataFile >> buffer;
		n = 0;
		sign = 1;
		i = 0;
		coords.clear();
		while (true) {
			c = buffer[i];
			if (c == 0) {
				coords.push_back(n * sign);
				break;
			} else if (c == '-') {
				sign = -1;
			} else if (c == ',') {
				coords.push_back(n * sign);
				n = 0;
				sign = 1;
			} else {
				n = n * 10 + (c - '0');
			}
			i++;
		}

		t.a.x = coords[0];
		t.a.y = coords[1];

		t.b.x = coords[2];
		t.b.y = coords[3];

		t.c.x = coords[4];
		t.c.y = coords[5];

		if (isContainOrigin(t) == true) containedTriangles++;

		if (dataFile.eof()) break;
	}
	dataFile.close();

	cout << containedTriangles << "\n";

	return 0;
}
