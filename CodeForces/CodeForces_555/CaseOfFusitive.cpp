// http://codeforces.com/problemset/problem/555/B
// Time limit exceeded on test 12

#include <iostream>
#include <set>

using namespace std;

const int SIZE = 200000;

unsigned long long starts[SIZE];
unsigned long long endes[SIZE];
unsigned long long bridges[SIZE];
int results[SIZE] = {0, };
int nexts[SIZE] = {0, };
int n, m;

bool useBridges() {
    int i, idx, next, direction;
    unsigned long long start, end;
    set<int> visits;
    set<int>::iterator it;

    for (i = 0; i < m; i++) {
        visits.insert(i);
    }

    direction = 1;
    idx = 0;
    while (idx >= 0) {
        start = starts[idx];
        end = endes[idx];

        if (direction == -1) {
            visits.insert(nexts[idx] - 1);
        }

        direction = -1;

        next = nexts[idx];
        it = visits.find(next);
        if (it == visits.end()) {
            it = visits.begin();
            while (it != visits.end()) {
                if (*it > next) {
                    break;
                }
                it++;
            }
        }
        while (it != visits.end()) {
            i = *it;
            if (bridges[i] >= start && bridges[i] <= end) {
                nexts[idx] = i + 1;
                visits.erase(i);
                results[idx] = i + 1;
                direction = 1;
                break;
            }
            it++;
        }

        idx += direction;
        if (idx == n) {
            return true;
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    int i;
    unsigned long long left, right, prevLeft, prevRight;

    scanf("%d %d", &n, &m);

    scanf("%I64d %I64d", &prevLeft, &prevRight);

    i = 0;
    n--;
    while (i < n) {
        scanf("%I64d %I64d", &left, &right);
        starts[i] = left - prevRight;
        endes[i] = right - prevLeft;
        prevLeft = left;
        prevRight = right;
        i++;
    }

    i = 0;
    while (i < m) {
        scanf("%I64d", &bridges[i++]);
    }

    if (n <= m && useBridges() == true) {
        printf("Yes\n");
        for (i = 0; i < n; i++) {
            printf("%d ", results[i]);
        }
        printf("\n");
    } else {
        printf("No\n");
    }

    return 0;
}

/*
4 4
1 4
7 8
9 10
12 14
4 5 3 8
=====
Yes
2 3 1 

2 2
11 14
17 18
2 9
=====
No

2 1
1 1
1000000000000000000 1000000000000000000
999999999999999999
=====
Yes
1 
*/
