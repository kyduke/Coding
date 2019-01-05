// http://codeforces.com/contest/1020/problem/A

#include <iostream>

using namespace std;

int main() {
	int ans, n, h, a, b, k, ta, tb, fa, fb;

    scanf("%d %d %d %d %d", &n, &h, &a, &b, &k);
    while (k--) {
        scanf("%d %d %d %d", &ta, &fa, &tb, &fb);

        if (ta == tb) {
            ans = fa - fb;
            if (ans < 0) ans = -ans;
            printf("%d\n", ans);
            continue;
        }

        ans = ta - tb;
        if (ans < 0) ans = -ans;

        if (fa > b) {
            ans += fa - b;
            fa = b;
        } else if (fa < a) {
            ans += a - fa;
            fa = a;
        }

        if (fa > fb) {
            ans += fa - fb;
        } else {
            ans += fb - fa;
        }

        printf("%d\n", ans);
    }

	return 0;
}

/*
3 6 2 3 3
1 2 1 3
1 4 3 4
1 2 2 3
=====
1
4
2
*/

