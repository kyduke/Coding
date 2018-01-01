// https://www.hackerrank.com/contests/w9/challenges/lexicographic-steps

#include <iostream>

using namespace std;

const int SIZE = 11;

int cache[SIZE][SIZE];

int calc(int h, int r) {
	int ans, i;

	if (cache[h][r] > 0) return cache[h][r];

	if (h == 1) {
		cache[h][r] = r;
		return cache[h][r];
	}

	ans = 0;
	for (i = 1; i <= r; i++) {
		ans += calc(h - 1, i);
	}

	cache[h][r] = ans;

	return ans;
}

void solve(int x, int y, int k) {
	int z;

	while (x + y > 0) {
		if (x == 0) {
			y--;
			printf("V");
		} else if (y == 0) {
			x--;
			printf("H");
		} else {
			z = cache[x - 1][y + 1];
			if (k <= z) {
				x--;
				printf("H");
			} else {
				y--;
				printf("V");
				k -= z;
			}
		}
	}
	printf("\n");
}

int main(int argc, char* argv[]) {
	int t, i, k, x, y, z;

	for (i = 0; i <= 10; i++) {
		cache[0][i] = 1;
		cache[i][0] = 1;
	}

	calc(10, 10);

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &x, &y, &k);
		solve(x, y, k + 1);
	}

	return 0;
}

/*
2
2 2 2
2 2 3
=====
HVVH
VHHV
*/
