// http://codeforces.com/problemset/problem/624/B

#include <iostream>
#include <vector>
#include <set>

typedef unsigned long long UINT64;

using namespace std;

UINT64 solve(vector<int>& arr) {
	set<int> s;
	set<int>::iterator it;
	int i, a;
	UINT64 ret;

	ret = 0;
	for (i = 0; i < arr.size(); i++) {
		a = arr[i];
		while (a) {
			if (s.find(a) == s.end()) {
				s.insert(a);
				ret += a;
				break;
			}
			a--;
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int n, a;
	vector<int> arr;

	cin >> n;
	while (n--) {
		cin >> a;
		arr.push_back(a);
	}

	cout << solve(arr) << "\n";

	return 0;
}

/*
3
2 5 5
=====
11

3
1 1 2
=====
3
*/
