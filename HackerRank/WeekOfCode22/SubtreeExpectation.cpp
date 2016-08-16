// https://www.hackerrank.com/contests/w22/challenges/subtree-expectation
// pass 3 of 30

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

struct Node {
	int idx;
	UINT64 w;
	vector<int> parents;
	string str;
};

const int SIZE = 500001;

UINT64 weights[202];
int a[SIZE] = {0, };
vector<int> map[202];
int n;
set<string> visit;

string generateString() {
	string str;
	int i;

	str = "";
	for (i = 0; i < n; i++) str += "0";

	return str;
}

double solve() {
	queue<Node> q;
	vector<int> arr;
	Node node;
	UINT64 sum, k, t;
	int count, i, j, r, s, u, v;
	double w;
	string str, str2;

	visit.clear();

	w = 0.0;

	sum = 0;
	count = 0;

	str = generateString();

	for (i = 0; i < n; i++) {
		k = weights[i];
		sum += a[k];
		node.idx = i;
		node.w = k;
		str2 = str;
		str2[i] = '1';
		node.str = str2;
		q.push(node);
		count++;
	}

	while (!q.empty()) {
		node = q.front();
		q.pop();

		i = node.idx;
		k = node.w;
		arr = node.parents;
		str = node.str;
		node.parents.push_back(i);
		for (j = 0; j < map[i].size(); j++) {
			s = map[i][j];
			str2 = str;
			str2[s] = '1';
			if (visit.find(str2) != visit.end()) continue;
			visit.insert(str2);
			t = k + weights[s];
			sum += a[t];
			count++;

			node.idx = s;
			node.w = t;
			node.str = str2;
			q.push(node);
		}
		node.parents.pop_back();

		if (arr.size() > 0) {
			u = arr[ arr.size() - 1 ];
			node.idx = u;
			node.w = k;
			arr.pop_back();
			node.parents = arr;
			node.str = str;
			q.push(node);
		}
	}

	w = sum / (double)count;

	return w;
}

int main(int argc, char* argv[]) {
	int q, i, u, v, sum;
	double w;

	w = 0.0;

	cin >> q;
	while (q--) {
		cin >> n;
		sum = 0;
		for (i = 0; i < n; i++) {
			cin >> weights[i];
			sum += weights[i];

			map[i].clear();
		}

		for (i = 0; i <= sum; i++) {
			cin >> a[i];
		}

		for (i = 0; i < n - 1; i++) {
			cin >> u >> v;
			u--;
			v--;
			map[u].push_back(v);
			map[v].push_back(u);
		}

		w = solve();

		printf("%.8f\n", w);
	}

	return 0;
}
