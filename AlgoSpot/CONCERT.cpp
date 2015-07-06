// https://algospot.com/judge/problem/read/CONCERT

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> v;
int cache[50][1001];

int getMaxVolume(int vs, int vm, int idx) {
	int t, v1, v2;
	int& ret = cache[idx][vs];

	if (ret != -1) return ret;

	if (idx == v.size() - 1) {
		t = vs + v[idx];
		if (t >= 0 && t <= vm) {
			ret = t;
			return ret;
		}
		t = vs - v[idx];
		if (t >= 0 && t <= vm) {
			ret = t;
			return ret;
		}
		ret = -2;
		return ret;
	}

	v1 = -2;
	v2 = -2;

	t = vs + v[idx];
	if (t >= 0 && t <= vm) {
		v1 = getMaxVolume(t, vm, idx + 1);
	}
	t = vs - v[idx];
	if (t >= 0 && t <= vm) {
		v2 = getMaxVolume(t, vm, idx + 1);
	}

	ret = max(v1, v2);

	return ret;
}

int main(int argc, char* argv[]) {
	int T, N, VS, VM;
	int volume;

	cin >> T;
	while (T--) {
		cin >> N >> VS >> VM;
		v.clear();
		while (N--) {
			cin >> volume;
			v.push_back(volume);
		}
		memset(cache, -1, sizeof(int) * 50 * 1001);
		cout << max(-1, getMaxVolume(VS, VM, 0)) << "\n";
	}

	return 0;
}

/*
3
3 5 10
5 3 7
4 8 20
15 2 9 10
14 40 243
74 39 127 95 63 140 99 96 154 18 137 162 14 88
=====
10
-1
238
*/
