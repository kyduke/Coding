// https://www.hackerrank.com/contests/hourrank-4/challenges/new-year-party

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int n, i, t;

	i = 0;

	cin >> n;
	while (n--) {
		cin >> t;
		i++;
		if (i < t) i = t;
	}

	cout << i << "\n";

	return 0;
}

/*
8
2 2 2 2 4 4 4 6 
=====
9

3
2000 2015 2015
=====
2016
*/
