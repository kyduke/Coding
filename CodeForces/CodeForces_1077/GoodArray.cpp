// https://codeforces.com/contest/1077/problem/C

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 1000001;

int arr[SIZE] = {0, };
int cnt[SIZE] = {0, };

int main() {
	int n, i;
	UINT64 sum, temp;
	vector<int> ans;
	
	scanf("%d", &n);
	sum = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cnt[ arr[i] ]++;
		sum += arr[i];
	}
	
	for (i = 0; i < n; i++) {
		temp = sum - arr[i];
		cnt[ arr[i] ]--;
		if (temp % 2 == 0 && (temp / 2) < SIZE && cnt[temp / 2] > 0) {
			ans.push_back(i + 1);
		}
		cnt[ arr[i] ]++;
	}
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}

/*
5
2 5 1 2 2
=====
3
4 1 5

4
8 3 5 2
=====
2
1 4 

5
2 1 2 4 3
=====
0
*/
