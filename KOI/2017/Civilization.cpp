// https://www.acmicpc.net/problem/14868
// 한국정보올림피아드 2017 고등부 문명

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int x;
	int y;
};

const int SIZE = 2000;

int board[SIZE][SIZE] = {0, };
int group[SIZE * SIZE + 1];

int getGroupID(int n) {
	if (group[n] == n) return n;

	group[n] = getGroupID(group[n]);
	return group[n];
}

int solve(int n, int k) {
	vector<Node> curr, temp;
	Node node;
	int ans, i, j, x, y, p1, p2, groupID;

	// find group
	groupID = 2;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				node.x = i;
				node.y = j;
				curr.push_back(node);
				x = i - 1;
				y = j;
				p1 = 0;
				if (x > 0 && board[x][y] != 0) {
					p1 = getGroupID(board[x][y]);
				}
				x = i;
				y = j - 1;
				p2 = 0;
				if (y > 0 && board[x][y] != 0) {
					p2 = getGroupID(board[x][y]);
				}

				if (p1 == 0 && p2 == 0) {
					board[i][j] = groupID;
					group[groupID] = groupID;
					groupID++;
				} else if (p2 == 0) {
					board[i][j] = p1;
				} else if (p1 == 0) {
					board[i][j] = p2;
				} else {
					board[i][j] = min(p1, p2);
					group[p1] = board[i][j];
					group[p2] = board[i][j];
				}
			}
		}
	}

	ans = 0;
	while (true) {
		// Merge groups
		for (i = 0; i < curr.size(); i++) {
			x = curr[i].x;
			y = curr[i].y;
			p1 = getGroupID(board[x][y]);
			x = curr[i].x - 1;
			y = curr[i].y;
			if (x >= 0) {
				if (board[x][y] != 0) {
					p2 = getGroupID(board[x][y]);
					j = min(p1, p2);
					group[p1] = j;
					group[p2] = j;
					p1 = j;
				}
			}
			x = curr[i].x + 1;
			y = curr[i].y;
			if (x < n) {
				if (board[x][y] != 0) {
					p2 = getGroupID(board[x][y]);
					j = min(p1, p2);
					group[p1] = j;
					group[p2] = j;
					p1 = j;
				}
			}
			x = curr[i].x;
			y = curr[i].y - 1;
			if (y >= 0) {
				if (board[x][y] != 0) {
					p2 = getGroupID(board[x][y]);
					j = min(p1, p2);
					group[p1] = j;
					group[p2] = j;
					p1 = j;
				}
			}
			x = curr[i].x;
			y = curr[i].y + 1;
			if (y < n) {
				if (board[x][y] != 0) {
					p2 = getGroupID(board[x][y]);
					j = min(p1, p2);
					group[p1] = j;
					group[p2] = j;
					p1 = j;
				}
			}
		}

		// Count groups
		j = 0;
		for (i = 2; i < groupID; i++) {
			if (group[i] == i) {
				j++;
				if (j > 1) break;
			}
		}
		if (j == 1) break;
		ans++;

		// Expand area
		for (i = 0; i < curr.size(); i++) {
			x = curr[i].x;
			y = curr[i].y;
			p1 = getGroupID(board[x][y]);
			x = curr[i].x - 1;
			y = curr[i].y;
			if (x >= 0) {
				if (board[x][y] == 0) {
					board[x][y] = p1;
					node.x = x;
					node.y = y;
					temp.push_back(node);
				} else {
					p2 = getGroupID(board[x][y]);
					j = min(p1, p2);
					group[p1] = j;
					group[p2] = j;
					p1 = j;
				}
			}
			x = curr[i].x + 1;
			y = curr[i].y;
			if (x < n) {
				if (board[x][y] == 0) {
					board[x][y] = p1;
					node.x = x;
					node.y = y;
					temp.push_back(node);
				} else {
					p2 = getGroupID(board[x][y]);
					j = min(p1, p2);
					group[p1] = j;
					group[p2] = j;
					p1 = j;
				}
			}
			x = curr[i].x;
			y = curr[i].y - 1;
			if (y >= 0) {
				if (board[x][y] == 0) {
					board[x][y] = p1;
					node.x = x;
					node.y = y;
					temp.push_back(node);
				} else {
					p2 = getGroupID(board[x][y]);
					j = min(p1, p2);
					group[p1] = j;
					group[p2] = j;
					p1 = j;
				}
			}
			x = curr[i].x;
			y = curr[i].y + 1;
			if (y < n) {
				if (board[x][y] == 0) {
					board[x][y] = p1;
					node.x = x;
					node.y = y;
					temp.push_back(node);
				} else {
					p2 = getGroupID(board[x][y]);
					j = min(p1, p2);
					group[p1] = j;
					group[p2] = j;
					p1 = j;
				}
			}
		}
		curr = temp;
		temp.clear();
	}
	
	return ans;
}

int main(int argc, char* argv[]) {
	int n, k, i, x, y;

	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		board[x - 1][y - 1] = 1;
	}

	printf("%d\n", solve(n, k));

	return 0;
}

/*
5 4
1 1
2 1
2 5
5 2
=====
2

10 3
1 1
1 3
1 8
=====
2

2000 1
100 100
=====
0

2000 2
1 1
2000 2000
=====
1999
*/
