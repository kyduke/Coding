// https://algospot.com/judge/problem/read/JOSEPHUS

#include <iostream>

using namespace std;

const int SIZE = 1000;

int persons[SIZE];

void solve(int n, int k) {
	int i, remains, move;

	for (i = 1; i < n; i++) {
		persons[i] = 1;
	}

	i = 0;
	remains = n - 1;
	while (remains > 2) {
		move = k % remains;
		if (move == 0) move = remains;
		while (move) {
			i = (i + 1) % n;
			move -= persons[i];
		}
		persons[i] = 0;
		remains--;
	}

	for (i = 1; i < n; i++) {
		if (persons[i]) cout << (i + 1) << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int C, N, K;

	cin >> C;
	while (C--) {
		cin >> N >> K;
		solve(N, K);
	}

	return 0;
}

/*
2
6 3
40 3
=====
3 5
11 26
*/
