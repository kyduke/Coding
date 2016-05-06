// https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret, temp;
		map<int, int> m1;
		map<int, int>::iterator itm1;
		map<int, vector<int>> m2;
		map<int, vector<int>>::iterator itm2;
		map<int, vector<int>>::reverse_iterator itm2r;
		int i;

		temp = nums;
		sort(temp.begin(), temp.end());

		for (i = 0; i < temp.size(); i++) {
			itm1 = m1.find(temp[i]);
			if (itm1 == m1.end()) {
				m1.insert(make_pair(temp[i], 1));
			} else {
				itm1->second++;
			}
		}

		for (itm1 = m1.begin(); itm1 != m1.end(); itm1++) {
			itm2 = m2.find(itm1->second);
			if (itm2 == m2.end()) {
				temp.clear();
				temp.push_back(itm1->first);
				m2.insert(make_pair(itm1->second, temp));
			} else {
				itm2->second.push_back(itm1->first);
			}
		}

		for (itm2r = m2.rbegin(); itm2r != m2.rend(); itm2r++) {
			temp = itm2r->second;
			for (i = 0; i < temp.size(); i++) {
				ret.push_back(temp[i]);
				k--;
				if (k == 0) break;
			}
			if (k == 0) break;
		}

		return ret;
    }
};

void printArray(vector<int> arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums, result;
	int data[] = {1, 1, 1, 2, 2, 3};

	nums.assign(data, data + 6);

	result = s.topKFrequent(nums, 2);
	printArray(result);

	return 0;
}

/*
[1, 1, 1, 2, 2, 3], 2
=====
[1, 2]
*/
