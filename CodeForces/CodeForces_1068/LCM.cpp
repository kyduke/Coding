// https://codeforces.com/contest/1068/problem/B

#include <iostream>
#include <set>
#include <cmath>

using namespace std;

typedef long long INT64;

INT64 gcd(INT64 a, INT64 b) {
        INT64 c;
        while (a != 0) {
            c = a;
            a = b % a;
            b = c;
        }
        return b;
    }

int main() {
	INT64 b, i, k, n;
	set<INT64> s;
	
	cin >> b;
	k = sqrt((double)b);
	
	for (i = 1; i <= k; i++) {
		n = b / gcd(i, b);
		s.insert(n);
		s.insert(b / n);
	}
	
	cout << s.size() << "\n";
	
	return 0;
}

/*
1
=====
1

2
=====
2
*/
