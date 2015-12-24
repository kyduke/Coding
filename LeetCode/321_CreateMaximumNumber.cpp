// https://leetcode.com/problems/create-maximum-number/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
	struct Node {
		int i;
		int n;
		int k;
		bool operator< (const Node& a) const {
			if (i == a.i) return n < a.n;
			return i < a.i;
		}
	};
	vector<int> getMaxSub(vector<int>& num, int n) {
		priority_queue<Node> q;
		vector<int> sub, maxN;
		Node node;
		int i;

		sub.assign(n + 1, -1);

		if (n == 0) return sub;

		maxN.assign(n, -1);

		node.i = 0;
		for (i = 0; i < num.size(); i++) {
			if (num.size() - i < n) break;
			if (maxN[0] >= num[i]) continue;
			node.n = num[i];
			node.k = i;
			q.push(node);
			maxN[0] = num[i];
			if (num[i] == 9) break;
		}

		while (!q.empty()) {
			node = q.top();
			q.pop();
			sub[node.i] = node.n;
			if (node.i == n - 1) break;
			node.i++;
			maxN[node.i] = -1;
			for (i = node.k + 1; i < num.size(); i++) {
				if (num.size() - i < n - node.i) break;
				if (maxN[node.i] >= num[i]) continue;
				node.n = num[i];
				node.k = i;
				q.push(node);
				maxN[node.i] = num[i];
				if (num[i] == 9) break;
			}
		}

		return sub;
	}
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret, temp, sub1, sub2;
		bool big, merged;
		int i, j, m, n, a, b;

		ret.assign(k, 0);
		temp.assign(k, 0);

		for (n = k; n >= 0; n--) {
			if (n > nums1.size() || k - n > nums2.size()) continue;
			sub1 = getMaxSub(nums1, n);
			sub2 = getMaxSub(nums2, k - n);

			i = 0;
			j = 0;
			m = 0;
			big = false;
			merged = true;
			while (m < k) {
				if (sub1[i] > sub2[j]) {
					temp[m] = sub1[i];
					i++;
				} else if (sub1[i] < sub2[j]) {
					temp[m] = sub2[j];
					j++;
				} else {
					a = i + 1;
					b = j + 1;
					while (true) {
						if (sub2[b] == -1 || sub1[a] > sub2[b]) {
							temp[m] = sub1[i];
							i++;
							break;
						}
						if (sub1[a] == -1 || sub1[a] < sub2[b]) {
							temp[m] = sub2[j];
							j++;
							break;
						}
						a++;
						b++;
					}
				}
				if (big == false) {
					if (temp[m] < ret[m]) {
						merged = false;
						break;
					} else if (temp[m] > ret[m]) {
						big = true;
					}
				}
				m++;
			}
			if (merged) ret = temp;
		}

		return ret;
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
	vector<int> nums1, nums2, result;
	int data1[] = {3, 4, 6, 5};
	int data2[] = {9, 1, 2, 5, 8, 3};
	int data3[] = {6, 7};
	int data4[] = {6, 0, 4};
	int data5[] = {3, 9};
	int data6[] = {8, 9};
	int data7[] = {2, 5, 6, 4, 4, 0};
	int data8[] = {7, 3, 8, 0, 6, 5, 7, 6, 2};
	int data9[] = {3, 8, 5, 3, 4};
	int data0[] = {8, 7, 3, 6, 8};

	nums1.clear();
	nums2.clear();
	nums1.assign(data1, data1 + 4);
	nums2.assign(data2, data2 + 6);
	result = s.maxNumber(nums1, nums2, 5);
	printArray(result);

	nums1.clear();
	nums2.clear();
	nums1.assign(data3, data3 + 2);
	nums2.assign(data4, data4 + 3);
	result = s.maxNumber(nums1, nums2, 5);
	printArray(result);

	nums1.clear();
	nums2.clear();
	nums1.assign(data5, data5 + 2);
	nums2.assign(data6, data6 + 2);
	result = s.maxNumber(nums1, nums2, 3);
	printArray(result);

	nums1.clear();
	nums2.clear();
	nums1.assign(data7, data7 + 6);
	nums2.assign(data8, data8 + 9);
	result = s.maxNumber(nums1, nums2, 15);
	printArray(result);

	nums1.clear();
	nums2.clear();
	nums1.assign(data9, data9 + 5);
	nums2.assign(data0, data0 + 5);
	result = s.maxNumber(nums1, nums2, 5);
	printArray(result);

	return 0;
}


/*
[3, 4, 6, 5]
[9, 1, 2, 5, 8, 3]
5
=====
[9, 8, 6, 5, 3]

[6, 7]
[6, 0, 4]
5
=====
[6, 7, 6, 0, 4]

[3, 9]
[8, 9]
3
=====
[9, 8, 9]

[2,5,6,4,4,0]
[7,3,8,0,6,5,7,6,2]
15
=====
[7,3,8,2,5,6,4,4,0,6,5,7,6,2,0]

[3,8,5,3,4]
[8,7,3,6,8]
5
=====
[8,8,8,5,4]
*/
