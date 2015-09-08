// http://codeforces.com/problemset/problem/574/A

#include <iostream>
#include <queue>

using namespace std;

int solve(priority_queue<int>& votes, int m) {
	int count, n;

	count = 0;
	while (votes.size() > 0) {
		n = votes.top();
		votes.pop();

		if (n < m) break;

		votes.push(--n);

		m++;
		count++;
	}

	return count;
}

int main(int argc, char* argv[]) {
	priority_queue<int> votes;
	int n, m, a;

	cin >> n;
	cin >> m;
	n--;
	while (n--) {
		cin >> a;
		votes.push(a);
	}

	cout << solve(votes, m) << "\n";

	return 0;
}

/*
5
5 1 11 2 8
=====
4

4
1 8 8 8
=====
6

2
7 6
=====
0
*/
