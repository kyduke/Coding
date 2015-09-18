// https://leetcode.com/problems/expression-add-operators/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	string num;
	int target;
	vector<int> digit;
	vector<int> op; //0(+), 1(-), 2(*), 3(.)
	void parseDigit() {
		int i;

		digit.clear();
		for (i = 0; i < num.size(); i++) {
			digit.push_back(num[i] - '0');
		}
	}
	void initOp() {
		int i;

		op.clear();
		for (i = 0; i < num.size() - 1; i++) {
			op.push_back(0);
		}
	}
	void nextOp() {
		int i;

		op[op.size() - 1]++;
		for (i = op.size() - 1; i > 0; i--) {
			if (op[i] > 3) {
				op[i] = 0;
				op[i - 1]++;
			}
		}
	}
	int calculate() {
		vector<int> d, o;
		int i;

		d = digit;
		o = op;

		//join
		for (i = 0; i < o.size(); i++) {
			if (o[i] == 3) {
				if (d[i] == 0) return target - 1;
				if (i == 0) {
					o[i] = 0;
				} else {
					o[i] = o[i - 1];
				}
				d[i + 1] += d[i] * 10;
				d[i] = 0;
				if (o[i] == 2) d[i] = 1;
			}
		}

		//multiply
		for (i = 0; i < o.size(); i++) {
			if (o[i] == 2) {
				if (i == 0) {
					o[i] = 0;
				} else {
					o[i] = o[i - 1];
				}
				d[i + 1] = d[i] * d[i + 1];
				d[i] = 0;
			}
		}

		//plus, minus
		for (i = 0; i < o.size(); i++) {
			if (o[i] == 0) {
				d[i + 1] += d[i];
			} else {
				d[i + 1] = d[i] - d[i + 1];
			}
		}

		return d[i];
	}
	string makeString() {
		string str;
		string d[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		string o[4] = {"+", "-", "*", ""};
		int i;

		for (i = 0; i < op.size(); i++) {
			str.append(d[ digit[i] ]);
			str.append(o[ op[i] ]);
		}
		str.append(d[ digit[i] ]);

		return str;
	}
	bool isFinishOp() {
		int i;

		for (i = 0; i < op.size(); i++) {
			if (op[i] != 3) return false;
		}

		return true;
	}
	int digitToNumber() {
		int n, i;

		n = 0;
		for (i = 0; i < digit.size(); i++) {
			n = n * 10 + digit[i];
		}

		return n;
	}
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
		int n;

		if (num.size() == 0) return result;
		
		this->num = num;
		this->target = target;
		parseDigit();

		n = digitToNumber();
		if (n < 0 || n < target) return result;
		if (target != 0 && n == target) {
			result.push_back(num);
			return result;
		}

		initOp();

		while (true) {
			if (calculate() == target) {
				result.push_back(makeString());
			}
			if (isFinishOp()) break;
			nextOp();
		}

		return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<string> result;
	int i;

	result = s.addOperators("2147483648", -2147483648);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	cout << "\n\n";

	return 0;

	result = s.addOperators("123", 6);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	cout << "\n\n";

	result = s.addOperators("232", 8);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	cout << "\n\n";

	result = s.addOperators("00", 0);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	cout << "\n\n";

	result = s.addOperators("3456237490", 9191);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	cout << "\n\n";


	return 0;
}
