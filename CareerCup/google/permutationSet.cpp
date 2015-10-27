// http://careercup.com/question?id=5101575825522688

#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr) {
	int i;

	cout << "{";
	for (i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i != arr.size() - 1) cout << ", ";
	}
	cout << "}";
}

bool nextIndex(vector<int>& indexes, int size) {
	int i, up;

	up = 0;
	i = indexes.size() - 1;
	indexes[i]++;
	while (i >= 0) {
		indexes[i] += up;
		if (indexes[i] < size) return true;
		indexes[i] = 0;
		up = 1;
		i--;
	}

	return false;
}

vector<vector<int>> getPermutation(vector<int>& arr, int n) {
	vector<vector<int>> permutations;
	
	if (arr.size() == 0 || n <= 0 || arr.size() < n) return permutations;

	vector<int> indexes;
	vector<int> item;
	int i;

	indexes.assign(n, 0);

	while (true) {
		item.clear();
		for (i = 0; i < indexes.size(); i++) {
			item.push_back(arr[ indexes[i] ]);
		}
		permutations.push_back(item);
		if (nextIndex(indexes, arr.size()) == false) break;
	}

	return permutations;
}

int main(int argc, char* argv[]) {
	int data[] = {2, 3, 4};
	vector<int> arr(data, data + 3);
	vector<vector<int>> permutations;
	int i;

	printArray(arr);
	cout << "\n";

	permutations = getPermutation(arr, 2);

	for (i = 0; i < permutations.size(); i++) {
		printArray(permutations[i]);
		if (i != permutations.size() - 1) cout << ", ";
	}
	cout << "\n";

	return 0;
}
