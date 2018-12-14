// https://codeforces.com/contest/1016/problem/B

#include <iostream>

using namespace std;

const int SIZE = 1003;

char str[SIZE];
int start[SIZE] = {0, };

char pattern[SIZE];
int fail[SIZE];

void preKMP(char* pattern, int size) {
    int i, m, k;
    
    m = size;
    for (i = 1; i <= m; i++) {
    	fail[i] = 0;
    }

    fail[0] = -1;
    for (i = 1; i < m; i++) {
        k = fail[i - 1];
        while (k >= 0) {
            if (pattern[k] == pattern[i - 1]) {
                break;
            } else {
                k = fail[k];
            }
        }
        fail[i] = k + 1;
    }
}

void KMP(char* pattern, char* target, int sizeOfPattern, int sizeOfTarget) {
    int m, n, i, k;
    
    m = sizeOfPattern;
    n = sizeOfTarget;
    i = 0;
    k = 0;
    while (i < n) {
        if (k == -1) {
            i++;
            k = 0;
        } else if (target[i] == pattern[k]) {
            i++;
            k++;
            if (k == m) {
            	start[i - m] = 1;
            	k = fail[k];
            }
        } else {
            k = fail[k];
        }
    }
}

int main() {
	int n, m, q, i, l, r, ans;
	
	scanf("%d %d %d", &n, &m, &q);
	scanf("%s", str);
	scanf("%s", pattern);
	preKMP(pattern, m + 1);
	KMP(pattern, str, m, n);
	
	while (q--) {
		scanf("%d %d", &l, &r);
		ans = 0;
		for (i = l - 1; i < r; i++) {
			if (start[i] == 1 && i + m <= r) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}

/*
10 3 4
codeforces
for
1 3
3 10
5 6
5 7
=====
0
1
0
1

15 2 3
abacabadabacaba
ba
1 15
3 4
2 14
=====
4
0
3

3 5 2
aaa
baaab
1 3
1 1
=====
0
0
*/
