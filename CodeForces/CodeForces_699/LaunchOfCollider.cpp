// http://codeforces.com/contest/699/problem/A

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	int i, n, p, x, answer;
	string str;

	cin >> n;
	cin >> str;

	p = -1;
	x = -1;
	answer = -1;
	cin >> x;
	for (i = 1; i < n; i++) {
		p = x;
		cin >> x;
		if (str[i] == 'L' && str[i - 1] == 'R') {
			if (answer == -1) {
				answer = (x - p) / 2;
			} else {
				answer = min(answer, (x - p) / 2);
			}
		}
	}

	cout << answer << "\n";

	return 0;
}

/*
4
RLRL
2 4 6 10
=====
1

3
LLR
40 50 60
=====
-1
*/
