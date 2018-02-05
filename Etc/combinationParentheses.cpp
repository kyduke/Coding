// Catalan Number
// Combination Parentheses
// https://en.wikipedia.org/wiki/Catalan_number
// https://ko.wikipedia.org/wiki/%EC%B9%B4%ED%83%88%EB%9E%91_%EC%88%98

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef unsigned long long UINT64;

struct Node {
	string str;
	int open;
	int close;
};

const UINT64 MUL = 1000000000;

map<UINT64, int> cache;

int ncr(UINT64 n, UINT64 r) {
	map<UINT64, int>::iterator it;
	UINT64 k;
	int v;

	r = min(r, n - r);

	if (r == 0) {
		return 1;
	} else if (r == 1) {
		return n;
	}

	k = n * MUL + r;
	it = cache.find(k);
	if (it != cache.end()) {
		return it->second;
	}

	v = ncr(n - 1, r - 1) + ncr(n - 1, r);
	cache.insert(make_pair(k, v));

	return v;
}

int catalan(int n) {
	return ncr(n + n, n) / (n + 1);
}

vector<string> combinationParentheses(int n) {
	vector<string> ans;
	queue<Node> q;
	Node node;

	node.str = "";
	node.open = 0;
	node.close = 0;
	q.push(node);

	while (!q.empty()) {
		node = q.front();
		q.pop();

		if (node.open == n && node.close == n) {
			ans.push_back(node.str);
			continue;
		} else if (node.open > n || node.close > n || node.open < node.close) {
			continue;
		}

		node.str += '(';
		node.open++;
		q.push(node);

		node.str[node.str.size() - 1] = ')';
		node.open--;
		node.close++;
		q.push(node);
	}

	return ans;
}


int main(int argc, char* argv[]) {
	vector<string> res;
	int i, j;

	for (i = 0; i < 5; i++) {
		cout << i << ": " << catalan(i) << "\n";
		res = combinationParentheses(i);
		for (j = 0; j < res.size(); j++) {
			cout << res[j] << "\n";
		}
	}

	return 0;
}

/*
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862
*/
