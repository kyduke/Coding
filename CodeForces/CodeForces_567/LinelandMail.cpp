// http://codeforces.com/problemset/problem/567/A

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int cities[100000];
	int n, i, x;
	int minCity, maxCity;

	cin >> n;
	i = 0;
	while (i < n) {
		cin >> cities[i++];
	}

	minCity = cities[0];
	maxCity = cities[n - 1];

	cout << (cities[1] - cities[0]) << " " << (maxCity - cities[0]) << "\n";

	for (i = 1; i < n - 1; i++) {
		cout << min((cities[i] - cities[i - 1]), (cities[i + 1] - cities[i])) << " ";
		cout << max((cities[i] - minCity), (maxCity - cities[i])) << "\n";
	}

	cout << (cities[n - 1] - cities[n - 2]) << " " << (cities[n - 1] - minCity) << "\n";

	return 0;
}

/*
4
-5 -2 2 7
=====
3 12
3 9
4 7
5 12

2
-1 1
=====
2 2
2 2
*/
