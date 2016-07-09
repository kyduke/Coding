// https://algospot.com/judge/problem/read/CHILDRENDAY

#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
	string s;
	int n;
	int r;
};

string solve(string d, int n, int m) {
	set<int> underSet, upperSet;
	set<int>::iterator it;
	queue<Node> q;
	Node node;
	int digits[10];
	int i, digitCount, nodeR, nodeN;
	string nodeS;
	char c;

	sort(d.begin(), d.end());

	digitCount = d.size();
	for (i = 0; i < digitCount; i++) {
		digits[i] = d[i] - '0';
	}

	node.s = "";
	node.n = 0;
	node.r = 0;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();

		nodeS = node.s;
		nodeN = node.n;
		nodeR = node.r;
		if (nodeN == 0) {
			nodeS = "";
		}
		for (i = 0; i < digitCount; i++) {
			c = digits[i] + '0';
			node.s = nodeS + c;
			node.r = (nodeR * 10 + digits[i]) % n;
			if (nodeN < n + m) {
				node.n = nodeN * 10 + digits[i];
			} else {
				node.n = n + m;
			}
			if (node.r == m && node.n >= n + m) {
				return node.s;
			}
			if (node.n < n + m) {
				if (underSet.find(node.r) == underSet.end()) {
					underSet.insert(node.r);
					q.push(node);
				}
			} else {
				if (upperSet.find(node.r) == upperSet.end()) {
					upperSet.insert(node.r);
					q.push(node);
				}
			}
		}
	}

	return "IMPOSSIBLE";
}

int main(int argc, char* argv[]) {
	int T, N, M;
	string D;

	cin >> T;
	while (T--) {
		cin >> D >> N >> M;
		cout << solve(D, N, M) << "\n";
	}

	return 0;
}

/*
5
1 7 0
1 10 1 
0 7 3
345 9997 3333
35 9 8
=====
111111
11
IMPOSSIBLE
35355353545
35
*/
