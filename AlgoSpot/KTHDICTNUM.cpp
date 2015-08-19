// https://www.algospot.com/judge/problem/read/KTHDICTNUM
// 시간초과

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

//brute force
UINT64 bruteforce(UINT64 a, UINT64 b, UINT64 k) {
    UINT64 i, n, c;
    
    if (k == 0 && a == 0) return 0;
    
    c = 0;
    i = 0;
    if (a == 0) {
        c++;
        i++;
    }
    while (i <= b) {
        if (i % 10 != 0) {
            n = i;
            while (n < a) n *= 10;
            while (n <= b) {
                if (c == k) return n;
                n *= 10;
                c++;
            }
        }
        i++;
    }
    
    return 0;
}

int getLength(UINT64 n) {
	int length;

	length = 0;
	while(n) {
		length++;
		n /= 10;
	}

	return length;
}

UINT64 getLimit(int length) {
	UINT64 limit;

	limit = 1;
	while (length) {
		limit *= 10;
		length--;
	}

	return limit;
}

int main(int argc, char* argv[]) {
	int T;
	UINT64 a, b, k;
	
	cin >> T;
	while (T--) {
		cin >> a >> b >> k;
		cout << bruteforce(a, b, k) << "\n";
	}

	return 0;
}

/*
3
1 10 0
1 10 1
1 10 2
=====
1
10 
2
*/
