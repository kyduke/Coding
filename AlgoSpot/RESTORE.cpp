// https://www.algospot.com/judge/problem/read/RESTORE

#include <iostream>
#include <string.h>

using namespace std;

int k, x;
char str[15][41];
int ignore[15];
int pprev[15];
int overlap[15][15];
int cache[15][65536];

void calcOverlap() {
	int i, j, n, step, count;
	char* a;
	char* b;
	char buffer[128];

	x = 0;
	memset(ignore, 0, sizeof(int) * 15);
	memset(cache, -1, sizeof(int) * 15 * 65536);

	for (i = 0; i < k; i++) {
		if (ignore[i] == 1) continue;
		overlap[i][i] = strlen(str[i]);
		for (j = 0; j < k; j++) {
			if (ignore[j] == 1 || i == j) continue;
			overlap[i][j] = 0;
			a = str[i]; 
			b = str[j];
			step = 0;
			count = 0;
			while (*a != '\0' && *b != '\0') {
				if (*a == *b) {
					count++;
					a++;
					b++;
				} else {
					count = 0;
					step++;
					a = str[i] + step;
					b = str[j];
				}
			}
			overlap[i][j] = count;
			if (count == strlen(str[j])) {
				x++;
				ignore[j] = 1;
			}
		}
	}
}

int getStringLength(int step, int prev, int pp, int visit) {
	int i, c;

	if (step == (k - x)) return overlap[prev][prev];

	int& ret = cache[prev][visit];

	if (ret != -1) return ret;

	ret = 40 * 15 + 1;
	for (i = 0; i < k; i++) {
		if (ignore[i] == 1 || visit & (1 << i)) continue;
		if (ignore[i] == 2 && pp >= 0 && pprev[i] == pp * 100 + prev) {
			c = overlap[prev][prev] - overlap[i][i] + getStringLength(step + 1, i, prev, visit | (1 << i));
		} else {
			c = overlap[prev][prev] - overlap[prev][i] + getStringLength(step + 1, i, prev, visit | (1 << i));
		}
		ret = min(ret, c);
	}

	return ret;
}

void restoreString(int step, int prev, int visit, int length) {
	int i, c;

	if (step == (k - x)) return;

	for (i = 0; i < k; i++) {
		if (ignore[i] == 1 || visit & (1 << i)) continue;
		c = overlap[prev][prev] - overlap[prev][i] + getStringLength(step + 1, i, prev, visit | (1 << i));
		if (c == length) {
			cout << str[i] + overlap[prev][i];
			return restoreString(step + 1, i, visit | (1 << i), length - (overlap[prev][prev] - overlap[prev][i]));
		}
	}
}

void solve() {
	int i, c;
	int minLength;
	int start;

	calcOverlap();

	start = 0;
	minLength = 40 * 15 + 1;
	for (i = 0; i < k; i++) {
		if (ignore[i] == 1) continue;
		c = getStringLength(1, i, -1, (1 << i));
		if (minLength > c) {
			minLength = c;
			start = i;
		}
	}

	cout << str[start];
	restoreString(1, start, (1 << start), minLength);
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int C;
	int i;

	cin >> C;
	while (C--) {
		cin >> k;
		i = 0;
		while (i < k) {
			cin >> str[i];
			i++;
		}
		solve();
	}

	return 0;
}

/*
3
3
geo
oji
jing
2
world
hello
3
abrac
cadabra
dabr
=====
geojing
helloworld
cadabrac
*/
