// https://www.hackerrank.com/contests/w22/challenges/number-of-sequences

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 DIV = 1000000007;
const int SIZE = 100002;

int arr[SIZE] = {0, };
int type[SIZE] = {0, };
UINT64 mul[SIZE] = {0, };
int n;

UINT64 solve() {
	UINT64 answer;
	UINT64 i, j, k;

	for (i = 2; i <= n; i++) {
		if (type[i] != 0) continue;
		for (j = i + i; j <= n; j += i) {
			type[j]++;
			if (arr[j] == -1) {
				mul[j] = i;
				if (type[j] == 1) {
					for (k = j + j; k <= n; k += j) {
						if (arr[k] != -1) {
							type[j] = 100;
							break;
						}
					}
				}
				continue;
			}
			type[i] = 100;
			if (arr[i] == -1) continue;
			if (arr[j] % i != arr[i]) return 0;
			
		}
	}

	answer = 1;
	for (i = 2; i <= n; i++) {
		if (arr[i] != -1) continue;
		if (type[i] == 0) {
			answer = (answer * i) % DIV;
		} else if (type[i] == 1) {
			answer = (answer * mul[i]) % DIV;
		}
	}

	return answer;
}

int main(int argc, char* argv[]) {
	int i;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cout << solve();

	return 0;
}
