// https://algospot.com/judge/problem/read/STRJOIN

#include <iostream>
#include <queue>

using namespace std;

int solve(priority_queue<int, vector<int>, greater<int>>& q) {
	int result;
	int a, b;

	result = 0;
	while (q.size() > 1) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		q.push(a + b);
		result += a + b;
	}
	q.pop();

	return result;
}

int main(int argc, char* argv[]) {
	priority_queue<int, vector<int>, greater<int>> q;
	int c, n, t;

	cin >> c;
	while (c--) {
		cin >> n;
		while (n--) {
			cin >> t;
			q.push(t);
		}

		cout << solve(q) << "\n";
	}

	return 0;
}

/*
3
3
2 2 4
5
3 1 3 4 1
8
1 1 1 1 1 1 1 2
=====
12
26
27
*/
