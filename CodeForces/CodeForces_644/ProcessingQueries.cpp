// http://codeforces.com/contest/644/problem/B

#include <iostream>
#include <queue>

typedef unsigned long long UINT64;

using namespace std;

int main(int argc, char* argv[]) {
	queue<UINT64> q;
	UINT64 a;
	int n, b, t, d;

	a = 0;
	cin >> n >> b;

	n--;
	cin >> t >> d;
	a = t + d;
	cout << a << " ";
	q.push(a);

	while (n--) {
		cin >> t >> d;

		while (!q.empty()) {
			if (q.front() > t) break;
			q.pop();
		}

		if (q.size() > b) {
			cout << "-1 ";
		} else {
			a += d;
			cout << a << " ";
			q.push(a);
		}
	}
	cout << "\n";

	return 0;
}

/*
5 1
2 9
4 8
10 9
15 2
19 1
=====
11 19 -1 21 22

4 1
2 8
4 8
10 9
15 2
=====
10 18 27 -1 
*/
