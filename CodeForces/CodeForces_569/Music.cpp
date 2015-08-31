// http://codeforces.com/problemset/problem/569/A

#include <iostream>
#include <cmath>

using namespace std;

int howManyTimes(int t, int s, int q) {
	double length, downloadSpeed, downloadTime;
	int count;

	length = (double)s;
	downloadSpeed = (double)(q - 1.0) / q;

	count = 0;
	while (s < t) {
		downloadTime = length / (1.0 - downloadSpeed);
		length += downloadSpeed * downloadTime;
		s = length + 0.00000000001;
		count++;
	}

	return count;
}

int main(int argc, char* argv[]) {
	int T, S, q;

	cin >> T >> S >> q;
	cout << howManyTimes(T, S, q) << "\n";

	return 0;
}

/*
5 2 2
=====
2

5 4 7
=====
1

6 2 3
=====
1
*/
