// http://codeforces.com/contest/606/problem/C

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	vector<int> nums;
	set<int> ss;
	set<int>::iterator it;
	map<int, int> mm;
	map<int, int>::iterator mit;
	int n, p, i, maxCnt;

	cin >> n;
	while (n--) {
		cin >> p;
		nums.push_back(p);
		ss.insert(p);
	}

	mm.insert(make_pair(nums[0], 1));
	for (i = 1; i < nums.size(); i++) {
		it = ss.find(nums[i]);
		if (it != ss.begin()) {
			it--;
			mit = mm.find(*it);
			if (mit != mm.end()) {
				mm.insert(make_pair(nums[i], mit->second + 1));
				mm.erase(mit);
			} else {
				mm.insert(make_pair(nums[i], 1));
			}
		} else {
			mm.insert(make_pair(nums[i], 1));
		}
	}

	maxCnt = 0;
	for (mit = mm.begin(); mit != mm.end(); mit++) {
		if (maxCnt < mit->second) maxCnt = mit->second;
	}

	cout << (nums.size() - maxCnt) << "\n";

	return 0;
}

/*
5
4 1 2 5 3
=====
2

4
4 1 3 2
=====
2
*/
