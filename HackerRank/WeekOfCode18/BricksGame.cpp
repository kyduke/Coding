// https://www.hackerrank.com/challenges/play-game

#include <iostream>
#include <string.h>

using namespace std;

typedef long long INT64;

const int SIZE = 100001;

INT64 cache[2][2][SIZE];
int nums[SIZE];
int N;

void maxScore(int turn, int idx, INT64& myScore, INT64& friendScore) {
    if (idx >= N) return;
    
    INT64& m0 = cache[turn][0][idx];
    INT64& f0 = cache[turn][1][idx];
    INT64 m1, m2, m3, f1, f2, f3;
    
    if (m0 != -1) {
        myScore = m0;
        friendScore = f0;
        
        return;
    }
    
    m1 = 0; m2 = 0; m3 = 0;
    f1 = 0; f2 = 0; f3 = 0;
    
    maxScore((turn + 1) % 2, idx + 1, m1, f1);
    if (turn == 0) {
        m1 += nums[idx];
    } else {
        f1 += nums[idx];
    }
    
    if (idx + 1 < N) {
        maxScore((turn + 1) % 2, idx + 2, m2, f2);
        if (turn == 0) {
            m2 += nums[idx] + nums[idx + 1];
        } else {
            f2 += nums[idx] + nums[idx + 1];
        }        
    }
    
    if (idx + 2 < N) {
        maxScore((turn + 1) % 2, idx + 3, m3, f3);
        if (turn == 0) {
            m3 += nums[idx] + nums[idx + 1] + nums[idx + 2];
        } else {
            f3 += nums[idx] + nums[idx + 1] + nums[idx + 2];
        }        
    }
    
    if (turn == 0) {
        m0 = m1;
        f0 = f1;
        if (m0 < m2) {
            m0 = m2;
            f0 = f2;
        }
        if (m0 < m3) {
            m0 = m3;
            f0 = f3;
        }
    } else {
        m0 = m1;
        f0 = f1;
        if (f0 < f2) {
            m0 = m2;
            f0 = f2;
        }
        if (f0 < f3) {
            m0 = m3;
            f0 = f3;
        }
    }

	myScore = m0;
    friendScore = f0;
}

int main() {
    int T, i;
    INT64 myScore, friendScore;
    
    cin >> T;
    while (T--) {
        memset(cache, -1, sizeof(INT64) * 2 * 2 * SIZE);
        
        cin >> N;
        i = 0;
        while (i < N) {
            cin >> nums[i];
            i++;
        }
        
        myScore = 0;
        friendScore = 0;
        maxScore(0, 0, myScore, friendScore);
        cout << myScore << "\n";
    }
    
    return 0;
}

/*
2
5
999 1 1 1 0
5
0 1 1 1 999
=====
1001
999
*/
