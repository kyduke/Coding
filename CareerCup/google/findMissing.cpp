// http://www.careercup.com/question?id=5633053969874944

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int UINT32;

void printArray(vector<UINT32>& arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void findMissing(vector<UINT32>& arr) {
	int i, j;
	UINT32 last, start, prev, count, firstFrom, firstTo, secondFrom, secondTo;

	if (arr.size() == 0) return;
	if (arr.size() == 1) {
		arr[0] = (arr[0] + 1) % 2;
		return;
	}

	sort(arr.begin(), arr.end());

	last = arr.size() + arr.size() - 1;

	// find continuous sequence
	start = last;
	prev = last;
	count = 0;
	for (i = 0; i < arr.size(); i++) {
		if (prev + 1 == arr[i]) {
			count++;
			if (count > 3) {
				arr[i - 3] = last;
				arr[i - 2] = start;
				arr[i - 1] = start;
			}
		} else {
			start = arr[i];
			count = 1;
		}
		prev = arr[i];
	}

	// move empty element to first
	for (i = arr.size() - 2; i > 0; i--) {
		if (arr[i] != last) continue;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] == last) continue;
			arr[i] = arr[j];
			arr[j] = last;
			break;
		}
	}

	// skip empty space
	for (i = 0; i < arr.size(); i++) {
		if (arr[i] != last) break;
	}
	j = 0;
	firstFrom = 0;
	firstTo = 0;
	secondFrom = 0;
	secondTo = 0;
	while (j < arr.size()) {
		// find first empty sequency
		firstFrom = secondTo;
		firstTo = secondTo;
		for (; i < arr.size(); i++) {
			if (arr[i] <= firstFrom || (i > 2 && arr[i - 2] == arr[i - 1])) {
				firstFrom = arr[i] + 1;
				firstTo = last + 1;
			} else {
				firstTo = arr[i];
				break;
			}
		}

		// find second empty sequency
		secondFrom = firstTo;
		secondTo = firstTo;
		for (; i < arr.size(); i++) {
			if (arr[i] <= secondFrom || (i > 2 && arr[i - 2] == arr[i - 1])) {
				secondFrom = arr[i] + 1;
				secondTo = last + 1;
			} else {
				secondTo = arr[i];
				break;
			}
		}
		
		for (; j < arr.size(); j++) {
			if (firstFrom == firstTo) break;
			arr[j] = firstFrom;
			firstFrom++;
		}

		for (; j < arr.size(); j++) {
			if (secondFrom == secondTo) break;
			arr[j] = secondFrom;
			secondFrom++;
		}
	}
}

int main(int argc, char* argv[]) {
	//UINT32 data[] = {0, 3, 4, 5, 6};
	//UINT32 data[] = {0, 2, 4, 6, 8};
	UINT32 data[] = {0, 2, 4, 12, 13, 14, 15, 16, 17, 18};
	vector<UINT32> arr;

	//arr.assign(data, data + 5);
	arr.assign(data, data + 10);

	printArray(arr);

	findMissing(arr);

	printArray(arr);

	return 0;
}
