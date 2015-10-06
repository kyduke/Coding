// http://careercup.com/question?id=5154205616570368

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getKthElementFromSortedSubarray(vector<int> arr, int a, int b, int k) {
	vector<int> subarray;

	if (a > b || k > (b - a) || a >= arr.size() || b > arr.size()) return -1;

	subarray.assign(arr.begin() + a, arr.begin() + b);
	sort(subarray.begin(), subarray.end());
	return subarray[k];
}

int main(int argc, char* argv[]) {
	int nums[] = {3, 4, 5, 0, 1, 2};
	vector<int> arr;

	arr.assign(nums, nums + 6);
	cout << getKthElementFromSortedSubarray(arr, 2, 5, 2) << "\n";
	return 0;
}
