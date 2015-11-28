// https://www.hackerrank.com/challenges/fibonacci-modified

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> calculated[20];
vector<int> a;
vector<int> b;
int A, B;

void normalize(vector<int>& arr) {
	int i, n;

	i = 0;
	while (i < arr.size()) {
		n = arr[i];
		arr[i] = n % 10;
		n /= 10;
		if (n != 0) {
			if (i + 1 < arr.size()) {
				arr[i + 1] += n;
			} else {
				arr.push_back(n);
			}
		}
		i++;
	}

	i = arr.size() - 1;
	while (i > 0) {
		if (arr[i] != 0) break;
		arr.erase(arr.begin() + i);
		i--;
	}
}

vector<int> addArray(vector<int>& a, vector<int>& b) {
	vector<int> ret;
	int len, i, x, y;

	len = max(a.size(), b.size());
	ret.assign(len, 0);

	i = 0;
	while (i < a.size() || i < b.size()) {
		x = 0;
		y = 0;
		if (i < a.size()) x = a[i];
		if (i < b.size()) y = b[i];
		ret[i] = x + y;
		i++;
	}

	normalize(ret);

	return ret;
}

vector<int> multiplyArray(vector<int>& a, vector<int>& b) {
	vector<int> ret;
	int i, j;

	ret.assign(a.size() + b.size(), 0);

	for (i = 0; i < a.size(); i++) {
		for (j = 0; j < b.size(); j++) {
			ret[i + j] += a[i] * b[j];
		}
	}

	normalize(ret);

	return ret;
}

void printArray(vector<int>& arr) {
	int i;

	for (i = arr.size() - 1; i >= 0; i--) {
		cout << arr[i];
	}
	cout << "\n";
}

vector<int> fibonacciModified(int n) {
	vector<int> x, x2, y;

	if (n == 0) return a;
	if (n == 1) return b;

	if (calculated[n].size() > 0) return calculated[n];

	x = fibonacciModified(n - 1);
	y = fibonacciModified(n - 2);

	x2 = multiplyArray(x, x);
	calculated[n] = addArray(x2, y);

	return calculated[n];
}

int main(int argc, char* argv[]) {
	vector<int> result;
	int n;

	cin >> A >> B >> n;

	if (A == 0 && B == 0) {
		cout << "0\n";
	} else  {
		a.push_back(A);
		b.push_back(B);

		result = fibonacciModified(n - 1);

		printArray(result);
	}

	return 0;
}

/*
0 1 5
=====
5

0 1 10
=====
84266613096281243382112
*/
