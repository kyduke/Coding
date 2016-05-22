//
//  main.cpp
//  CodeForces_675_InfiniteSequence
//
//  Created by Youngduke Koh on 5/22/16.
//  Copyright © 2016 Youngduke Koh. All rights reserved.
//
// http://codeforces.com/contest/675/problem/A

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b, c;
    
    cin >> a >> b >> c;
    
    a = b - a;
    
    if (a == 0) {
        cout << "YES\n";
    } else if (c == 0) {
        if (a == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if ((c > 0 && a > 0) || (c < 0 && a < 0)){
        if (c < 0) {
            c *= -1;
            a *= -1;
        }
        
        if (a % c == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }
    
    return 0;
}

/*
1 7 3
=====
YES

10 10 0
=====
YES

1 -4 5
=====
NO

0 60 50
=====
NO
*/
