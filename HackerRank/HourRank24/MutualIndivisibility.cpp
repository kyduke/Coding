// https://www.hackerrank.com/contests/hourrank-24/challenges/mutual-indivisibility/problem

#include <iostream>

using namespace std;

int main() {
    int t, a, b, x;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &x);
        a = max(a, (b / 2) + 1);
        if (b - a + 1 >= x) {
            while (x--) {
                printf("%d ", a);
                a++;
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}

/*
3
1 3 2
3 9 3
2 5 4
=====
2 3
3 7 8
-1
*/
