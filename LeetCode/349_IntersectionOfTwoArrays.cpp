// https://leetcode.com/problems/intersection-of-two-arrays/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a, b;
		set<int>::iterator it;
		vector<int> result;
		int i;

		for (i = 0; i < nums1.size(); i++) {
			a.insert(nums1[i]);
		}

		for (i = 0; i < nums2.size(); i++) {
			if (a.find(nums2[i]) != a.end()) {
				b.insert(nums2[i]);
			}
		}

		for (it = b.begin(); it != b.end(); it++) {
			result.push_back(*it);
		}

		return result;
    }
};

void printArray(vector<int>& arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> a, b, c;
	int dataA[] = {1, 2, 2, 1};
	int dataB[] = {2, 2};

	a.assign(dataA, dataA + 4);
	b.assign(dataB, dataB + 2);

	c = s.intersection(a, b);
	printArray(c);

	return 0;
}

/*
[1, 2, 2, 1], [2, 2]
=====
[2]
*/
