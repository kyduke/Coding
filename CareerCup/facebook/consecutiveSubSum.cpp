// http://careercup.com/question?id=5681862682869760

#include <iostream>
#include <vector>

using namespace std;

typedef long long INT64;

bool consecutiveSubSum(vector<int>& arr, int target) {
	vector<INT64> subsum;
	int i, j;

	subsum.assign(arr.size() + 1, 0);

	for (i = 0; i < arr.size(); i++) {
		subsum[i + 1] = subsum[i] + arr[i];
	}

	for (i = 0; i < subsum.size(); i++) {
		for (j = 0; j < i; j++) {
			if (subsum[i] - subsum[j] == target) return true;
		}
	}

	return false;
}

int main(int argc, char* argv[]) {
	int data[] = {1, 3, 5, 7, 11};
	vector<int> arr(data, data + 5);

	cout << consecutiveSubSum(arr, 8) << "\n";
	cout << consecutiveSubSum(arr, 10) << "\n";
	cout << consecutiveSubSum(arr, 11) << "\n";
	cout << consecutiveSubSum(arr, 27) << "\n";

	return 0;
}
