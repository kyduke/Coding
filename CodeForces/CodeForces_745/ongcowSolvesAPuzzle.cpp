//
//  main.cpp
//  CodeForces_385_B
//
//  Created by Young Duke Koh on 12/27/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
// http://codeforces.com/contest/745/problem/B

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solve(vector<string>& s, int n, int m) {
    int table[501][501] = {0, };
    int line[251001];
    string t;
    int i, j, a, b, x, y;
    bool flag;
    
    //remove empty borders
    a = 0;
    b = 0;
    x = (int)s[0].size() - 1;
    y = (int)s.size() - 1;
    for (i = 0; i < s[0].size(); i++) {
        flag = true;
        for (j = 0; j < s.size(); j++) {
            if (s[j][i] == 'X') {
                flag = false;
                break;
            }
        }
        if (!flag) {
            a = i;
            break;
        }
    }
    
    for (i = (int)s[0].size() - 1; i >= 0; i--) {
        flag = true;
        for (j = 0; j < s.size(); j++) {
            if (s[j][i] == 'X') {
                flag = false;
                break;
            }
        }
        if (!flag) {
            x = i;
            break;
        }
    }
    
    for (i = 0; i < s.size(); i++) {
        t = s[i];
        flag = true;
        for (j = 0; j < t.size(); j++) {
            if (t[j] == 'X') {
                flag = false;
                break;
            }
        }
        if (!flag) {
            b = i;
            break;
        }
    }
    
    for (i = (int)s.size() - 1; i >= 0; i--) {
        t = s[i];
        flag = true;
        for (j = 0; j < t.size(); j++) {
            if (t[j] == 'X') {
                flag = false;
                break;
            }
        }
        if (!flag) {
            y = i;
            break;
        }
    }
    
    //copy string array to int map
    for (i = b; i <= y; i++) {
        for (j = a; j <= x; j++) {
            if (s[i][j] == 'X') {
                table[i - b][j - a] = 1;
            }
        }
    }
    
    a = x - a + 1;
    b = y - b + 1;
    
    //check euquality of rows
    for (i = 1; i < b; i++) {
        for (j = 0; j < a; j++) {
            if (table[0][j] != table[i][j]) return false;
        }
    }
    
    //check euquality of columns
    for (i = 0; i < b; i++) {
        for (j = 1; j < a; j++) {
            if (table[0][j] != table[i][j]) return false;
        }
    }
    
    //check rows
    for (i = 0; i < 251001; i++) {
        line[i] = 0;
    }
    
    for (i = 0; i < a; i++) {
        line[i] = table[0][i];
    }
    
    x = 0;
    for (i = 0; i < a; i++) {
        if (line[i] == 0) {
            x = i;
            break;
        }
    }
    while (x) {
        a += x;
        for (i = x; i < a; i++) {
            line[i] += table[0][i - x];
            if (line[i] > 1) return false;
        }
        i = x;
        x = 0;
        for (; i < a; i++) {
            if (line[i] == 0) {
                x = i;
                break;
            }
        }
    }
    
    //check columns
    for (i = 0; i < 251001; i++) {
        line[i] = 0;
    }
    
    for (i = 0; i < b; i++) {
        line[i] = table[i][0];
    }
    
    y = 0;
    for (i = 0; i < b; i++) {
        if (line[i] == 0) {
            y = i;
            break;
        }
    }
    while (y) {
        b += y;
        for (i = y; i < b; i++) {
            line[i] += table[i - x][0];
            if (line[i] > 1) return false;
        }
        i = y;
        y = 0;
        for (; i < b; i++) {
            if (line[i] == 0) {
                y = i;
                break;
            }
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    int n, m, i;
    vector<string> s;
    
    cin >> n >> m;
    s.assign(n, "");
    for (i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    if (solve(s, n, m)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}

/*
2 3
XXX
XXX
=====
YES

2 2
.X
XX
=====
NO

5 5
.....
..X..
.....
.....
.....
=====
YES
*/
