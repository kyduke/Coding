// https://projecteuler.net/problem=75
// http://www.mathblog.dk/project-euler-75-lengths-of-wire-right-angle-triangle/

#include <iostream>

using namespace std;

const int LIMIT = 1500000;

int triangles[LIMIT + 1];

int gcd(int a, int b) {
	int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(int argc, char* argv[]) {
	unsigned long long a, b, c, p, n, m;
	int result = 0;
	int mlimit = (int)sqrt((double)LIMIT / 2);
 
	for (m = 2; m < mlimit; m++) {
		for (n = 1; n < m; n++) {
			if (((n + m) % 2) == 1 && gcd(m, n) == 1) {
				a = m * m + n * n;
				b = m * m - n * n;
				c = 2 * m * n;
				p = a + b + c;
				while(p <= LIMIT){
					triangles[p]++;
					if (triangles[p] == 1) result++;
					if (triangles[p] == 2) result--;
					p += a + b + c;
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}
