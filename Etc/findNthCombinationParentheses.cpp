// Find Nth Combination Parentheses

#include <iostream>
#include <string>

using namespace std;

const int LIMIT = 1000;

char str[LIMIT * 2 + 1];
int curr;
int target;

void dfs(int open, int close, int idx, int n) {
	if (curr == target) return;
	if (open > n || close > n || open < close) return;

	if (open == n && close == n) {
		curr++;
		if (curr == target) {
			str[idx] = 0;
			return;
		}
		return;
	}

	str[idx] = '(';
	dfs(open + 1, close, idx + 1, n);

	if (curr == target) return;

	str[idx] = ')';
	dfs(open, close + 1, idx + 1, n);
}

void findNthCombinationParentheses(int n, int k) {
	target = k;
	curr = 0;

	dfs(0, 0, 0, n);
}

int main(int argc, char* argv[]) {
	int n, k;

	scanf("%d %d", &n, &k);
	findNthCombinationParentheses(n, k);
	printf("%s\n", str);

	return 0;
}

/*
5 1
=====
((((()))))

3 3
=====
(())()

10 100
=====
((((((())(()()))))))
*/
