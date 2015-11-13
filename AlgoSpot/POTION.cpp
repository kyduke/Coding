// https://algospot.com/judge/problem/read/POTION

#include <iostream>

using namespace std;

const int SIZE = 200;

int r[SIZE];
int p[SIZE];
int n;

int gcd(int a, int b) {
	while (a && b) {
		if (a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}

	return a + b;
}

void solve() {
	int i, a, b;

	b = r[0];
	for (i = 1; i < n; i++) {
		b = gcd(b, r[i]);
	}
	
	a = b;
	for (i = 0; i < n; i++) {
		a = max(a, (p[i] * b + r[i] - 1) / r[i]);
	}
	
	for (i = 0; i < n; i++) {
		cout << r[i] * a / b - p[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	int c, i;

	cin >> c;
	while (c--) {
		cin >> n;
		i = 0;
		while (i < n) {
			cin >> r[i];
			i++;
		}

		i = 0;
		while (i < n) {
			cin >> p[i];
			i++;
		}

		solve();
	}

	return 0;
}

/*
3
4
4 6 2 4
6 4 2 4
4 
4 6 2 4
7 4 2 4
3
4 5 6 
1 2 3 
예제 출력

0 5 1 2
1 8 2 4
3 3 3
*/
