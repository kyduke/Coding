// https://www.hackerrank.com/contests/hourrank-3/challenges/contest-performance

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int a[5], score;

	cin >> a[0];
	cin >> a[1];
	cin >> a[2];
	cin >> a[3];
	cin >> a[4];

	score = 0;
	if (a[0] < 11) score += (11 - a[0]) * 10;
	if (a[1] < 12) score += (12 - a[1]) * 10;
	if (a[2] < 13) score += (13 - a[2]) * 10;
	if (a[3] < 14) score += (14 - a[3]) * 10;
	if (a[4] < 15) score += (15 - a[4]) * 10;

	cout << score << "\n";

	return 0;
}

/*
1 2 5 4 5
=====
480
*/
