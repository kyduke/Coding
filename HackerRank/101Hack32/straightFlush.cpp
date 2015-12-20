// https://www.hackerrank.com/contests/101hack32/challenges/straight-flush

#include <iostream>

using namespace std;

int charToCardIndex(char a) {
	int i;

	i = 0;
	switch (a) {
		case 'A': i = 0; break;
		case '2': i = 1; break;
		case '3': i = 2; break;
		case '4': i = 3; break;
		case '5': i = 4; break;
		case '6': i = 5; break;
		case '7': i = 6; break;
		case '8': i = 7; break;
		case '9': i = 8; break;
		case 'T': i = 9; break;
		case 'J': i = 10; break;
		case 'Q': i = 11; break;
		case 'K': i = 12; break;
	}

	return i;
}

int main(int argc, char* argv[]) {
	int cards[14] = {0, };
	char buffer[3];
	char type;
	bool same;
	int i, sum;

	same = true;
	cin >> buffer;
	i = charToCardIndex(buffer[0]);
	type = buffer[1];
	cards[i] = 1;
	if (i == 0) cards[13] = 1;

	cin >> buffer;
	if (type != buffer[1]) same = false;
	if (same) {
		i = charToCardIndex(buffer[0]);
		cards[i] = 1;
		if (i == 0) cards[13] = 1;
	}

	cin >> buffer;
	if (type != buffer[1]) same = false;
	if (same) {
		i = charToCardIndex(buffer[0]);
		cards[i] = 1;
		if (i == 0) cards[13] = 1;
	}

	cin >> buffer;
	if (type != buffer[1]) same = false;
	if (same) {
		i = charToCardIndex(buffer[0]);
		cards[i] = 1;
		if (i == 0) cards[13] = 1;
	}

	cin >> buffer;
	if (type != buffer[1]) same = false;
	if (same) {
		i = charToCardIndex(buffer[0]);
		cards[i] = 1;
		if (i == 0) cards[13] = 1;
	}

	sum = 0;
	if (same) {
		for (i = 0; i < 14; i++) {
			if (sum == 5) break;
			if (cards[i] == 0) sum = 0;
			sum += cards[i];
		}
	}
	if (sum == 5) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}

/*
3C
4C
6C
7C
5C
=====
YES

3C
4H
6C
7C
5C
=====
NO

AC
2C
3C
4C
5C
=====
YES
*/
