// https://www.acmicpc.net/problem/13309
// 한국정보올림피아드 2016 고등부 트리
// timeout

#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 200001;

set<int> children[SIZE];
int parent[SIZE] = {0, };
UINT64 group[SIZE] = {0, };
UINT64 prevG, g;

void updateGroup(int n) {
	queue<int> q;
	set<int>::iterator it;
	int i, k;

	prevG = g;
	for (i = 1; i <= n; i++) {
		if (group[i] > prevG) continue;
		g++;
		q.push(i);
		while (!q.empty()) {
			k = q.front();
			q.pop();
			group[k] = g;
			for (it = children[k].begin(); it != children[k].end(); it++) {
				q.push(*it);
			}
		}
	}
}

void updateSpcificGroup(int target, int n) {
	queue<int> q;
	set<int>::iterator it;
	int k;

	g++;
	q.push(target);
	while (!q.empty()) {
		k = q.front();
		q.pop();
		group[k] = g;
		for (it = children[k].begin(); it != children[k].end(); it++) {
			q.push(*it);
		}
	}
}

int main(int argc, char* argv[]) {
	int n, q, i, a, b, c, d;

	scanf("%d %d", &n, &q);
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		parent[i] = a;
		children[a].insert(i);
	}

	g = 0;
	updateGroup(n);
	while (q--) {
		scanf("%d %d %d", &b, &c, &d);
		
		if (group[b] == group[c]) {
			printf("YES\n");
		} else {
			printf("NO\n");
			b = c;
		}
		if (d == 1) {
			if (parent[b] != 0) {
				set<int>::iterator it;

				c = parent[b];
				parent[b] = 0;
				it = children[c].find(b);
				if (it != children[c].end()) {
					children[c].erase(it);
					updateSpcificGroup(b, n);
				}
			}
		}
	}

	return 0;
}

/*
3 4
1
1
2 3 1
1 3 0
2 3 1
1 3 1
=====
YES
YES
NO
NO

11 7
7
4
1
9
11
1
11
1
3
7
11 9 1
8 5 0
3 9 0
6 3 1
10 9 1
3 10 1
1 4 1
=====
YES
NO
YES
NO
NO
YES
YES
*/
