// Combination Parentheses Recursion

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int LIMIT = 1000;

char str[LIMIT * 2 + 1];
vector<string> result;

void dfs(int open, int close, int idx, int n) {

	if (open > n || close > n || open < close) return;

	if (open == n && close == n) {
		str[idx] = 0;
		result.push_back(string(str));
		return;
	}

	str[idx] = '(';
	dfs(open + 1, close, idx + 1, n);

	str[idx] = ')';
	dfs(open, close + 1, idx + 1, n);
}

void combinationParentheses(int n) {
	int i;

	dfs(0, 0, 0, n);

	printf("[");
	for (i = 0; i < result.size(); i++) {
		printf("\"%s\"", result[i].c_str());
		if (i != result.size() - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main(int argc, char* argv[]) {
	int n;

	scanf("%d", &n);
	if (n > LIMIT) {
		printf("I can't solve.\n");
	} else {
		combinationParentheses(n);
	}

	return 0;
}
