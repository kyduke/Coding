//http://codeforces.com/contest/549/problem/A

#include <iostream>

using namespace std;

int getFaceValue(char c) {
	switch (c) {
		case 'f':
			return 1;
			break;
		case 'a':
			return 2;
			break;
		case 'c':
			return 4;
			break;
		case 'e':
			return 8;
			break;
	}

	return -1;
}

int findFace(char image[51][51], int n, int m) {
	int i, j, w, h, ret;
	char c, face;

	h = n - 1;
	w = m - 1;
	ret = 0;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			c = image[i][j];
			if (c == 0) {
				continue;
			}
			face = c;

			c = image[i][j + 1];
			if (c == 0) {
				continue;
			}
			face += c;

			c = image[i + 1][j];
			if (c == 0) {
				continue;
			}
			face += c;

			c = image[i + 1][j + 1];
			if (c == 0) {
				continue;
			}
			face += c;

			if (face == 15) {
				ret++;
			}
		}
	}
	return ret;
}

int main(int argc, char* argv[]) {
	int n, m, i, j;
	char image[51][51], t;

	cin >> n >> m;

	i = 0;
	while (i < n) {
		j = 0;
		while (j < m) {
			cin >> t;
			switch (t) {
				case 'f':
					t = 1;
					break;
				case 'a':
					t = 2;
					break;
				case 'c':
					t = 4;
					break;
				case 'e':
					t = 8;
					break;
				default:
					t = 0;
			}
			image[i][j] = t;
			j++;
		}
		i++;
	}

	cout << findFace(image, n, m) << "\n";

	return 0;
}

/*
4 4
xxxx
xfax
xcex
xxxx
=====
1

4 2
xx
cf
ae
xx
=====
1

2 3
fac
cef
=====
2

1 4
face
=====
0
*/
