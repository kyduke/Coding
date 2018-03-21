// http://codeforces.com/contest/948/problem/C

#include <iostream>
#include <queue>

using namespace std;

typedef long long INT64;

const int SIZE = 100000;

int arr[SIZE];

int main(int argc, char** argv) {
	priority_queue<INT64> q;  
	int n, t, i;
	INT64 ans, sum;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	sum = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		ans = 0;
		q.push(-arr[i] - sum);
		while (!q.empty() && q.top() >= -(sum + t)) {
			ans -= sum + q.top();
			q.pop();
		}
		ans += (INT64)(t) * (INT64)(q.size());
		sum += t;
		printf("%I64u ", ans);
	}
	printf("\n");
	
	return 0;
}

/*
3
10 10 5
5 7 2
=====
5 12 4

5
30 25 20 15 10
9 10 12 4 13
=====
9 20 35 11 25
*/
