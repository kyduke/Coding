// https://projecteuler.net/problem=126
// http://www.mathblog.dk/project-euler-126-cubes-cover-cuboid/

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 500;

int covers[SIZE];
int coversByMathblog[30001];

vector<int> cuboidLayers(int a, int b, int c) {
	vector<int> shells;
	vector<int> centerLayers;
	vector<int> cells;
	int i, n, t, p, s;

	i = 0;
	p = 0;
	t = 0;
	while (true) {
		n = (a * b) - ((i * (i + 1) / 2) * 4);
		centerLayers.push_back(n);
		cells.push_back(n * c + p);

		s = n * c + p - t;
		if (s >= SIZE) break;

		shells.push_back(s);

		t = n * c + p;
		p += n + n;

		a += 2;
		b += 2;
		i++;
	}

	return shells;
}

void solve() {
	int a, b, c, k, n;
	vector<int> shells;

	c = 1;
	for (a = 1; a < SIZE; a++) {
		for (b = 1; b <= a; b++) {
			for (c = 1; c <= b; c++) {
				shells = cuboidLayers(a, b, c);
				for (k = 1; k < shells.size(); k++) {
					n = shells[k];
					if (n >= SIZE) break;
					covers[n]++;
				}
			}
		}
	}

	cout << covers[22] << "\n";
	cout << covers[46] << "\n";
	cout << covers[78] << "\n";
	cout << covers[118] << "\n";
	cout << covers[154] << "\n";

	for (k = 0; k < SIZE; k++) {
		if (covers[k] == 10) {
			cout << k << "\n";
			break;
		}
	}
}

int cubesByMathblog(int x, int y, int z, int n) {
    return 2 * (x * y + y * z + x * z ) + 4 * (x + y + z + n - 2) * (n - 1);
}

void solveByMathblog() {
	int x, y, z, n, limit, k;

	limit = 30000;
	for (z = 1; cubesByMathblog(z, z, z, 1) <= limit; z++) {
		for (y = z; cubesByMathblog(z, y, z, 1) <= limit; y++) {
			for (x = y; cubesByMathblog(z, y, x, 1) <= limit; x++) {
				for (n = 1; cubesByMathblog(z, y, x, n) <= limit; n++) {
					coversByMathblog[cubesByMathblog(z, y, x, n)]++;
				}
			}
		}
	}

	for (k = 0; k < limit; k++) {
		if (coversByMathblog[k] == 1000) {
			cout << k << "\n";
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	solve();
	solveByMathblog();
	return 0;
}
