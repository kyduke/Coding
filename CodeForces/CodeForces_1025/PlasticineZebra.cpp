// https://codeforces.com/contest/1025/problem/C

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 100001;

char buffer[SIZE];

void reverseString(int l, int r) {
	char c;
	
	while (l < r) {
		c = buffer[l];
		buffer[l] = buffer[r];
		buffer[r] = c;
		l++;
		r--;
	}
}

int main(int argc, char** argv) {
	int ans, i, j, len;
	int leftCnt, centerCnt, rightCnt;
	
	scanf("%s", buffer);
	len = strlen(buffer);
	
	leftCnt = 0;
	rightCnt = 0;
	for (i = 1; i < len; i++) {
		if (buffer[0] == buffer[len - 1]) break;
		if (leftCnt == 0) {
			leftCnt = 1;
			for (j = 1; j < len; j++) {
				if (buffer[j - 1] == buffer[j]) break;
				leftCnt++;
			}
		}
		if (i < leftCnt) continue;
		if (rightCnt == 0) {
			rightCnt = 1;
			for (j = len - 2; j >= 0; j--) {
				if (buffer[j + 1] == buffer[j]) break;
				rightCnt++;
			}
		}
		if (i > len - rightCnt) break;
		
		centerCnt = 1;
		for (j = i - 1; j >= 0; j--) {
			if (buffer[j + 1] == buffer[j]) break;
			centerCnt++;
		}
		for (j = i + 1; j < len; j++) {
			if (buffer[j - 1] == buffer[j]) break;
			centerCnt++;
		}
		
		if (leftCnt + rightCnt > centerCnt) {
			leftCnt = 0;
			rightCnt = 0;
			reverseString(0, i - 1);
			reverseString(i, len - 1);
		}
	}
	
	ans = 1;
	for (i = 0; i < len; i++) {
		j = i + 1;
		while (j < len && buffer[j - 1] != buffer[j]) j++;
		ans = max(ans, j - i);
		i = j - 1;
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
bwwwbwwbw
=====
5

bwwbwwb
=====
3
*/
