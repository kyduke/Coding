//
//  main.cpp
//  CodeForces_459_C
//
//  Created by Young Duke Koh on 1/30/18.
//  Copyright © 2018 Young Duke Koh. All rights reserved.
//
// http://codeforces.com/contest/918/problem/C

#include <iostream>
#include <string>

using namespace std;

int solve(string& str) {
    int ans, i, j, question, count;
    
    ans = 0;
    for (i = 0; i < str.size(); i++) {
        question = 0;
        count = 0;
        for (j = i; j < str.size(); j++) {
            if (str[j] == '(') {
                count++;
            } else if (str[j] == ')') {
                count--;
            } else {
                question++;
                count--;
            }
            
            while (question > 0 && count < 0) {
                question--;
                count += 2;
            }
            
            if (count < 0) break;
            
            if (count == 0) ans++;
        }
    }
    
    return ans;
}

int main(int argc, char* arg[]) {
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
