// https://www.hackerrank.com/contests/hourrank-24/challenges/kth-minimum
// Score: 19.73 / 65
// Success: 18 cases
// Timeout: 33 cases
// Abort Called: 6 cases

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long INT64;

struct Node {
    INT64 v;
    int i;
};

const int SIZE = 200001;

Node arrA[SIZE];
Node arrB[SIZE];
int curr[SIZE];
INT64 targets[SIZE];

bool nodeCompare(Node lhs, Node rhs) {
	return lhs.v < rhs.v;
}

INT64 solve(int n, int m, int k) {
	vector<INT64> arr;
	INT64 t, v;
	int i, a, b, cnt;

	sort(arrA, arrA + n, nodeCompare);
	sort(arrB, arrB + m, nodeCompare);
	
	i = 0;
	for (a = 0; a < n; a++) {
		if (arrA[a].v < 0) {
			for (b = m - 1; b >= 0; b--) {
				if (arrA[a].i <= arrB[b].i) {
					curr[a] = b;
					targets[i] = arrA[a].v * arrB[b].v;
					break;
				}
			}
		} else if (arrA[a].v > 0) {
			for (b = 0; b < m; b++) {
				if (arrA[a].i <= arrB[b].i) {
					curr[a] = b;
					targets[i] = arrA[a].v * arrB[b].v;
					break;
				}
			}
		} else {
			curr[a] = 0;
			targets[i] = 0;
		}
		i++;
	}

	sort(targets, targets + n);
	targets[n] = 40000000000;

	cnt = 0;
	for (i = 0; i <= n; i++) {
		t = targets[i];
		arr.clear();
		for (a = 0; a < n; a++) {
			if (arrA[a].v < 0) {
				b = curr[a];
				while (b >= 0) {
					if (arrA[a].i > arrB[b].i) {
						b--;
						continue;
					}
					v = arrA[a].v * arrB[b].v;
					if (t < v) break;
					arr.push_back(v);
					b--;
				}
				curr[a] = b;
			} else if (arrA[a].v > 0) {
				b = curr[a];
				while (b < m) {
					if (arrA[a].i > arrB[b].i) {
						b++;
						continue;
					}
					v = arrA[a].v * arrB[b].v;
					if (t < v) break;
					arr.push_back(v);
					b++;
				}
				curr[a] = b;
			} else {
				b = curr[a];
				while (b < m) {
					if (arrA[a].i > arrB[b].i) {
						b++;
						continue;
					}
					if (t < 0) break;
					arr.push_back(0);
					b++;
				}
				curr[a] = b;
			}
		}
		if (arr.size() + cnt >= k) break;
		cnt += arr.size();
	}

	sort(arr.begin(), arr.end());

	return arr[k - cnt - 1];
}

int main(int argc, char* argv[]) {
	int n, m, x, k, i, z, a;

	scanf("%d %d %d %d", &n, &m, &x, &k);

	z = min(n, m - x);
	for (i = 0; i < z; i++) {
		scanf("%d", &a);
		arrA[i].v = a;
		arrA[i].i = i;
	}
	for (; i < n; i++) {
		scanf("%d", &a);
	}

	for (i = 0; i < x; i++) {
		scanf("%d", &a);
	}
	for (i = 0; i < m - x; i++) {
		scanf("%d", &a);
		arrB[i].v = a;
		arrB[i].i = i;
	}

	printf("%lld\n", solve(z, m - x, k));

	return 0;
}

/*
3 4 1 5
2 -3 1
3 1 -2 -1
=====
3
*/
