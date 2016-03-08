// https://careercup.com/question?id=5650516169195520

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countOfMeltDownBruteForce(vector<int>& arr) {
	vector<int> a, b;
	int i, count;

	a = arr;

	count = -1;
	for (i = 0; i < a.size(); i++) {
		if (a[i] != 0) {
			count = 0;
			break;
		}
	}

	if (count == -1) return 0;

	while (a.size()) {
		count++;
		b.clear();
		for (i = 1; i < a.size() - 1; i++) {
			if (a[i] > 1 && a[i - 1] > 0 && a[i + 1] > 0) {
				b.push_back(a[i] - 1);
			}
		}
		a = b;
	}

	return count;
}

int countOfMeltDown(vector<int>& arr) {
	vector<int> mins;
	int i, k, count;

	mins.assign(arr.size(), 0);

	count = 0;
	for (i = 0, k = 1; i < arr.size(); i++, k++) {
		mins[i] = min(arr[i], k);
		if (arr[i] <= 0) k = 0;
	}

	for (i = arr.size() - 1, k = 1; i >= 0; i--, k++) {
		count = max(count, min(mins[i], min(arr[i], k)));
		if (arr[i] <= 0) k = 0;
	}

	return count;
}

int main(int argc, char* argv[]) {
	int data[] = {5, 4, 3, 6, 0, 1};
	vector<int> arr;

	arr.assign(data, data + 6);
	cout << countOfMeltDownBruteForce(arr) << "\n";
	cout << countOfMeltDown(arr) << "\n";

	return 0;
}

/*
[5, 4, 3, 6, 0, 1] => [0, 3, 2, 0, 0, 0] => [0, 0, 0, 0, 0, 0]
=====
2

[0, 1, 1, 1, 1, 0] => [0, 0, 0, 0, 0, 0]
=====
1
*/
