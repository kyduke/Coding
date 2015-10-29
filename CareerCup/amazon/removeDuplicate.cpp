// http://careercup.com/question?id=5747603499122688

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

// O(n^3)
int removeDupBruteForce(vector<int>& arr) {
	int i, k;

	i = 0;
	while (i < arr.size()) {
		k = i + 1;
		while (k < arr.size()) {
			if (arr[i] == arr[k]) {
				arr.erase(arr.begin() + k);
			} else {
				k++;
			}
		}
		i++;
	}

	return arr.size();
}

// O(n log n)
int removeDup(vector<int>& arr) {
	vector<int> result;
	set<int> s;
	int i, size;

	i = 0;
	size = 0;
	while (i < arr.size()) {
		s.insert(arr[i]);
		if (size != s.size()) {
			size = s.size();
			result.push_back(arr[i]);
		}
		i++;
	}
	arr = result;

	return arr.size();
}

int main(int argc, char* argv[]) {
	int data[] = {1, 1, 5, 3, 8, 3, 7, 32, 32};
	vector<int> arr(data, data + 9);

	printArray(arr);

	cout << removeDup(arr) << "\n";

	printArray(arr);

	return 0;
}
