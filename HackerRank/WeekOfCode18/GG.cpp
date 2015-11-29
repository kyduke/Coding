// https://www.hackerrank.com/contests/w18/challenges/gg

#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 3003;

struct Node {
	int idx;
	int curr;
	int next;
};

int n;
UINT64 m;
UINT64 cnt;
char str[SIZE];
int visit[SIZE];

void solve() {
	stack<Node> st;
	Node node;
	int c, i, j;
	bool found;

	cnt = 0;

	node.idx = -1;
	node.curr = -1;
	node.next = 0;
	st.push(node);
	while (!st.empty()) {
		node = st.top();
		node.idx++;
		if (node.idx == n) {
			cnt = (cnt + 1) % m;
			visit[node.curr] = 0;
			st.pop();
			continue;
		}
		c = node.curr;
		
		found = false;
		for (i = node.next; i < n; i++) {
			if (visit[i] == 1) continue;
			if (c != -1) {
				if (str[node.idx - 1] == 'G') {
					if (c < i) continue; 
				} else {
					if (c > i) continue;
				}
			}
			st.top().next = i + 1;
			visit[i] = 1;
			node.curr = i;
			node.next = 0;
			st.push(node);
			found = true;
			break;
		}

		if (found == false) {
			visit[c] = 0;
			st.pop();
		}
	}
}

int main(int argc, char* argv[]) {
	cin >> n >> m >> str;

	solve();

	cout << cnt << "\n";

	return 0;
}
