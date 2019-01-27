// https://codeforces.com/contest/1107/problem/B

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef unsigned long long UINT64;
typedef long long INT64;

const int SIZE = 100001;

int main(int argc, char** argv) {
	int n;
	UINT64 k, x;

	scanf("%d", &n);
	while (n--) {
		cin >> k >> x;
		cout << (((k - 1) * 9) + x) << "\n";
	}

	return 0;
}

/*
3
1 5
5 2
3 1
=====
5
38
19
*/
