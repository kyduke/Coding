// https://codeforces.com/contest/1107/problem/C

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef unsigned long long UINT64;
typedef long long INT64;

const int SIZE = 200001;

UINT64 arr[SIZE];
char str[SIZE];

int main(int argc, char** argv) {
	int n, k, i, j, a;
	UINT64 ans;
	priority_queue<UINT64> q;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[i] = a;
	}
	scanf("%s", str);

	ans = 0;
	for (i = 0; i < n; i++) {
		j = i;
		while (j < n && str[i] == str[j]) {
			q.push(arr[j]);
			j++;
		}
		a = k;
		while (a > 0 && !q.empty()) {
			ans += q.top();
			q.pop();
			a--;
		}
		while (!q.empty()) q.pop();
		i = j - 1;
	}
	cout << ans << "\n";

	return 0;
}

/*
7 3
1 5 16 18 7 2 10
baaaaca
=====
54

5 5
2 4 1 3 1000
aaaaa
=====
1010

5 4
2 4 1 3 1000
aaaaa
=====
1009

8 1
10 15 2 1 4 8 15 16
qqwweerr
=====
41

6 3
14 18 9 19 2 15
cccccc
=====
52

2 1
10 10
qq
=====
10
*/
