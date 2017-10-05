// A string with digits, find Nth permutation number.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calcMaxValueWithoutZero(int n) {
	int i, k, x;
	
	x = 0;
	for (i = 9; i > 0; i--) {
		k = n;
		while (k) {
			if (k % 10 == i) x = x * 10 + i;
			k /= 10;
		}
	}
	
	return x;
}

int main() {
	string str = "20171005";
	vector<int> arr;
	int i, minValue, maxValue, maxValueWithoutZero, cnt, target;
	
	for (i = 0; i < str.size(); i++) {
		arr.push_back(str[i] - '0');
	}
	sort(arr.begin(), arr.end());
	
	minValue = 0;
	maxValue = 0;
	for (i = 0; i < arr.size(); i++) {
		minValue = minValue * 10 + arr[i];
		maxValue = maxValue * 10 + arr[arr.size() - i - 1];
	}
	
	cnt = 0;
	target = 127;
	maxValueWithoutZero = calcMaxValueWithoutZero(maxValue);
	for (i = minValue; i <= maxValue; i++) {
		if (calcMaxValueWithoutZero(i) == maxValueWithoutZero) {
			cnt++;
			cout << cnt << ": " << i << "\n";
			if (cnt == target) break;
		}
	}
	
	if (cnt == target) {
		cout << i << "\n";
	} else {
		cout << "-1\n";
	}
	
	return 0;
}
