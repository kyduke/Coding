#include <iostream>

using namespace std;

enum Operator {
	plus = 0,
	minus = 1,
	multiply = 2,
	divide = 3
};

// ((a @ b) @ c) @ d = 24
bool calculationA(int* num, char* ops) {
	int i;
	double x;

	x = (double)num[0];

	for (i = 0; i < 3; i++) {
		switch(ops[i]) {
			case plus:
				x += (double)num[i + 1];
				break;
			case minus:
				x -= (double)num[i + 1];
				break;
			case multiply:
				x *= (double)num[i + 1];
				break;
			case divide:
				x /= (double)num[i + 1];
				break;
			default:
				return false;
		}
	}

	return (x == 24.0);
}

// (a @ b) @ (c @ d) = 24
bool calculationB(int* num, char* ops) {
	double x, a, b;

	a = (double)num[0];
	switch(ops[0]) {
		case plus:
			a += (double)num[1];
			break;
		case minus:
			a -= (double)num[1];
			break;
		case multiply:
			a *= (double)num[1];
			break;
		case divide:
			a /= (double)num[1];
			break;
		default:
			return false;
	}

	b = (double)num[2];
	switch(ops[2]) {
		case plus:
			b += (double)num[3];
			break;
		case minus:
			b -= (double)num[3];
			break;
		case multiply:
			b *= (double)num[3];
			break;
		case divide:
			b /= (double)num[3];
			break;
		default:
			return false;
	}

	switch(ops[1]) {
		case plus:
			x = a + b;
			break;
		case minus:
			x = a - b;
			break;
		case multiply:
			x = a * b;
			break;
		case divide:
			x = a / b;
			break;
		default:
			return false;
	}

	return (x == 24.0);
}

int makeOps(char* ops, int* num, int count) {
	int i, result;

	if (count == 3) {
		if (calculationA(num, ops)) return 1;
		if (calculationB(num, ops)) return 2;
		return 0;
	}

	for (i = 0; i < 4; i++) {
		ops[count] = (char)i;
		result = makeOps(ops, num, count + 1);
		if (result) return result;
	}

	return 0;
}

int permutationNumbers(int* src, char* visit, int* num, char* ops, int count) {
	int i, result;

	if (count == 4) {
		return makeOps(ops, num, 0);
	}

	for (i = 0; i < 4; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		num[count] = src[i];
		result = permutationNumbers(src, visit, num, ops, count + 1);
		if (result) return result;
		visit[i] = 0;
	}

	return 0;
}

void displayResult(int* num, char* ops, int result) {
	char sign[4] = {'+', '-', '*', '/'};

	if (result == 1) {
		cout << "((";
		cout << num[0] << " " << sign[ops[0]] << " " << num[1];
		cout << ") ";
		cout << sign[ops[1]] << " " << num[2];
		cout << ") ";
		cout << sign[ops[2]] << " " << num[3];
		cout << " = 24\n";
	} else if (result == 2) {
		cout << "(";
		cout << num[0] << " " << sign[ops[0]] << " " << num[1];
		cout << ") ";
		cout << sign[ops[1]];
		cout << " (";
		cout << num[2] << " " << sign[ops[2]] << " " << num[3];
		cout << ") = 24\n";
	} else {
		cout << "failed\n";
	}
}

int main(int argc, char* argv[]) {
	int src[4], num[4], result;
	char visit[4], ops[3];

	while (1) {
		cin >> src[0];
		cin >> src[1];
		cin >> src[2];
		cin >> src[3];

		visit[0] = 0;
		visit[1] = 0;
		visit[2] = 0;
		visit[3] = 0;

		result = permutationNumbers(src, visit, num, ops, 0);
		displayResult(num, ops, result);
	}

	return 0;
}
