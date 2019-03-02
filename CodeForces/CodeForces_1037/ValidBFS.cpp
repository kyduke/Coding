// https://codeforces.com/contest/1037/problem/D

#include <iostream>
#include <set>
#include <queue>

using namespace std;

const int SIZE = 200001;

set<int> link[SIZE];
int arr[SIZE];

int main() {
	queue<int> q;
	int n, u, v, i;
	set<int>::iterator it;
	
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		link[u].insert(v);
		link[v].insert(u);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	link[0].insert(1);
	link[1].insert(0);
	q.push(0);
	i = 0;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		if (link[u].size() == 0) continue;
		while (link[u].size()) {
			v = arr[i];
			it = link[u].find(v);
			if (it == link[u].end()) {
				printf("No\n");
				return 0;
			}
			link[u].erase(it);
			link[v].erase(u);
			q.push(v);
			i++;
		}
	}
	
	printf("Yes\n");
	
	return 0;
}

/*
4
1 2
1 3
2 4
1 2 3 4
=====
Yes

4
1 2
1 3
2 4
1 2 4 3
=====
No
*/
