// https://leetcode.com/problems/self-crossing/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
	map<int, vector<pair<int, int>>> xs, ys;
	int currX, currY;

	bool checkCrossingX(int startY, int endY) {
		map<int, vector<pair<int, int>>>::iterator it;
		vector<pair<int, int>> ps;
		pair<int, int> p;
		int s, e, i, j;

		s = min(startY, endY);
		e = max(startY, endY);

		for (i = s; i <= e; i++) {
			if (i == startY) continue;
			it = ys.find(i);
			if (it != ys.end()) {
				for (j = 0; j < it->second.size(); j++) {
					if (it->second[j].first <= currX && currX <= it->second[j].second) return true;
				}
			}
		}

		p.first = s;
		p.second = e;

		it = xs.find(currX);
		if (it != xs.end()) {
			for (i = 0; i < it->second.size(); i++) {
				if (startY <= it->second[i].second && it->second[i].first <= endY) return true;
			}
			it->second.push_back(p);
		} else {
			ps.clear();
			ps.push_back(p);
			xs.insert(make_pair(currX, ps));
		}

		return false;
	}
	bool checkCrossingY(int startX, int endX) {
		map<int, vector<pair<int, int>>>::iterator it;
		vector<pair<int, int>> ps;
		pair<int, int> p;
		int s, e, i, j;

		s = min(startX, endX);
		e = max(startX, endX);

		for (i = s; i <= e; i++) {
			if (i == startX) continue;
			it = xs.find(i);
			if (it != xs.end()) {
				for (j = 0; j < it->second.size(); j++) {
					if (it->second[j].first <= currY && currY <= it->second[j].second) return true;
				}
			}
		}

		p.first = s;
		p.second = e;

		it = ys.find(currY);
		if (it != ys.end()) {
			for (i = 0; i < it->second.size(); i++) {
				if (startX <= it->second[i].second && it->second[i].first <= endX) return true;
			}
			it->second.push_back(p);
		} else {
			ps.clear();
			ps.push_back(p);
			ys.insert(make_pair(currY, ps));
		}

		return false;
	}
public:
    bool isSelfCrossing(vector<int>& x) {
		map<int, vector<pair<int, int>>>::iterator it;
		int dir, i, p;

		dir = 0;
		currX = 0;
		currY = 0;
		for (i = 0; i < x.size(); i++) {
			if (dir == 0) {
				dir = 1;
				p = currY;
				currY += x[i];
				if (checkCrossingX(p, currY) == true) return true;
			} else if (dir == 1) {
				dir = 2;
				p = currX;
				currX -= x[i];
				if (checkCrossingY(p, currX) == true) return true;
			} else if (dir == 2) {
				dir = 3;
				p = currY;
				currY -= x[i];
				if (checkCrossingX(p, currY) == true) return true;
			} else {
				dir = 0;
				p = currX;
				currX += x[i];
				if (checkCrossingY(p, currX) == true) return true;
			}
		}

		return false;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	//int nums[] = {2, 1, 1, 2};
	//int nums[] = {1, 2, 3, 4};
	//int nums[] = {1, 1, 1, 1};
	int nums[] = {1, 1, 2, 1, 1};
	vector<int> arr;

	//arr.assign(nums, nums + 4);
	arr.assign(nums, nums + 5);

	cout << s.isSelfCrossing(arr) << "\n";

	return 0;
}

/*
2, 1, 1, 2
=====
true

1, 2, 3, 4
=====
false

1, 1, 1, 1
=====
true
*/
