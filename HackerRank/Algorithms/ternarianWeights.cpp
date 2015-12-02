// https://www.hackerrank.com/contests/round-1-holiday-cup/challenges/ternarian-weights

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long INT64;

struct Node {
	INT64 n;
	INT64 s;
	int t;
	bool next;
};

vector<INT64> lefts, rights;

void solve(INT64 n) {
	stack<Node> q;
	Node node;
	INT64 s;
	bool found;

	s = 1;
	while (s < n) {
		s *= 3;
	}

	if (s == n) {
		rights.push_back(n);
		return;
	}

	node.n = n;
	node.s = s;
	node.t = -1;
	node.next = false;

	q.push(node);

	found = false;
	while (!q.empty()) {
		node = q.top();
		q.pop();
		if (found == true) {
			if (node.t == -1) {
				rights.push_back(node.s);
			} else if (node.t == 1) {
				lefts.push_back(node.s);
			}
			continue;
		}

		if (node.n == 0) {
			found = true;
			continue;
		}
		if (node.s == 0) continue;

		s = node.n;
		if (node.n < 0) s = -node.n;
		if (s / node.s > 1) continue;

		if (node.next == false) {
			node.next = true;
			q.push(node);
			node.n = node.n + node.t * node.s;
			node.s /= 3;
			node.t = -1;
			node.next = false;
			q.push(node);
		} else {
			node.t++;
			if (node.t <= 1) {
				node.next = false;
				q.push(node);
			}
		}
	}
}

void printResult() {
	int i;

	cout << "left pan: ";
	for (i = lefts.size() - 1; i >= 0; i--) {
		cout << lefts[i] << " ";
	}
	cout << "\n";

	cout << "right pan: ";
	for (i = rights.size() - 1; i >= 0; i--) {
		cout << rights[i] << " ";
	}
	cout << "\n";
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int n;
	INT64 x;

	cin >> n;
	while (n--) {
		cin >> x;
		lefts.clear();
		rights.clear();
		solve(x);
		printResult();
	}

	return 0;
}

/*
4
2
3
21
250
=====
left pan: 1
right pan: 3

left pan:
right pan: 3

left pan: 9
right pan: 27 3

left pan: 3
right pan: 243 9 1
*/
