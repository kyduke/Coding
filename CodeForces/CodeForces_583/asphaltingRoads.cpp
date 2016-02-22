// http://codeforces.com/problemset/problem/583/A

#include <iostream>

using namespace std;

const int SIZE = 50;

int horizontal[SIZE];
int vertical[SIZE];

int main(int argc, char* argv[]) {
	int i, n, h, v;

	cin >> n;
	
	i = 0;
	n = n * n;
	while (i < n) {
		i++;
		cin >> h >> v;
		if (horizontal[h - 1] == 0 && vertical[v - 1] == 0) {
			horizontal[h - 1] = 1;
			vertical[v - 1] = 1;
			cout << i << " ";
		}
	}
	cout << "\n";

	return 0;
}

/*
2
1 1
1 2
2 1
2 2
=====
1 4 
1
1 1
=====
1 
*/
