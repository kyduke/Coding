// http://codeforces.com/contest/608/problem/B

#include <iostream>
#include <string>

typedef unsigned long long UINT64;

using namespace std;

const int SIZE = 200001;

int f[SIZE][2];

int main() {
    string a, b;
	int i, j, c;
	UINT64 ans;

    cin >> a;
	cin >> b;

	ans = 0;

    for (i = 1; i <= b.size(); i++) {
        for (j = 0; j < 2; j++) {
            f[i][j] = f[i - 1][j];
        }
        f[i][ b[i - 1] - '0' ]++;
    }
    
    for (i = 0; i < a.size(); i++) {
        c = a[i] - '0';
        for (j = 0; j < 2; j++) {
			if (c == j) continue;
            ans += f[ b.size() - a.size() + i + 1 ][j] - f[i][j];
        }
    }

    cout << ans << '\n';
    
	return 0;
}

/*
01
00111
=====
3

0011
0110
=====
2
*/
