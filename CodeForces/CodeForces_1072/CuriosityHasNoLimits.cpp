// https://codeforces.com/contest/1072/problem/B

#include <iostream>

using namespace std;

const int SIZE = 100001;

int cache[4][4][4] = {0, };
int arr[2][SIZE] = {0, };
int ans[SIZE] = {0, };

bool check(int n) {
	int i;
	
    for (i = 1; i < n; i++) {
        ans[i] = cache[ arr[0][i - 1] ][ arr[1][i - 1] ][ ans[i - 1] ];
        if (ans[i] == -1) return false;
    }
    
    return true;
}

int main() {
	int n, i, j, k, p, x, y;
	bool flag;
	
	for (i = 0; i <= 3; i++) {
		for (j = 0; j <= 3; j++) {
			for (k = 0; k <= 3; k++) {
				cache[i][j][k] = -1;
			}
		}
	}
	
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {
            for (k = 0; k <= 3; k++) {
                for (p = 0; p<= 3; p++) {
                    x = p | k;
                    y = p & k;
                    if (x == i && y == j) cache[i][j][k] = p;
                }
            }
        }
    }
	
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d", &arr[0][i]);
	}
	for (i = 0; i < n - 1; i++) {
		scanf("%d", &arr[1][i]);
	}
	
	flag = false;
	for (i = 0; i <= 3; i++) {
        ans[0] = i;
        if (check(n) == true) {
            flag = true;
            break;
        }
    }

	if (flag == true) {
		printf("YES\n");
		for (i = 0; i < n; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}

/*
4
3 3 2
1 2 0
=====
YES
1 3 2 0 

3
1 3
3 2
=====
NO
*/
