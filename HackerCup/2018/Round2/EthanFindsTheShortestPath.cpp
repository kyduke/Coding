//
//  main.cpp
//  HackerCup_2018_Round2_A
//
//  Created by Young Duke Koh on 06/08/2018.
//  Copyright © 2018 Young Duke Koh. All rights reserved.
//
// https://www.facebook.com/hackercup/problem/988017871357549/

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int t, ti, n, k, ans, cnt, i;
    
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        scanf("%d %d", &n, &k);
        cnt = min(n - 1, k - 1);
        ans = 0;
        if (cnt > 1) {
        i = 1;
            while (i <= cnt) {
                ans += (k - i);
                i++;
            }
        }
        ans -= k;
        if (ans < 0) ans = 0;
        printf("Case #%d: %d\n", ti, ans);
        if (cnt > 1) {
            printf("%d\n", cnt + 1);
            i = 1;
            while (i <= cnt) {
                printf("%d ", i);
                if (i == cnt) {
                    printf("%d ", n);
                } else {
                    printf("%d ", i + 1);
                }
                printf("%d\n", k - i);
                i++;
            }
        } else {
            printf("1\n");
        }
        printf("1 %d %d\n", n, k);
    }
    
    return 0;
}

/*
6
2 1
2 50
4 2
5 5
42 48
47 38
=====
Case #1: 0
Multiple possible accepted graphs
Case #2: 0
Multiple possible accepted graphs
Case #3: 0
Multiple possible accepted graphs
Case #4: 5
Multiple possible accepted graphs
Case #5: 1059
Multiple possible accepted graphs
Case #6: 665
Multiple possible accepted graphs
*/
