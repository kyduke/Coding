// CodeForces 764 C.Timofey and a tree

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int SIZE = 100001;

vector<int> link[SIZE];
int color[SIZE] = {0, };
int visited[SIZE] = {0, };

int solve(int n) {
	int ans, root, a, b, i, maxCnt, maxIdx;
	map<int, int> nodes;
	map<int, int> counts;
	map<int, int>::iterator it;
	queue<int> q;

	ans = 0;

	for (i = 1; i <= n; i++) {
		if (link[i].size() == 1) {
			root = i;
			q.push(i);
			break;
		}
	}

	while (!q.empty()) {
		a = q.front();
		q.pop();
		visited[a] = 1;
		for (i = 0; i < link[a].size(); i++) {
			b = link[a][i];
			if (visited[b]) continue;
			if (color[a] != color[b]) {
				nodes[a]++;
				nodes[b]++;
			}
			q.push(b);
		}
	}

	maxCnt = 0;
	maxIdx = 0;
	for (it = nodes.begin(); it != nodes.end(); it++) {
		counts[it->second]++;
		if (maxCnt < it->second) {
			maxCnt = it->second;
			maxIdx = it->first;
		}
	}

	if (counts.size() == 0) {
		ans = root;
	} else if (counts.size() == 1) {
		it = counts.begin();
		if (it->second == 2) {
			ans = maxIdx;
		}
	} else if (counts.size() == 2) {
		it = counts.begin();
		it++;
		if (it->second == 1) {
			ans = maxIdx;
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	int n, a, b, i;

	cin >> n;
	for (i = 1; i < n; i++) {
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	for (i = 1; i <= n; i++) {
		cin >> color[i];
	}

	i = solve(n);
	if (i > 0) {
		cout << "YES\n";
		cout << i << "\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}

/*
4
1 2
2 3
3 4
1 2 1 1
=====
YES
2

3
1 2
2 3
1 2 3
=====
YES
2

5
1 2
2 3
2 4
2 5
1 2 3 4 5
=====
YES
2

4
1 4
2 4
3 4
1 2 3 1
=====
YES
4
*/
