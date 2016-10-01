// http://codeforces.com/contest/721/problem/B

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 101;

int counts[SIZE] = {0, };

void solve(int k, int a) {
	int i, sum;

	sum = 0;
	for (i = 1; i < a; i++) {
		sum += counts[i];
	}

	i = sum / k;
	cout << (sum + i * 5 + 1) << " ";

	sum += counts[a] - 1;
	i = sum / k;
	cout << (sum + i * 5 + 1);
}

int main(int argc, char* argv[]) {
	int n, k;
	string str;

	cin >> n >> k;
	while (n--) {
		cin >> str;
		counts[str.size()]++;
	}
	cin >> str;
	
	solve(k, str.size());

	return 0;
}

/*
5 2
cba
abc
bb1
abC
ABC
abc
=====
1 15

4 100
11
22
1
2
22
=====
3 4
*/
