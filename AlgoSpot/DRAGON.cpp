// https://algospot.com/judge/problem/read/DRAGON

#include <iostream>

using namespace std;

char str[51];

void fillCharacter(int start, int interval, char character, int offset, int length) {
	start = start + offset - (offset % interval);
	if (start < offset) start += interval;
	length += offset;
	while (start < length) {
		str[start - offset] = character;
		start += interval;
	}
}

int main(int argc, char* argv[]) {
	int c, n, p, l;
	int ms, mi;

	cin >> c;
	while (c--) {
		cin >> n >> p >> l;
		fillCharacter(0, 3, '+', p, l);
		ms = 9;
		mi = 12;
		while (n-- && ms <= p + l) {
			fillCharacter(ms, mi, '-', p, l);
			ms *= 2;
			mi *= 2;
		}
		fillCharacter(1, 6, 'F', p, l);
		fillCharacter(2, 6, 'X', p, l);
		fillCharacter(4, 6, 'Y', p, l);
		fillCharacter(5, 6, 'F', p, l);
		str[l] = '\0';
		cout << str << "\n";
	}

	return 0;
}

/*
4
0 1 2
1 1 5
2 6 5
42 764853475 30
=====
FX
FX+YF
+FX-Y
FX-YF-FX+YF+FX-YF-FX+YF-FX-YF-
*/
