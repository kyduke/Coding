//http://www.careercup.com/question?id=5196192088588288
#include <iostream>
#include <vector>

using namespace std;

void makeKCombination(vector<int>& num, int k, int n, int index, int start) {
	int i;

	if (index == k) {
		for (i = 0; i < k; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (i = start; i <= n; i++) {
		num[index] = i;
		makeKCombination(num, k, n, index + 1, i + 1);
	}
}

void printKCombination(int k, int n) {
	vector<int> num;
	int i;

	for (i = 0; i < k; i++) {
		num.push_back(0);
	}

	makeKCombination(num, k, n, 0, 1);
}

int main(int argc, char* argv[]) {
	printKCombination(1, 2);
	printKCombination(2, 3);

	return 0;
}
