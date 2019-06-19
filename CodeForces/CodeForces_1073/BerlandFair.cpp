// https://codeforces.com/contest/1073/problem/D

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 200000;

int main() {
	int n, i;
	UINT64 ans, a, t, s, m;
	vector<UINT64> arr, temp;
	
	cin >> n >> t;
	s = 0;
	m = 1000000000;
	for (i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
		s += a;
		m = min(m, a);
	}
	
	ans = 0;
	ans += (UINT64)n * (t / s);
	t %= s;
	while (t >= m) {
		s = 0;
		for (i = 0; i < arr.size(); i++) {
			if (t >= arr[i]) {
				t -= arr[i];
				ans++;
				temp.push_back(arr[i]);
				s += arr[i];
			}
		}
		arr = temp;
		temp.clear();
		ans += (UINT64)(arr.size()) * (t / s);
		t %= s;
	}
	
	cout << ans << "\n";
	
	return 0;
}

/*
3 38
5 2 5
=====
10

5 21
2 4 100 2 6
=====
6
*/
