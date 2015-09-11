//http://www.careercup.com/question?id=5673229274316800

#include <iostream>
#include <cmath>

using namespace std;

void print3Points(int x, int y, int w, int h) {
	int i, j, a, b;

	for (i = 0; i < 2; i++) {
		if (i == 0) {
			a = w;
		} else {
			a = -w;
		}
		for (j = 0; j < 2; j++) {
			if (j == 0) {
				b = h;
			} else {
				b = -h;
			}
			cout << "(" << x << "," << y + b << "),";
			cout << "(" << x + a << "," << y << "),";
			cout << "(" << x + a << "," << y + b << ")\n";
		}
	}
}

void findPermutaions(int x, int y, int area) {
	int i, j, r;

	r = (int)sqrt((double)area);
	for (i = 1; i <= r; i++) {
		if (area % i == 0) {
			j = area / i;
			print3Points(x, y, i, j);
			if (i != j) {
				print3Points(x, y, j, i);
			}
		}
	}
}

int main(int argc, char* argv[]) {
	findPermutaions(0, 0, 20);

	return 0;
}
