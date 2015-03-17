#include <iostream>
#include <algorithm>

using namespace std;

int deceitfulWar(double* a, double* b, int n) {
	int i, count, temp;
	double m;

	count = 0;
	m = b[0];
	for (i = 0; i < n; i++) {
		if (a[i] > m) break;
		count++;
	}

	temp = 0;
	m = a[n - 1];
	for (i = n - 1; i >= 0; i--) {
		if (b[i] < m) break;
		temp++;
	}

	if (temp > count) count = temp;

	return n - count;
}

int war(double* a, double* b, int n) {
	int i, j;
	bool big;

	i = 0;
	while (i < n) {
		big = false;
		for (j = 0; j < n; j++) {
			if (b[j] > a[i]) {
				b[j] = 0.0;
				big = true;
				break;
			}
		}
		if (big == false) break;
		i++;
	}

	return n - i;
}

int main(int argc, char* argv[]) {
	int T, i, N, j;
	double temp;
	double a[1000], b[1000], c[1000];

	cin >> T;
	i = 0;
	while (i < T) {
		i++;
		cin >> N;
		j = 0;
		while (j < N) {
			cin >> temp;
			a[j++] = temp;
		}
		j = 0;
		while (j < N) {
			cin >> temp;
			b[j] = temp;
			c[j] = temp;
			j++;
		}
		sort(a, a + N);
		sort(b, b + N);
		sort(c, c + N);
		cout << "Case #" << i << ": ";
		cout << deceitfulWar(a, b, N) << " ";
		cout << war(a, c, N) << "\n";
	}

	return 0;
}

/*
4
1
0.5
0.6
2
0.7 0.2
0.8 0.3
3
0.5 0.1 0.9
0.6 0.4 0.3
9
0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458
===== 
Case #1: 0 0
Case #2: 1 0
Case #3: 2 1
Case #4: 8 4
*/
