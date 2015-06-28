// http://codeforces.com/problemset/problem/553/B

#include <iostream>

using namespace std;

void makeFibonacci(unsigned long long* num, int n) {
	int i;

	num[0] = 1;
	num[1] = 1;
	for (i = 2; i < n; i++) {
		num[i] = num[i - 1] + num[i - 2];
	}
}

void solve(int n, unsigned long long k) {
	unsigned long long num[50];
	int result[50];
	int i, t;

	makeFibonacci(num, n);

	for (i = 0; i < n; i++) {
		result[i] = i + 1;
	}

	i = n - 1;
	while (i > 0) {
		if (k > num[i]) {
			k -= num[i];
			t = result[n - i];
			result[n - i] = result[n - i - 1];
			result[n - i - 1] = t;
		}
		i--;
	}

	for (i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int n;
	unsigned long long k;

	cin >> n >> k;

	solve(n, k);

	return 0;
}

/*
4 3
output
1 3 2 4
input
10 1
output
1 2 3 4 5 6 7 8 9 10
*/
