// http://careercup.com/question?id=5676298150084608

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct sort_first_second {
    bool operator()(const pair<int, int>& left, const pair<int, int>& right) {
		if (left.first != right.first) return left.first < right.first;
        return left.second < right.second;
    }
};

void optimizeArray(vector<pair<int, int>>& arr) {
	vector<pair<int, int>> result;
	int i, limit, start, end, index;

	if (arr.size() == 0) return;

	sort(arr.begin(), arr.end(), sort_first_second());

	limit = arr[arr.size() - 1].second;
	start = arr[0].first;
	end = start;
	i = 0;
	while (end < limit) {
		index = -1;
		while (i < arr.size()) {
			if (arr[i].first <= start) {
				if (arr[i].second > end) {
					end = arr[i].second;
					index = i;
				}
			} else {
				if (index == -1) {
					start = arr[i].first;
				}
				break;
			}
			i++;
		}
		if (index != -1) {
			start = end;
			result.push_back(arr[index]);
		}
	}

	arr = result;
}

void printArray(vector<pair<int, int>>& arr) {
	int i;

	cout << "[";
	for (i = 0; i < arr.size(); i++) {
		cout << "(" << arr[i].first << "," << arr[i].second << ")";
		if (i < arr.size() - 1) cout << ",";
	}
	cout << "]\n";
}

int main(int argc, char* argv[]) {
	vector<pair<int, int>> arr;

	arr.push_back(make_pair(2, 6));
	arr.push_back(make_pair(3, 5));
	arr.push_back(make_pair(7, 21));
	arr.push_back(make_pair(20, 21));

	printArray(arr);

	optimizeArray(arr);

	printArray(arr);

	return 0;
}
