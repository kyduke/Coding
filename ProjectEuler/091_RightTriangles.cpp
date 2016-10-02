// https://projecteuler.net/problem=91

#include <iostream>

using namespace std;

const int LIMIT = 50;

bool isRightTriangle(int* triangles) {
	int ax, ay, bx, by;

	if ((triangles[0] == triangles[2]) && (triangles[1] == triangles[3])) return false;
	if ((triangles[0] == triangles[4]) && (triangles[1] == triangles[5])) return false;
	if ((triangles[2] == triangles[4]) && (triangles[3] == triangles[5])) return false;

	ax = triangles[2] - triangles[0];
	ay = triangles[3] - triangles[1];
	bx = triangles[4] - triangles[0];
	by = triangles[5] - triangles[1];

	if ((ax * bx) + (ay * by) == 0) return true;

	ax = triangles[0] - triangles[2];
	ay = triangles[1] - triangles[3];
	bx = triangles[4] - triangles[2];
	by = triangles[5] - triangles[3];

	if ((ax * bx) + (ay * by) == 0) return true;

	ax = triangles[0] - triangles[4];
	ay = triangles[1] - triangles[5];
	bx = triangles[2] - triangles[4];
	by = triangles[3] - triangles[5];

	if ((ax * bx) + (ay * by) == 0) return true;

	return false;
}

int main(int argc, char* argv[]) {
	int i, j, x, y, s;
	int triangles[6];
	int count;

	count = 0;
	triangles[0] = 0;
	triangles[1] = 0;
	for (j = 0; j <= LIMIT; j++) {
		triangles[3] = j;
		for (i = 0; i <= LIMIT; i++) {
			triangles[2] = i;
			for (y = j; y <= LIMIT; y++) {
				triangles[5] = y;
				if (y == j) {
					s = i + 1;
				} else {
					s = 0;
				}
				for (x = s; x <= LIMIT; x++) {
					triangles[4] = x;
					if (isRightTriangle(triangles) == true) count++;
				}
			}
		}
	}

	cout << count << "\n";

	return 0;
}
