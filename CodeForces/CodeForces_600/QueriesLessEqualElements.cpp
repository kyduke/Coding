// http://codeforces.com/problemset/problem/600/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	vector<int> a;
	vector<int>::iterator it;
	int n, m, i;

	cin >> n >> m;

	a.assign(n, 0);

	i = 0;
	while (i < n) {
		cin >> a[i];
		i++;
	}
	sort(a.begin(), a.end());

	i = 0;
	while (i < m) {
		cin >> n;
		i++;

		it = upper_bound(a.begin(), a.end(), n);
		cout << distance(a.begin(), it) << " ";
	}
	cout << "\n";

	return 0;
}

/*
5 4
1 3 5 7 9
6 4 2 8
=====
3 2 1 4

5 5
1 2 1 2 5
3 1 4 1 5
=====
4 2 4 2 5
*/
