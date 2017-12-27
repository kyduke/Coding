//
//  main.cpp
//  CodeForces_454_C
//
//  Created by Young Duke Koh on 12/27/17.
//  Copyright © 2017 Young Duke Koh. All rights reserved.
//
// http://codeforces.com/contest/907/problem/C

#include <iostream>
#include <set>
#include <cstring>

using namespace std;

const int SIZE = 100001;

char buffer[SIZE];
set<int> digit;

void solve(char c) {
    set<int> s;
    int arr[26] = {0, };
    int i;
    
    for (i = 0; i < strlen(buffer); i++) {
        arr[buffer[i] - 'a'] = 1;
    }
    
    if (c == '!') {
        for (i = 0; i < 26; i++) {
            if (arr[i] == 1 && digit.find(i) != digit.end()) {
                s.insert(i);
            }
        }
    } else {
        for (i = 0; i < 26; i++) {
            if (arr[i] == 0 && digit.find(i) != digit.end()) {
                s.insert(i);
            }
        }
    }
    
    digit = s;
}

int main(int argc, const char * argv[]) {
    int n, i, ans;
    char command[2];
    
    for (i = 0; i < 26; i++) digit.insert(i);
    
    ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %s", command, buffer);
        
        if (digit.size() == 1 && command[0] != '.' && i != n - 1) ans++;
        solve(command[0]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}

/*
5
! abc
. ad
. b
! cd
? c
=====
1

8
! hello
! codeforces
? c
. o
? d
? h
. l
? e
=====
2

7
! ababahalamaha
? a
? b
? a
? b
? a
? h
=====
0
*/
