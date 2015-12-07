// https://www.hackerrank.com/challenges/largest-permutation

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char* argv[]) {
	priority_queue<pair<int, int>> pq;
	vector<int> arr, sortedValues, sortedIndex;
	int n, k, i, j, a, v, idx;

	cin >> n >> k;
	arr.assign(n, 0);
	i = 0;
	while (i < n) {
		cin >> arr[i];
		pq.push(make_pair(arr[i], i));
		i++;
	}

	sortedValues.assign(n, 0);
	sortedIndex.assign(n, 0);

	i = 0;
	while (!pq.empty()) {
		sortedValues[i] = pq.top().first;
		sortedIndex[i] = pq.top().second;
		pq.pop();
		i++;
	}

	i = 0;
	j = 0;
	while (true) {
		if (sortedIndex[j] == i) {
			i++;
			j++;
		}
		while (j < n) {
			v = sortedValues[j];
			idx = sortedIndex[j];
			if (idx > i) break;
			j++;
		}
		if (j == n) break;
		while (i < n) {
			if (arr[i] < v) break;
			i++;
		}
		if (i == n) break;
		for (a = j + 1; a < n; a++) {
			if (sortedIndex[a] == i) {
				sortedIndex[a] = idx;
				break;
			}
		}
		sortedIndex[j] = i;
		arr[idx] = arr[i];
		arr[i] = v;
		i++;
		j++;

		k--;
		if (k == 0) break;
	}

	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
5 1
4 2 3 5 1
=====
5 2 3 4 1
*/
