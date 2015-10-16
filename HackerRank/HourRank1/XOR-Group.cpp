// https://www.hackerrank.com/contests/hourrank-1/challenges/xor-groups

#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long UINT64;

using namespace std;

const int MOD = 1000000007;
const int SIZE = 100000;

int nums[SIZE];
int maskA[SIZE];
int maskB[SIZE];
int countA[SIZE];
int countB[SIZE];
int AB[SIZE];
int n;

int countBruteForce() {
	int cnt, s;

	cnt = 0;
	s = 1;
	maskA[0] = nums[0];
	countA[0] = 1;
	AB[0] = 1;
	while (s) {
		if (s == n) {
			if (countA[s - 1] > 0 && countB[s - 1] > 0 && maskA[s - 1] == maskB[s - 1]) cnt = (cnt + 1) % MOD;
			s--;
			continue;
		}

		if (AB[s] == 0) {
			AB[s] = 1;
			maskA[s] = maskA[s - 1] ^ nums[s];
			countA[s] = countA[s - 1] + 1;
			
			maskB[s] = maskB[s - 1];
			countB[s] = countB[s - 1];
			s++;
		} else if (AB[s] == 1) {
			AB[s] = 2;
			maskA[s] ^= nums[s];
			countA[s] = countA[s - 1];
			
			maskB[s] = maskB[s - 1] ^ nums[s];
			countB[s] = countB[s - 1] + 1;
			s++;
		} else {
			AB[s] = 0;
			maskB[s] ^= nums[s];
			countB[s] = countB[s - 1];
			s--;
		}
	}

	return cnt;
}

int count() {
	UINT64 cnt;
	int i;

	cnt = 1;
	i = 1;
	while (i < n) {
		cnt = (cnt * 2) % MOD;
		i++;
	}

	return cnt - 1;
}

int main(int argc, char* argv[]) {
	int m, a;
	int bit;

	bit = 0;

	cin >> n;
	m = 0;
	while (m < n) {
		cin >> a;
		nums[m] = a;
		bit ^= a;
		m++;
	}

	if (n > 1 && bit == 0) {
		//cout << countBruteForce() << "\n";
		cout << count() << "\n";
	} else {
		cout << "0\n";
	}

	return 0;
}

/*
3
0 1 1
===
3

4
5 2 3 2
=====
0
*/
