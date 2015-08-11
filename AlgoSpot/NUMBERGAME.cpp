// https://algospot.com/judge/problem/read/NUMBERGAME

#include <iostream>
#include <string.h>

using namespace std;

int cache[50][50];
int numbers[50];
int n;

int play(int left, int right) {
	if (right == left) return numbers[left];
	if (right < left) return 0;

	int& ret = cache[left][right];

	if (ret != -1) return ret;

	ret = numbers[left] - play(left + 1, right);
	ret = max(ret, numbers[right] - play(left, right - 1));
	ret = max(ret, -1 * play(left + 2, right));
	ret = max(ret, -1 * play(left, right - 2));

	return ret;
}

int main(int argc, char* argv[]) {
	int C, i;

	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(int) * 50 * 50);
		cin >> n;
		i = 0;
		while (i < n) {
			cin >> numbers[i];
			i++;
		}
		cout << play(0, n - 1) << "\n";
	}

	return 0;
}

/*
3 
5 
-1000 -1000 -3 -1000 -1000 
6 
100 -1000 -1000 100 -1000 -1000 
10 
7 -5 8 5 1 -4 -8 6 7 9 
=====
-1000
1100
7
*/
