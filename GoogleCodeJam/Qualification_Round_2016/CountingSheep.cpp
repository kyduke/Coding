// Google CodeJam Qualification Round 2016

#include <iostream>

using namespace std;

int solve(int n) {
	int digits[10] = {0, };
	int answer, i, k;

	answer = 1;

	while (true) {
		k = n * answer;
		while (k) {
			digits[k % 10] = 1;
			k /= 10;
		}

		k = digits[0] + digits[1] + digits[2] + digits[3] + digits[4] + digits[5] + digits[6] + digits[7] + digits[8] + digits[9];

		if (k == 10) break;

		answer++;
	}

	return answer * n;
}

int main(int argc, char* argv[]) {
	int T, t, n;

	cin >> T;

	t = 1;
	while (t <= T) {
		cin >> n;

		cout << "Case #" << t << ": ";
		if (n == 0) {
			cout << "INSOMNIA\n";
		} else {
			cout << solve(n) << "\n";
		}

		t++;
	}

	return 0;
}

/*
5
0
1
2
11
1692
=====
Case #1: INSOMNIA
Case #2: 10
Case #3: 90
Case #4: 110
Case #5: 5076
*/
