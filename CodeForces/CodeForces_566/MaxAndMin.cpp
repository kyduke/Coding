// http://codeforces.com/problemset/problem/566/G

#include <iostream>

using namespace std;

const int MAX = 100000;

int n, m;
int maxs[2][MAX];
int mins[2][MAX];

bool makeAllNegative(int a, int b, int c, int d, int depth) {
	int i, e, f, minE, minF, minSum;
    bool result;

    if (depth == m) return false;

    minSum = 20000000;
    for (i = 0; i < m; i++) {
		e = c - mins[0][i];
		f = d - mins[1][i];
		if (e < 0 && f < 0) {
			return true;
        } else {
			if (minSum > max(e, f)) {
				minSum = max(e, f);
				minE = a + e;
				minF = b + f;
			}
        }
    }

	if (a < minE && b < minF) return false;
	if (a > minE && b > minF) return true;

    return makeAllNegative(a, b, minE, minF, depth + 1);
}

bool solve() {
	int i;

	for (i = 0; i < n; i++) {
		if (makeAllNegative(maxs[0][i], maxs[1][i], maxs[0][i], maxs[1][i], 0) == false) return false;
	}

	return true;
}

int main(int argc, char* argv[]) {
	int i, a, b, maxA, maxB, maxC, maxD;
	bool magic;

	cin >> n >> m;
	cin >> i >> i;

	maxA = 0;
	maxB = 0;

	i = 0;
	while (i < n) {
		cin >> a >> b;
		maxs[0][i] = a;
		maxs[1][i] = b;
		maxA = max(maxA, a);
		maxB = max(maxB, b);
		i++;
	}

	maxC = 0;
	maxD = 0;

	i = 0;
	magic = false;
	while (i < m) {
		cin >> a >> b;
		mins[0][i] = a;
		mins[1][i] = b;
		maxC = max(maxC, a);
		maxD = max(maxD, b);
		if (maxA < a && maxB < b) {
			magic = true;
		}
		i++;
	}

	if (magic == true) {
		cout << "Min\n";
	} else if (maxA >= maxC || maxB >= maxD) {
		cout << "Max\n";
	} else {
		cout << (solve() ? "Min\n" : "Max\n");
	}

	return 0;
}

/*
2 2
42 43
2 3
3 2
3 10
10 3
=====
Min

1 1
1 1
3 4
1 1
=====
Max
*/
