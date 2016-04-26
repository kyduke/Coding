// Google Code Jam Round 1A 2016 Problem B. Rank and File

#include <iostream>
#include <map>

using namespace std;

const int SIZE = 2500;

int data[SIZE * SIZE * 2];

void solve(int n) {
	map<int, int> m;
	map<int, int>::iterator it;
	int i, l;

	l = n * (n * 2 - 1);
	for (i = 0; i < l; i++) {
		m[data[i]]++;
	}

	for (it = m.begin(); it != m.end(); it++) {
		if (it->second % 2 == 1) {
			cout << it->first << " ";
		}
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int T, n, t, i, l;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> n;
		l = n * (n * 2 - 1);
		for (i = 0; i < l; i++) {
			cin >> data[i];
		}

		t++;
		cout << "Case #" << t << ": ";
		solve(n);
	}

	return 0;
}

/*
1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
=====
Case #1: 3 4 6
*/
