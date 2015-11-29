//
//  main.cpp
//  HackerRank_week18_Ghosts
//
//  Created by Youngduke Koh on 11/23/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// https://www.hackerrank.com/contests/w18/challenges/ghosts

#include <iostream>
#include <queue>

using namespace std;

struct Object {
    int a;
    int b;
    int c;
    int d;
    Object() : a(0), b(0), c(0), d(0) {}
};

int gdc(int a, int b) {
    while (a && b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    
    return a + b;
}

int main(int argc, const char * argv[]) {
    queue<Object> qa, qb, qc;
    Object o;
    int a, b, c, d, i, cnt;
    
    cin >> a >> b >> c >> d;
    
    for (i = 1; i <= a; i++) {
        o.a = i;
        qa.push(o);
    }
    
    while (!qa.empty()) {
        o = qa.front();
        qa.pop();
        for (i = 1; i <= b; i++) {
            if (o.a < i) {
                if ((i - o.a) % 3 == 0) {
                    o.b = i;
                    qb.push(o);
                }
            } else {
                if ((o.a - i) % 3 == 0) {
                    o.b = i;
                    qb.push(o);
                }
            }
        }
    }
    
    while (!qb.empty()) {
        o = qb.front();
        qb.pop();
        for (i = 1; i <= c; i++) {
            if ((o.b + i) % 5 == 0) {
                if ((o.a * i) % 4 == 0) {
                    o.c = i;
                    qc.push(o);
                }
            }
        }
    }
    
    cnt = 0;
    while (!qc.empty()) {
        o = qc.front();
        qc.pop();
        for (i = 1; i <= d; i++) {
            if (gdc(o.a, i) == 1) {
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}

/*
4 4 4 4
=====
8
*/

