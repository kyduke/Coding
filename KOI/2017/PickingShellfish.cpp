// https://www.acmicpc.net/problem/14870
// 한국정보올림피아드 2017 고등부 조개 줍기

#include <iostream>
#include <queue>

using namespace std;

typedef long long INT64;

struct Node {
	int a;
	int b;
};

const int SIZE = 1500;

INT64 arr[SIZE][SIZE];
INT64 board[SIZE][SIZE];

INT64 makeSum(int n) {
	int i, j;
	INT64 sum;

	for (i = 1; i < n; i++) {
		board[0][i] += board[0][i - 1];
		board[i][0] += board[i - 1][0];
	}

	for (i = 1; i < n; i++) {
		for (j = 1; j < n; j++) {
			board[i][j] += max(board[i - 1][j], board[i][j - 1]);
		}
	}

	sum = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum += board[i][j];
		}
	}

	return sum;
}

INT64 updateSum(int n, int a, int b, int j, INT64 sum) {
	queue<Node> q;
	Node node;
	INT64 ans, temp;

	ans = sum;
	arr[a][b] += j;

	node.a = a;
	node.b = b;
	q.push(node);

	while (!q.empty()) {
		node = q.front();
		q.pop();

		a = node.a;
		b = node.b;
		if (a >= n || b >= n) continue;

		if (a == 0 || b == 0) {
			ans += j;
			
			board[a][b] += j;

			node.a = a + 1;
			node.b = b;
			q.push(node);

			node.a = a;
			node.b = b + 1;
			q.push(node);
		} else {
			temp = max(board[a - 1][b], board[a][b - 1]) + arr[a][b];
			if (temp != board[a][b]) {
				ans += j;

				board[a][b] += j;

				node.a = a + 1;
				node.b = b;
				q.push(node);

				node.a = a;
				node.b = b + 1;
				q.push(node);
			}
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int n, i, j, a, b;
	char c[2];
	INT64 ans;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a);
			arr[i][j] = a;
			board[i][j] = a;
		}
	}

	ans = makeSum(n);
	printf("%lld\n", ans);

	for (i = 0; i < n; i++) {
		scanf("%s %d %d", c, &a, &b);
		j = 1;
		if (c[0] == 'D') j = -1;
		ans = updateSum(n, a - 1, b - 1, j, ans);
		printf("%lld\n", ans);
	}

	return 0;
}

/*
3
3 2 7
4 2 6
5 3 8
U 1 2
D 3 2
U 1 2
=====
107
111
110
114
*/
