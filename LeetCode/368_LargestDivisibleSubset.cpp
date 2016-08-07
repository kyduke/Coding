// https://leetcode.com/problems/largest-divisible-subset/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	struct Node {
		int count;
		int next;
	};
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<Node> nodes;
        vector<int> answer;
		Node node;
		int i, j, l, maxCount, maxIndex;

		if (nums.size() == 0) return answer;

		sort(nums.begin(), nums.end());

		l = nums.size();
		node.count = 1;
		node.next = -1;
		for (i = 0; i < l; i++) {
			nodes.push_back(node);
		}

		maxCount = 0;
		maxIndex = 0;
		for (i = l - 1; i >= 0; i--) {
			node.count = 0;
			node.next = -1;
			for (j = i + 1; j < l; j++) {
				if (nums[j] % nums[i] == 0) {
					if (node.count < nodes[j].count) {
						node.count = nodes[j].count;
						node.next = j;
					}
				}
			}
			nodes[i].count += node.count;
			nodes[i].next = node.next;
			if (maxCount < nodes[i].count) {
				maxCount = nodes[i].count;
				maxIndex = i;
			}
		}

		i = maxIndex;
		while(i >= 0) {
			answer.push_back(nums[i]);
			i = nodes[i].next;
		}

		return answer;
    }
};

void printArray(vector<int>& arr) {
	int i, l;

	l = arr.size();
	cout << "[";
	for (i = 0; i < l - 1; i++) {
		cout << arr[i] << ", ";
	}
	if (l > 0) cout << arr[ arr.size() - 1 ];
	cout << "]\n";
}

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> arr;
	int data1[] = {1, 2, 3};
	int data2[] = {1, 2, 4, 8};
	int data3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int data4[] = {2, 3, 5, 6, 7};
	
	arr.assign(data1, data1 + 3);
	printArray(arr);
	arr = s.largestDivisibleSubset(arr);
	printArray(arr);

	cout << "\n";

	arr.assign(data2, data2 + 4);
	printArray(arr);
	arr = s.largestDivisibleSubset(arr);
	printArray(arr);

	cout << "\n";

	arr.assign(data3, data3 + 10);
	printArray(arr);
	arr = s.largestDivisibleSubset(arr);
	printArray(arr);

	cout << "\n";

	arr.assign(data4, data4 + 5);
	printArray(arr);
	arr = s.largestDivisibleSubset(arr);
	printArray(arr);

	cout << "\n";
	
	arr.clear();
	printArray(arr);
	arr = s.largestDivisibleSubset(arr);
	printArray(arr);
	
	cout << "\n";
	
	arr.clear();
	arr.push_back(1);
	printArray(arr);
	arr = s.largestDivisibleSubset(arr);
	printArray(arr);
	
	cout << "\n";
	
	arr.clear();
	arr.push_back(100);
	printArray(arr);
	arr = s.largestDivisibleSubset(arr);
	printArray(arr);

	return 0;
}

/*
[1, 2, 3]
=====
[1, 2]

[1, 2, 4, 8]
=====
[1, 2, 4, 8]
*/
