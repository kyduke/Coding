// https://algospot.com/judge/problem/read/RATIO

#include <iostream>

using namespace std;

long long solve(int curr, long long n, long long m) {
	long long result, target;
	double calc;

	target = curr + 1;
	calc = (double)((target * n) - (m * 100)) / (100 - target);
	result = (int)calc;

	if ((calc - (double)result) > 0.0) return result + 1;

	return result;
}

int main(int argc, char* argv[]) {
	int T;
	long long N, M;
	int curr;

	cin >> T;
	while (T--) {
		cin >> N >> M;

		curr = (M * 100) / (double)N;
		if (curr >= 99) {
			cout << "-1\n";
			continue;
		}
		cout << solve(curr, N, M) << "\n";
	}

	return 0;
}

/*
5
10 8
100 80
47 47
99000 0
1000000000 470000000
=====
1
6
-1
1000
19230770
*/
