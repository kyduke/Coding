// http://careercup.com/question?id=5631660689195008

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void printArray(vector<int>& arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i != arr.size() - 1) cout << ", ";
	}
	cout << "\n";
}

vector<int> remainGreaterCount(vector<int>& arr) {
	multiset<int> s;
	multiset<int>::iterator it;
	vector<int> result;
	int i, j;

	result.assign(arr.size(), 0);
	for (i = arr.size() - 1; i >= 0; i--) {
		s.insert(arr[i]);
		it = s.upper_bound(arr[i]);
		result[i] = distance(it, s.end());
	}

	return result;
}

int main(int argc, char* argv[]) {
	int data[] = {3, 4, 5, 9, 2, 1, 3};
	vector<int> arr(data, data + 7);
	vector<int> result;

	result = remainGreaterCount(arr);

	printArray(arr);
	printArray(result);

	return 0;
}
