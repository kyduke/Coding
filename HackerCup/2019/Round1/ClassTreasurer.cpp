// https://www.facebook.com/hackercup/problem/2448144345414246/

#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 1000002;
const UINT64 MOD = 1000000007;

UINT64 pow2[SIZE] = {0, };
char str[SIZE];
int arr[SIZE];

void preprocessing() {
    int i;
    
    pow2[0] = 1;
    for (i = 1; i < SIZE; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
}

int main(int argc, const char * argv[]) {
    int t, ti;
    int n, k;
    int i, diff;
    UINT64 ans;
    bool flag;
    
    preprocessing();
    
    cin >> t;
    for (ti = 1; ti <= t; ti++) {
        ans = 0;
        
        cin >> n >> k;
        cin >> str;
        
        diff = 0;
        for (i = n - 1; i >= 0; i--) {
        	if (str[i] == 'B') {
        		if (diff == k) {
        			ans = (ans + pow2[i + 1]) % MOD;
        			diff = max(diff - 1, 0);
        		} else {
        			diff++;
        		}
        	} else {
        		diff = max(diff - 1, 0);
        	}
        }
        
        cout << "Case #" << ti << ": " << ans << "\n";
    }
    
    return 0;
}

/*
6
4 0
BAAB
4 1
BAAB
4 1
ABBA
5 2
BBBBB
15 3
ABBBABBBBBABABB
50 4
BBABAABBBBABBBBAABBBBAABBBBBABBBAABABBBBBBABABBAAB
=====
Case #1: 18
Case #2: 0
Case #3: 4
Case #4: 10
Case #5: 324
Case #6: 363067831
*/
