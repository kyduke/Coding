// http://codeforces.com/contest/1020/problem/B

#include <iostream>
#include <set>

using namespace std;

const int SIZE = 1001;

int arr[SIZE] = {0, };
set<int> s;

int findClosestLoop(int k) {
	if (s.find(k) != s.end()) return k;
	s.insert(k);
	return findClosestLoop(arr[k]);
}

int main() {
	int n, i;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	
	for (i = 1; i <= n; i++) {
		s.clear();
		printf("%d ", findClosestLoop(i));
	}
	
	return 0;
}

/*
3
2 3 2
=====
2 2 3 

3
1 2 3
=====
1 2 3 
*/
