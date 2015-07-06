// https://algospot.com/judge/problem/read/WEIRD
// https://en.wikipedia.org/wiki/Weird_number

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int weirds[500000] = {0, };
int visit[500000];

bool isWeird(int n) {
	vector<int> sub;
	vector<int> sum;
	int i, j, l, t;

	if (n / 2 == 1) {
		return false;
	}

	sub.push_back(1);
	l = n;
	t = 0;
	for (i = 2; i < l; i++) {
		if (n % i == 0) {
			sub.push_back(i);
			l = n / i;
			t += i;
			if (l > i) {
				sub.push_back(l);
				t += l;
			}
		}
	}

	if (t <= n) {
		return false;
	}

	sort(sub.begin(), sub.end());
	memset(visit, 0, sizeof(int) * n);

	sum.push_back(0);
	for (i = 0; i < (int)sub.size(); i++) {
		l = sum.size();
		for (j = 0; j < l; j++) {
			t = sum[j] + sub[i];
			if (t == n) {
				return false;
			}
			if (t < n && visit[t] == 0) {
				visit[t] = 1;
				sum.push_back(t);
			}
		}
	}

	return true;
}

int main(int argc, char* argv[]) {
	int C, N;

	cin >> C;
	while (C--) {
		cin >> N;
		if (isWeird(N) == true) {
			cout << "weird\n";
		} else {
			cout << "not weird\n";
		}
	}

	return 0;
}

/*
2
12
70
=====
not weird
weird
*/
