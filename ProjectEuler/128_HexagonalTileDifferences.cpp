// https://projecteuler.net/problem=128

#include <iostream>
#include <set>

using namespace std;

const int SIZE = 101;

int map[SIZE][SIZE] = {0, };
int primes[SIZE * SIZE + 1] = {1, 1, 0, };
set<int> result;

void printMap() {
	int i, j;

	for (j = 0; j < SIZE; j++) {
		for (i = 0; i < SIZE; i++) {
			printf("%3d ", map[j][i]);
		}
		cout << "\n";
	}
}

void fillPrimes() {
	int i, j;

	for (i = 2; i < SIZE * SIZE + 1; i++) {
		if (primes[i] == 0) {
			for (j = i + i; j < SIZE * SIZE + 1; j += i) {
				primes[j] = 1;
			}
		}
	}

	for (i = 0; i < SIZE * SIZE + 1; i++) {
		primes[i] = !primes[i];
	}
}

void fillMap() {
	int x, y;

	x = SIZE / 2;
	y = SIZE / 2;

	x = SIZE / 2;
	y = SIZE / 2;

	map[y][x - 2] = 12;
	map[y][x - 1] = 4;
	map[y][x    ] = 1;
	map[y][x + 1] = 7;
	map[y][x + 2] = 18;

	for (x = SIZE / 2 - 3; x >= 0; x--) {
		map[y][x] = map[y][x + 1] + map[y][x + 1] - map[y][x + 2] + 6;
	}

	for (x = SIZE / 2 + 3; x < SIZE; x++) {
		map[y][x] = map[y][x - 1] + map[y][x - 1] - map[y][x - 2] + 6;
	}

	for (x = 0; x < SIZE / 2; x++) {
		for (y = SIZE / 2 - 1; y >= x; y--) {
			map[y][x] = map[y + 1][x] - 1;
		}
	}

	for (x = SIZE / 2 + 1; x < SIZE; x++) {
		for (y = SIZE / 2 + 1; y <= x; y++) {
			map[y][x] = map[y - 1][x] - 1;
		}
	}

	for (y = 0; y < SIZE / 2; y++) {
		for (x = y + 1; x <= SIZE / 2; x++) {
			map[y][x] = map[y][x - 1] - 1;
		}
	}

	for (y = SIZE / 2 + 1; y < SIZE; y++) {
		for (x = y - 1; x >= SIZE / 2; x--) {
			map[y][x] = map[y][x + 1] - 1;
		}
	}

	for (y = SIZE / 2 - 1; y > 0; y--) {
		for (x = y + SIZE / 2; x > SIZE / 2; x--) {
			map[y][x] = map[y + 1][x + 1] + 1;
		}
	}

	for (y = SIZE / 2 + 1; y < SIZE; y++) {
		for (x = y - SIZE / 2; x < SIZE / 2; x++) {
			map[y][x] = map[y - 1][x - 1] + 1;
		}
	}
}

void findPD3() {
	int x, y, d, p;

	primes[0] = 100;

	for (y = 1; y < SIZE - 1; y++) {
		for (x = 1; x < SIZE - 1; x++) {
			p = 0;
			d = map[y - 1][x    ] - map[y    ][x    ];
			if (d < 0) d *= -1;
			p += primes[d];

			d = map[y - 1][x - 1] - map[y    ][x    ];
			if (d < 0) d *= -1;
			p += primes[d];

			d = map[y    ][x - 1] - map[y    ][x    ];
			if (d < 0) d *= -1;
			p += primes[d];

			d = map[y + 1][x    ] - map[y    ][x    ];
			if (d < 0) d *= -1;
			p += primes[d];

			d = map[y + 1][x + 1] - map[y    ][x    ];
			if (d < 0) d *= -1;
			p += primes[d];

			d = map[y    ][x + 1] - map[y    ][x    ];
			if (d < 0) d *= -1;
			p += primes[d];

			if (p == 3) result.insert(map[y][x]);
		}
	}

	primes[0] = 1;
}

int main(int argc, char* argv[]) {
	set<int>::iterator it;
	int i;

	fillPrimes();
	fillMap();
	findPD3();

	i = 0;
	for (it = result.begin(); it != result.end(); it++) {
		i++;
		if (i == 10) {
			cout << *it << "\n";
			break;
		}
	}

	return 0;
}
