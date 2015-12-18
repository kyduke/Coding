// http://careercup.com/question?id=5679154655657984

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void zigZagSort(vector<int>& arr) {
	vector<int> copy = arr;
	int i, k, n;

	sort(copy.begin(), copy.end());

	n = arr.size() * 2 - 1;
	for (i = 0; i < arr.size(); i++) {
		k = i * 2 + 1;
		if (k >= arr.size()) k = n - k;
		arr[k] = copy[i];
	}
}

void printArray(vector<int> arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	int data0[] = {1, 2, 3, 4, 5, 6, 7};
	int data1[] = {1, 2, 3, 4, 5, 6, 7, 8};

	arr.assign(data0, data0 + 7);
	zigZagSort(arr);
	printArray(arr);

	arr.assign(data1, data1 + 8);
	zigZagSort(arr);
	printArray(arr);

	return 0;
}
