// https://codeforces.com/contest/1015/problem/B

#include <iostream>
#include <vector>

using namespace std;

char strA[51];
char strB[51];

int isPossible(int n) {
	int arr[26] = {0, };
	int i, a, b;
	
	for (i = 0; i < n; i++) {
		arr[ strA[i] - 'a' ]++;
		arr[ strB[i] - 'a' ]--;
	}
	
	for (i = 0; i < 26; i++) {
		if (arr[i] != 0) return -1;
	}
	
	return 1;
}

vector<int> solve(int n) {
	vector<int> ans;
	int i, j;
	
	for (i = 0; i < n; i++) {
		if (strA[i] == strB[i]) continue;
		for (j = i + 1; j < n; j++) {
			if (strA[j] == strB[i]) break;
		}
		while (j > i) {
			ans.push_back(j);
			strA[j] = strA[j - 1];
			j--;
		}
		strA[i] = strB[i];
	}
	
	return ans;
}

int main() {
	vector<int> ans;
	int n, i;
	
	scanf("%d", &n);
	scanf("%s", strA);
	scanf("%s", strB);
	
	if (isPossible(n) == -1) {
		printf("-1\n");
		return 0;
	}
	
	ans = solve(n);
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}

/*
6
abcdef
abdfec
=====
4

4
abcd
accd
=====
-1
*/
