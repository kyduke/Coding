// http://codeforces.com/contest/586/problem/A

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

vector<int> schedules;

int solve() {
	int time, i, university;

	time = 0;
	university = 0;
	for (i = 0; i < schedules.size(); i++) {
		if (university == 1) {
			if (schedules[i] == 0 && (i == schedules.size() - 1 || schedules[i + 1] == 0)) {
				university = 0;
				continue;
			}
			time++;
		} else {
			if (schedules[i] == 1) {
				university = 1;
				time++;
			}
		}
	}

	return time;
}

int main(int argc, char* argv[]) {
	int n, a;

	cin >> n;
	while (n--) {
		cin >> a;
		schedules.push_back(a);
	}

	cout << solve() << "\n";

	return 0;
}

/*
5
0 1 0 1 1
=====
4

7
1 0 1 0 0 1 0
=====
4

1
0
=====
0
*/
