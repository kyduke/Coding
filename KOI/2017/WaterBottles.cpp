// https://www.acmicpc.net/problem/14867
// 한국정보올림피아드 2017 고등부 물통

#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

struct Node {
	int a;
	int b;
	int cnt;
};

const UINT64 MUL = 1000000;

int solve(int a, int b, int c, int d) {
	queue<Node> q;
	set<UINT64> visited;
	Node node;
	int ans, x, y, cnt;
	UINT64 key;

	ans = -1;
	node.a = 0;
	node.b = 0;
	node.cnt = 0;
	q.push(node);
	visited.insert(0);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		x = node.a;
		y = node.b;
		cnt = node.cnt;
		if (ans != -1 && cnt >= ans) continue;
		if (x == c && y == d) {
			if (ans == -1 || ans > cnt) {
				ans = cnt;
			}
			continue;
		}

		// a -> 0
		if (x != 0) {
			node.a = 0;
			node.b = y;
			node.cnt = cnt + 1;
			key = (UINT64)node.a * MUL + (UINT64)node.b;
			if (visited.find(key) == visited.end()) {
				q.push(node);
				visited.insert(key);
			}
		}

		// b -> 0
		if (y != 0) {
			node.a = x;
			node.b = 0;
			node.cnt = cnt + 1;
			key = (UINT64)node.a * MUL + (UINT64)node.b;
			if (visited.find(key) == visited.end()) {
				q.push(node);
				visited.insert(key);
			}
		}

		// a -> A
		if (x != a) {
			node.a = a;
			node.b = y;
			node.cnt = cnt + 1;
			key = (UINT64)node.a * MUL + (UINT64)node.b;
			if (visited.find(key) == visited.end()) {
				q.push(node);
				visited.insert(key);
			}
		}

		// b -> B
		if (y != b) {
			node.a = x;
			node.b = b;
			node.cnt = cnt + 1;
			key = (UINT64)node.a * MUL + (UINT64)node.b;
			if (visited.find(key) == visited.end()) {
				q.push(node);
				visited.insert(key);
			}
		}

		// a -> b
		if (x != 0) {
			node.a = 0;
			node.b = y + x;
			node.cnt = cnt + 1;
			if (node.b > b) {
				node.a = node.b - b;
				node.b = b;
			}
			key = (UINT64)node.a * MUL + (UINT64)node.b;
			if (visited.find(key) == visited.end()) {
				q.push(node);
				visited.insert(key);
			}
		}

		// b -> a
		if (y != 0) {
			node.a = x + y;
			node.b = 0;
			node.cnt = cnt + 1;
			if (node.a > a) {
				node.b = node.a - a;
				node.a = a;
			}
			key = (UINT64)node.a * MUL + (UINT64)node.b;
			if (visited.find(key) == visited.end()) {
				q.push(node);
				visited.insert(key);
			}
		}
	}
	
	return ans;
}

int main(int argc, char* argv[]) {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d\n", solve(a, b, c, d));

	return 0;
}

/*
3 7 3 2
=====
9

2 5 0 1
=====
5

3 5 2 4
=====
-1
*/
