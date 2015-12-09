// https://algospot.com/judge/problem/read/GRADUATION

#include <iostream>
#include <vector>

using namespace std;

vector<int> pre;
vector<vector<int>> terms;
int n, k, m, l;

int solve(int learned, int learnedCount, int selected, int selectedCount, int idx, int termsCount, int termsIndex) {
	int i, lecture, condition, ret, temp;

	if (learnedCount >= k) return termsCount;
	if (termsIndex >= m) return -1;

	ret = -1;
	if (selectedCount < l) {
		for (i = idx; i < terms[ termsIndex ].size(); i++) {
			lecture = terms[ termsIndex ][i];
			if (learned & (1 << lecture)) continue;
			condition = learned & pre[lecture];
			if (condition == pre[lecture]) {
				temp = solve(learned, learnedCount, selected | (1 << lecture), selectedCount + 1, i + 1, termsCount, termsIndex);
				if (temp != -1 && (ret == -1 || ret > temp)) ret = temp;
			}
		}
	}
	if (selectedCount > 0) {
		temp = solve(learned | selected, learnedCount + selectedCount, 0, 0, 0, termsCount + 1, termsIndex + 1);
	} else {
		temp = solve(learned, learnedCount, 0, 0, 0, termsCount, termsIndex + 1);
	}
	if (temp != -1 && (ret == -1 || ret > temp)) ret = temp;

	return ret;
}

int main(int argc, char* argv[]) {
	int t, i, r, ri;
	
	cin >> t;
	while (t--) {
		cin >> n >> k >> m >> l;

		pre.clear();

		terms.clear();
		terms.assign(m, pre);

		pre.assign(n, 0);

		i = 0;
		while (i < n) {
			cin >> r;
			while (r--) {
				cin >> ri;
				pre[i] |= 1 << ri;
			}
			i++;
		}

		i = 0;
		while (i < m) {
			cin >> r;
			terms[i].assign(r, 0);
			ri = 0;
			while (ri < r) {
				cin >> terms[i][ri];
				ri++;
			}
			i++;
		}

		r = solve(0, 0, 0, 0, 0, 0, 0);
		if (r == -1) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << r << "\n";
		}
	}

	return 0;
}

/*
2
4 4 4 4
0
1 0
3 0 1 3
0
4 0 1 2 3 
4 0 1 2 3
3 0 1 3
4 0 1 2 3
4 2 2 4
1 1
0
1 3
1 2
3 0 2 3
3 1 2 3
*/
