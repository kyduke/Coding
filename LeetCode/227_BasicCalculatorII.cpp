// https://leetcode.com/problems/basic-calculator-ii/

#include <iostream>
#include <string>

using namespace std;

enum State {
	NUMBER_A,
	OPERATOR,
	NUMBER_B,
	NEXT_OPERATOR,
	NEXT_NUMBER
};

enum Operation {
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE
};

class Solution {
public:
    int calculate(string s) {
		State state;
		int a, b, nextNum, next;
		Operation op, nextOp, next2;
		int index, length;
		char c;

		state = NUMBER_A;

		next = 0;
		length = s.length();
		for (index = 0; index < length; index++) {
			c = s[index];
			if (c == ' ') continue;
			if (c >= '0' && c <= '9') {
				switch (state) {
					case NUMBER_A:
					case NUMBER_B:
					case NEXT_NUMBER:
						next = next * 10 + (c - '0');
						break;
				}
			} else if (c == '+' || c == '-' || c == '*' || c == '/'){
				switch (state) {
					case NUMBER_A:
						a = next;
						next = 0;
						state = OPERATOR;
						break;
					case NUMBER_B:
						b = next;
						next = 0;
						if (op == MULTIPLY) {
							a = a * b;
							state = OPERATOR;
						} else if (op == DIVIDE) {
							a = a / b;
							state = OPERATOR;
						} else {
							state = NEXT_OPERATOR;
						}
						break;
					case NEXT_NUMBER:
						nextNum = next;
						next = 0;
						if (nextOp == MULTIPLY) {
							b = b * nextNum;
						} else {
							b = b / nextNum;
						}
						state = NEXT_OPERATOR;
						break;
				}
				switch (c) {
					case '+':
						next2 = PLUS;
						break;
					case '-':
						next2 = MINUS;
						break;
					case '*':
						next2 = MULTIPLY;
						break;
					case '/':
						next2 = DIVIDE;
						break;
				}
				if (state == OPERATOR) {
					op = next2;
					state = NUMBER_B;
				} else {
					nextOp = next2;
					if (nextOp == PLUS || nextOp == MINUS) {
						if (op == PLUS) {
							a = a + b;
						} else {
							a = a - b;
						}
						op = nextOp;
						state = NUMBER_B;
					} else {
						state = NEXT_NUMBER;
					}
				}
			}
		}

		if (state == NUMBER_A) {
			a = next;
		} else if (state == NUMBER_B) {
			if (op == PLUS) {
				a = a + next;
			} else if (next > 0) {
				a = a - next;
			}
		} else if (state == NEXT_OPERATOR) {
			if (op == PLUS) {
				a = a + b;
			} else if (b > 0) {
				a = a - b;
			}
		} else if (state == NEXT_NUMBER) {
			if (nextOp == MULTIPLY) {
				b = b * next;
			} else if (next > 0) {
				b = b / next;
			}
			if (op == PLUS) {
				a = a + b;
			} else if (b > 0) {
				a = a - b;
			}
		}

        return a;
    }
};

int main(int argc, char* argv[]) {
	Solution sol;
	string s;
	char buffer[256];

	cin.get(buffer, 256);

	s = string(buffer);

	cout << sol.calculate(s) << "\n";

	return 0;
}

/*
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/
