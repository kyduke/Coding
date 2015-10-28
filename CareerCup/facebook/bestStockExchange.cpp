// http://careercup.com/question?id=5180595304923136

#include <iostream>
#include <vector>

using namespace std;

int bestStockExchange(vector<int>& arr) {
	int best, i, low;

	if (arr.size() == 0) return 0;

	best = 0;
	low = arr[0];
	for (i = 1; i < arr.size(); i++) {
		if (arr[i] < low) {
			low = arr[i];
		} else {
			best = max(best, arr[i] - low);
		}
	}

	return best;
}

int main(int argc, char* argv[]) {
	int data[] = {10, 30, 42, 15, 20, 50, 10, 25};
	vector<int> arr(data, data + 8);

	cout << bestStockExchange(arr) << "\n";

	return 0;
}
