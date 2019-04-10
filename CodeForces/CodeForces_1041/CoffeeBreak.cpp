// https://codeforces.com/contest/1041/problem/C

#include <iostream>
#include <map>

using namespace std;

const int SIZE = 200000;

int arr[SIZE];

int main(int argc, char** argv) {
	map<int, int> m;
	map<int, int>::iterator it;
	int n, k, d, i, a, ans;

	scanf("%d %d %d", &n, &k, &d);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		m[a] = i;
	}

	ans = 1;
	i = 0;
	while (m.size()) {
		it = m.upper_bound(i);
		if (it == m.end()) {
			ans++;
			i = 0;
			continue;
		}

		arr[it->second] = ans;
		i = it->first + d;

		m.erase(it);
	}

	printf("%d\n", ans);
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

/*
4 5 3
3 5 1 2
=====
3
3 1 1 2 

10 10 1
10 5 7 4 6 3 2 1 9 8
=====
2
2 1 1 2 2 1 2 1 1 2 
*/
