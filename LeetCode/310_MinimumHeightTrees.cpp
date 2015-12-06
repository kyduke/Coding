// https://leetcode.com/problems/minimum-height-trees/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<vector<int>> links;
		vector<int> cnt;
        vector<int> nodes;
		set<int> leafs, temp;
		set<int>::iterator it;
		int i, m, x, y;

		if (n < 2) {
			if (n == 1) nodes.push_back(0);
			return nodes;
		}

		for (i = 0; i < n; i++) {
			links.push_back(nodes);
		}

		cnt.assign(n, 0);
		for (i = 0; i < edges.size(); i++) {
			x = edges[i].first;
			y = edges[i].second;
			links[x].push_back(y);
			links[y].push_back(x);
			cnt[x]++;
			cnt[y]++;
		}

		for (i = 0; i < n; i++) {
			if (cnt[i] == 1) {
				leafs.insert(i);
			}
		}
		
		m = n;
		while (m > 2 && leafs.size()) {
			if (m - leafs.size() <= 2) {
				for (it = leafs.begin(); it != leafs.end(); it++) {
					x = *it;
					cnt[x]--;
				}
				break;
			}
			for (it = leafs.begin(); it != leafs.end(); it++) {
				x = *it;
				cnt[x]--;
				m--;
				for (i = 0; i < links[x].size(); i++) {
					y = links[x][i];
					cnt[y]--;
					if (cnt[y] == 1) {
						temp.insert(y);
					}
				}
			}
			leafs = temp;
			temp.clear();
		}

		for (i = 0; i < n; i++) {
			if (cnt[i] > 0) {
				nodes.push_back(i);
			}
		}

		return nodes;
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
	vector<pair<int, int>> edges;
	vector<int> nodes;

	edges.push_back(make_pair(1, 0));
	edges.push_back(make_pair(1, 2));
	edges.push_back(make_pair(1, 3));
	nodes = s.findMinHeightTrees(4, edges);
	printArray(nodes);

	edges.clear();
	edges.push_back(make_pair(0, 3));
	edges.push_back(make_pair(1, 3));
	edges.push_back(make_pair(2, 3));
	edges.push_back(make_pair(4, 3));
	edges.push_back(make_pair(5, 4));
	nodes = s.findMinHeightTrees(6, edges);
	printArray(nodes);

	edges.clear();
	edges.push_back(make_pair(0, 1));
	edges.push_back(make_pair(1, 2));
	edges.push_back(make_pair(1, 3));
	edges.push_back(make_pair(2, 4));
	edges.push_back(make_pair(3, 5));
	edges.push_back(make_pair(4, 6));
	nodes = s.findMinHeightTrees(7, edges);
	printArray(nodes);

	return 0;
}

/*
n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3

return [1]

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

return [3, 4]

Given n = 7, edges = [[0,1],[1,2],[1,3],[2,4],[3,5],[4,6]]

return [1, 2]
*/
