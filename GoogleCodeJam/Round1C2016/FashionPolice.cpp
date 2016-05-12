// Google Code Jam Round 1C 2016 Problem C. Fashion Police

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve(int J, int P, int S, int K) {
	vector<int> Js, Ps, Ss;
	map<int, int> m;
	map<int, int>::iterator itX, itY, itZ;
	int i, j, k, x, y, z;

	for (i = 1; i <= J; i++) {
		for (j = 1; j <= P; j++) {
			for (k = 1; k <= S; k++) {
				x = i + j * 100;
				itX = m.find(x);
				if (itX != m.end() && itX->second >= K) continue;
				y = i + k * 10000;
				itY = m.find(y);
				if (itY != m.end() && itY->second >= K) continue;
				z = j * 100 + k * 10000;
				itZ = m.find(z);
				if (itZ != m.end() && itZ->second >= K) continue;

				if (itX == m.end()) {
					m.insert(make_pair(x, 1));
				} else {
					itX->second++;
				}
				if (itY == m.end()) {
					m.insert(make_pair(y, 1));
				} else {
					itY->second++;
				}
				if (itZ == m.end()) {
					m.insert(make_pair(z, 1));
				} else {
					itZ->second++;
				}

				Js.push_back(i);
				Ps.push_back(j);
				Ss.push_back(k);
			}
		}
	}

	cout << Js.size() << "\n";
	for (i = 0; i < Js.size(); i++) {
		cout << Js[i] << " " << Ps[i] << " " << Ss[i] << "\n";
	}
}

int main(int argc, char* argv[]) {
	int T, t, J, P, S, K;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> J >> P >> S >> K;
		t++;
		cout << "Case #" << t << ": ";
		solve(J, P, S, K);
	}

	return 0;
}

/*
4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
=====
Case #1: 1
1 1 1
Case #2: 4
1 1 2
1 2 3
1 2 1
1 1 1
Case #3: 2
1 1 2
1 1 1
Case #4: 2
1 1 3
1 2 1
*/
