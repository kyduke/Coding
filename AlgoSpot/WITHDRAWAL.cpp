// https://algospot.com/judge/problem/read/WITHDRAWAL

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 1000;

int ranks[SIZE];
int classes[SIZE];
int n, k;

bool decision(double rank) {
	vector<double> arr;
	int i;
	double v;

	for (i = 0; i < n; i++) {
		v = rank * classes[i] - ranks[i];
		arr.push_back(v);
	}

	sort(arr.begin(), arr.end());

	v = 0;
	for (i = n - 1; i >= n - k; i--) {
		v += arr[i];
	}

	return (v >= 0.0);
}

double solve() {
	double low, hi, mid;
	int i;

	low = 0.0;
	hi = 1.0;

	i = 100;
	while (i) {
		mid = (low + hi) / 2.0;
		if (decision(mid) == true) {
			hi = mid;
		} else {
			low = mid;
		}
		i--;
	}

	return hi;
}

int main(int argc, char* argv[]) {
	int T, i;

	cin >> T;
	while (T--) {
		cin >> n >> k;
		i = 0;
		while (i < n) {
			cin >> ranks[i] >> classes[i];
			i++;
		}

		printf("%.10f\n", solve());
	}

	return 0;
}

/*
3
3 2
1 4 6 10 10 17
4 2
4 8 9 12 3 10 2 5
10 5
70 180 192 192 1 20 10 200 6 102 60 1000 4 9 1 12 8 127 100 700 
=====
0.5000000000 
0.3333333333 
0.0563991323
*/
