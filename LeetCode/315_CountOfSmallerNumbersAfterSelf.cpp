// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
	struct Node {
		int value;
		int count;
	};
	vector<Node> tree;
	void insert(int n) {
		int h;

		h = 0;
		while (h < tree.size()) {
			if (tree[h].count == -1) {
				tree[h].value = n;
				tree[h].count = 0;
				break;
			}
			if (tree[h].value > n) {
				h = h * 2 + 1;
			} else if (tree[h].value < n) {
				h = h * 2 + 2;
			} else {
				break;
			}
		}
	}
	int getCount(int n) {
		int h, cnt;

		cnt = 0;

		h = 0;
		while (h < tree.size()) {
			if (tree[h].count == -1) break;
			if (tree[h].value > n) {
				tree[h].count++;
				h = h * 2 + 1;
			} else if (tree[h].value < n) {
				cnt += tree[h].count;
				h = h * 2 + 2;
			} else {
				tree[h].count++;
				h = h * 2 + 1;
				if (h < tree.size() && tree[h].count != -1) {
					cnt += tree[h].count;
					h = h * 2 + 2;
					while (h < tree.size() && tree[h].count != -1) {
						cnt += tree[h].count;
						h = h * 2 + 2;
					}
				}
				break;
			}
		}

		return cnt;
	}
public:
    vector<int> countSmaller(vector<int>& nums) {
		vector<int> result;
		vector<int> sorted;
		set<int> ss;
		set<int>::iterator it;
		queue<pair<int, int>> q;
		Node node;
		int i, left, right, mid;

		result.assign(nums.size(), 0);

		for (i = 0; i < nums.size(); i++) {
			ss.insert(nums[i]);
		}

		sorted.assign(ss.size(), 0);
		for (it = ss.begin(), i = 0; it != ss.end(); it++, i++) {
			sorted[i] = *it;
		}
		ss.clear();

		node.value = 0;
		node.count = -1;
		tree.clear();
		tree.assign(sorted.size() * 2, node);

		q.push(make_pair(0, sorted.size() - 1));
		while (!q.empty()) {
			left = q.front().first;
			right = q.front().second;
			q.pop();
			if (left > right) continue;
			mid = (left + right) / 2;
			insert(sorted[mid]);
			q.push(make_pair(left, mid - 1));
			q.push(make_pair(mid + 1, right));
		}

		for (i = nums.size() - 1; i >= 0; i--) {
			result[i] = getCount(nums[i]);
		}

		return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums, result;
	int data[] = {5, 2, 6, 1};
	int i;

	nums.assign(data, data + 5);
	result = s.countSmaller(nums);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
[5, 2, 6, 1]
=====
[2, 1, 1, 0]
*/
