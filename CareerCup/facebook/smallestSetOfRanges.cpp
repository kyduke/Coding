// http://careercup.com/question?id=6262661043978240

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printPairArray(vector<pair<int, int>>& arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << "(" << arr[i].first << ", " << arr[i].second << ") ";
	}
	cout << "\n";
}

struct Compare {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
};

vector<pair<int, int>> smallestSetOfRanges(vector<pair<int, int>>& ranges, pair<int, int> R) {
	vector<pair<int, int>> result;
	int target, i, maxTarget, maxIndex;

	sort(ranges.begin(), ranges.end(), Compare());

	target = R.first;
	maxIndex = 0;
	while (target < R.second) {
		maxTarget = target;
		for (i = maxIndex; i < ranges.size(); i++) {
			if (ranges[i].first <= target && ranges[i].second >= maxTarget) {
				maxTarget = ranges[i].second;
				maxIndex = i;
			} else if (ranges[i].first > target) {
				break;
			}
		}
		result.push_back(ranges[maxIndex]);
		target = maxTarget;
	}

	return result;
}

int main(int argc, char* argv[]) {
	vector<pair<int, int>> ranges;
	vector<pair<int, int>> result;

	ranges.push_back(make_pair(1, 4));
	ranges.push_back(make_pair(30, 40));
	ranges.push_back(make_pair(20, 91));
	ranges.push_back(make_pair(8, 10));
	ranges.push_back(make_pair(6, 7));
	ranges.push_back(make_pair(3, 9));
	ranges.push_back(make_pair(9, 12));
	ranges.push_back(make_pair(11, 14));

	result = smallestSetOfRanges(ranges, make_pair(3, 13));

	printPairArray(result);

	return 0;
}
