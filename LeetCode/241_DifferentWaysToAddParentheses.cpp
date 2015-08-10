// https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
private:
	map<string, int> answers;
	string integerToString(int n) {
		string str;
		string table[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

		str = "";
		while (n) {
			str = table[n % 10] + str;
			n /= 10;
		}

		return str;
	}
	int calcOneEquation(int a, int op, int b) {
		int c;

		if (op == '+') c = a + b;
		else if (op == '-') c = a - b;
		else if (op == '*') c = a * b;
		else if (op == '/') c = a / b;

		return c;
	}
	void calcEquationAnyOrder(vector<pair<int, int>>& equations, vector<string> parentheses) {
		vector<pair<int, int>> temp;
		vector<pair<int, int>>::iterator it;
		vector<string> tempParentheses;
		vector<string>::iterator itParentheses;
		int i;

		if (equations.size() == 1) {
			answers.insert(make_pair(parentheses[0], equations[0].second));
			return;
		}

		for (i = 0; i < equations.size() - 1; i++) {
			temp = equations;
			temp[i].second = calcOneEquation(temp[i].second, temp[i + 1].first, temp[i + 1].second);
			it = temp.begin() + (i + 1);
			temp.erase(it);

			tempParentheses = parentheses;
			tempParentheses[i] = "(" + tempParentheses[i] + tempParentheses[i + 1] + ")";
			itParentheses = tempParentheses.begin() + (i + 1);
			tempParentheses.erase(itParentheses);

			calcEquationAnyOrder(temp, tempParentheses);
		}
	}
public:
    vector<int> diffWaysToCompute(string input) {
		vector<pair<int, int>> equations;
		vector<string> parentheses;
		vector<int> result;
		map<string, int>::iterator it;
		int i, op, n, idx;

		result.clear();
		answers.clear();

		op = 0;
		n = 0;
		idx = 0;
		for (i = 0; i < input.size(); i++) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
				equations.push_back(make_pair(op, n));
				parentheses.push_back(integerToString(idx++));
				n = 0;

				op = input[i];
				continue;
			}
			
			n = n * 10 + (input[i] - '0');
		}
		equations.push_back(make_pair(op, n));
		parentheses.push_back(integerToString(idx++));

		if (equations.size() == 0) return result;

		calcEquationAnyOrder(equations, parentheses);

		for (it = answers.begin(); it != answers.end(); it++) {
			result.push_back(it->second);
		}

		sort(result.begin(), result.end());

		return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> result;
	int i;

	result = s.diffWaysToCompute("11");
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	result = s.diffWaysToCompute("2-1-1");
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	result = s.diffWaysToCompute("2*3-4*5");
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
