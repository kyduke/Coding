// http://codeforces.com/contest/723/problem/C

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int SIZE = 2001;

int arr[SIZE] = {0, };
int count[SIZE] = {0, };
vector<int> idxs[SIZE];
vector<int> others;

void solve(int n, int m, int other) {
	multimap<int, int> mm;
	multimap<int, int>::iterator it;
	multimap<int, int>::iterator it2;
	int quota, ans, i, k, a, b, c, d;

	quota = n / m;
	ans = 0;

	for (i = 1; i <= m; i++) {
		if (count[i] < quota) {
			ans += quota - count[i];
		}
		mm.insert(make_pair(count[i], i));
	}

	for (i = 0; i < n; i++) {
		if (arr[i] <= m) continue;
		it = mm.begin();
		if (it->first < quota) {
			a = it->first;
			b = it->second;
			arr[i] = b;
			mm.erase(it);
			mm.insert(make_pair(a + 1, b));
		}
	}

	while (true) {
		it = mm.begin();
		if (it->first >= quota) break;
		a = it->first;
		b = it->second;
		mm.erase(it);

		it2 = mm.begin();
		k = mm.size() - 1;
		while (k--) {
			it2++;
		}
		c = it2->first;
		d = it2->second;
		mm.erase(it2);

		arr[ idxs[d][0] ] = b;
		idxs[d].erase(idxs[d].begin());

		mm.insert(make_pair(a + 1, b));
		mm.insert(make_pair(c - 1, d));
	}

	cout << quota << " " << ans << "\n";
	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main(int argc, char* argv[]) {
	int n, m, other, a, i;

	other = 0;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> a;
		arr[i] = a;
		if (a <= m) {
			count[a]++;
			idxs[a].push_back(i);
		} else {
			other++;
			others.push_back(i);
		}
	}

	solve(n, m, other);

	return 0;
}

/*
4 2
1 2 3 2
=====
2 1
1 2 1 2 

7 3
1 3 2 2 2 2 1
=====
2 1
1 3 3 2 2 2 1 

4 4
1000000000 100 7 1000000000
======
1 4
1 2 3 4 

5 4
3 1 495987801 522279660 762868488
=====
1 2
3 1 4 2 762868488

20 3
3 2 2 3 3 3 2 3 3 3 2 748578511 149249674 844954396 321901094 3 255089924 244803836 3 943090472
=====
6 8
3 2 2 1 3 3 2 3 3 3 2 1 1 1 1 3 1 2 3 2

50 10
820558149 7 10 7 9 9 7 7 7 9 7 10 8 8 10 8 6 8 9 9 8 971788012 9 8 9 10 6 5 871178015 4 10 5 7 9 10 9 10 4 643998638 8 10 9 10 766953454 5 9 10 10 8 10
=====
5 23
1 1 1 1 1 2 7 7 7 2 7 2 2 2 3 3 6 8 3 3 8 3 4 8 9 4 6 5 4 4 5 5 7 9 5 9 6 4 6 8 10 9 10 6 5 9 10 10 8 10

7 4
1 1 1 1 1 1 1
=====
1 3
2 3 4 1 1 1 1
*/
