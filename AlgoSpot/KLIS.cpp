//https://algospot.com/judge/problem/read/KLIS

#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int cacheLen[501];
long long cacheCnt[501];
int S[501];

int lis(int start) {
	int& ret = cacheLen[start + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}

	return ret;
}

long long count(int start) {
	if (lis(start) == 1) return 1;

	long long& ret = cacheCnt[start + 1];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = start + 1; next < n; next++) {
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1) {
			ret = min<long long>(2147483647, ret + count(next));
		}
	}

	return ret;
}

void reconstruct(int start, int skip, vector<int>& result) {
	if (start !=  -1) result.push_back(S[start]);

	vector<pair<int, int>> followers;
	for (int next = start + 1; next < n; next++) {
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1) {
			followers.push_back(make_pair(S[next], next));
		}
	}
	sort(followers.begin(), followers.end());

	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		long long cnt = count(idx);
		if (cnt <= skip) {
			skip -= cnt;
		} else {
			reconstruct(idx, skip, result);
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	int C, N, K;
	vector<int> result;

	cin >> C;
	while (C--) {
		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));

		cin >> N >> K;

		n = N;
		while (N--) {
			cin >> S[n - N - 1];
		}

		cout << lis(-1) - 1 << "\n";
		result.clear();
		reconstruct(-1, K - 1, result);

		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}

/*
3
9 2
1 9 7 4 2 6 3 11 10
8 4
2 1 4 3 6 5 8 7
8 2
5 6 7 8 1 2 3 4
=====
4
1 2 3 11
4
1 3 6 8
4
5 6 7 8
*/
