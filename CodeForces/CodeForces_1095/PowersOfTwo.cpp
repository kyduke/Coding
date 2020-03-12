// https://codeforces.com/contest/1095/problem/C

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	int n, k, a, i, j;
	
	scanf("%d", &n);
	scanf("%d", &k);
	
	arr.push_back(n);
	while (n > k) {
		a = n - k;
		if (arr[arr.size() - 1] >= a * 2) {
			arr[arr.size() - 1] -= a * 2;
			arr.push_back(a);
		} else {
			a = arr[arr.size() - 1] / 2;
			arr[arr.size() - 1] -= a * 2;
			arr.push_back(a);
		}
		n -= a;
		if (arr[arr.size() - 1] == 1) {
			break;
		}
	}
	
	if (n == k) {
		printf("YES\n");
		a = 1;
		for (i = 0; i < arr.size(); i++) {
			for (j = 0; j < arr[i]; j++) {
				printf("%d ", a);
			}
			a *= 2;
		}
		printf("\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}

/*
9 4
=====
YES
1 2 2 4 

8 1
=====
YES
8 

5 1
=====
NO

3 7
=====
NO
*/
