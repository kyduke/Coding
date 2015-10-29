// http://careercup.com/question?id=5767394003779584

#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i != arr.size() - 1) cout << ", ";
	}
	cout << "\n";
}

void moveZeroToRight(vector<int>& arr) {
	int i, k;

	k = 0;
	for (i = 0; i < arr.size(); i++) {
		if (arr[i] != 0) {
			arr[k] = arr[i];
			k++;
		}
	}

	for (i = k; i < arr.size(); i++) {
		arr[i] = 0;
	}
}

int main(int argc, char* argv[]) {
	int data[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 0, 9, 0};
	vector<int> arr(data, data + 12);

	printArray(arr);

	moveZeroToRight(arr);

	printArray(arr);

	return 0;
}
