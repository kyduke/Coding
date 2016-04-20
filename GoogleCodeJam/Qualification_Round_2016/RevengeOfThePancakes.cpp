// Google Code Jamp Qualification Round 2016 Problem B. Revenge of the Pancakes

#include <iostream>
#include <string>

using namespace std;

int solve(string str) {
	int answer, i;
	char c;

	answer = 0;
	c = ' ';
	for (i = 0; i < str.size(); i++) {
		if (c != str[i]) {
			answer++;
			c = str[i];
		}
	}
	if (c == '+') {
		answer--;
	}

	return answer;
}

int main(int argc, char* argv[]) {
	int T, t;
	string str;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> str;
		cout << "Case #" << t << ": " << solve(str) << "\n";
		t++;
	}

	return 0;
}

/*

5
-
-+
+-
+++
--+-
=====
Case #1: 1
Case #2: 1
Case #3: 2
Case #4: 0
Case #5: 3
*/
