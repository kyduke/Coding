// https://www.hackerrank.com/contests/hourrank-14/challenges/lilys-homework

// https://www.hackerrank.com/contests/hourrank-14/challenges/lilys-homework

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solve(vector<int>& arr) {
	vector<int> cpy, tmp;
	map<int, int> m;
	int ans, i, x, y, t;

	cpy = arr;
	tmp = arr;

	sort(cpy.begin(), cpy.end());

	for (i = 0; i < cpy.size(); i++) {
		m[cpy[i]] = i;
	}

	x = 0;
	for (i = 0; i < tmp.size(); i++) {
		if (tmp[i] != cpy[i]) {
			t = tmp[i];
			tmp[i] = tmp[m[tmp[i]]];
			tmp[m[t]] = t;
			x++;
			i--;
		}
	}

	reverse(cpy.begin(), cpy.end());

	m.clear();
	for (i = 0; i < cpy.size(); i++) {
		m[cpy[i]] = i;
	}

	tmp = arr;

	y = 0;
	for (i = 0; i < tmp.size(); i++) {
		if (tmp[i] != cpy[i]) {
			t = tmp[i];
			tmp[i] = tmp[m[tmp[i]]];
			tmp[m[t]] = t;
			y++;
			i--;
		}
	}

	ans = min(x, y);

	return ans;
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	int n, i;

	cin >> n;
	arr.assign(n, 0);
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << solve(arr) << "\n";

	return 0;
}

/*
4
2 5 3 1
=====
2
*/
