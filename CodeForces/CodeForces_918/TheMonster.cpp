//
//  main.cpp
//  CodeForces_459_C
//
//  Created by Young Duke Koh on 1/30/18.
//  Copyright © 2018 Young Duke Koh. All rights reserved.
//
// http://codeforces.com/contest/918/problem/C
// Wrong answer

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 5000;

int dp[SIZE][SIZE] = {0, };

int solve(string& str) {
    int ans;
    int i, j, k, left, right;
    
    ans = 0;
    
    // (( <= () => ))
    for (i = 0; i < str.size() - 1; i++) {
        left = i;
        right = i + 1;
        while (left >= 0 && right < str.size()) {
            if (str[left] == ')' || str[right] == '(') {
                break;
            }
            dp[left][right] = 1;
            left--;
            right++;
        }
    }
    
    for (i = str.size() - 2; i >= 0; i--) {
        if (str[i] == ')') continue;
        
        // () => (())
        left = 0;
        right = 0;
        k = -1;
        for (j = i; j < str.size(); j++) {
            if (dp[i][j] == 0) {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                k = i + 2;
                break;
            }
        }
        if (k == -1) continue;
        for (j = k + 1; j < str.size(); j++) {
            dp[i][j] |= dp[k][j];
        }
        
        // ( => (()) )
        k = i + 1;
        for (j = k + 1; j < str.size(); j++) {
            if (dp[k][j] == 1) {
                if (j + 1 < str.size() && str[j + 1] != '(') {
                    dp[i][j + 1] = 1;
                }
            }
        }
    }
    
    for (i = 0; i < str.size(); i++) {
        for (j = 0; j < str.size(); j++) {
            // cout << dp[i][j] << " ";
            ans += dp[i][j];
        }
        // cout << "\n";
    }
    
    
    return ans;
}

int main(int argc, const char * argv[]) {
    string str;
    
    cin >> str;
    
    cout << solve(str) << "\n";
                  
    return 0;
}

/*
((?))
=====
4

??()??
=====
7
 
?????)(???
=====
21
 
??)(??
=====
6
(()())
 
()()((?(()(((()()(())(((()((())))(()))(()(((((())))()))(((()()()))))))(((((()))))))))
=====
62
*/
