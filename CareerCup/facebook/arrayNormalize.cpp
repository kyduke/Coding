// https://careercup.com/question?id=5643607445864448

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<int>& arr) {
	int i;

	for (i= 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void addAndNormalize(vector<int>& arr, int n) {
	vector<int>::iterator it;
	int r;

	r = n;
	if (arr.size() == 0) {
		arr.push_back(n);
		r = 0;
	}

	reverse(arr.begin(), arr.end());

	it = arr.begin();
	while (true) {
		*it += r;
		r = *it / 10;
		if (r == 0) break;
		*it %= 10;
		it++;
		if (it == arr.end()) {
			it = arr.insert(it, r);
			r = 0;
		}
	}

	reverse(arr.begin(), arr.end());
}


int main(int argc, char* argv[]) {
	vector<int> arr;
	int i;

	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(1);
	for (i = 1; i < 20; i++) {
		addAndNormalize(arr, i);
		printArray(arr);
	}

	return 0;
}
