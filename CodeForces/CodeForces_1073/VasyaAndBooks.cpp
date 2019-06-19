// https://codeforces.com/contest/1073/problem/B

#include <iostream>
#include <set>

using namespace std;

const int SIZE = 200000;

int arr[SIZE] = {0, };

int main() {
	set<int> s;
	int n, i, j, k, c;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	j = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		if (s.find(k) != s.end()) {
			printf("0 ");
		} else {
			c = 1;
			while (arr[j] != k) {
				s.insert(arr[j]);
				j++;
				c++;
			}
			printf("%d ", c);
			s.insert(k);
			j++;
		}
	}
	
	return 0;
}

/*
3
1 2 3
2 1 3
=====
2 0 1 

5
3 1 4 2 5
4 5 1 3 2
=====
3 2 0 0 0 

6
6 5 4 3 2 1
6 5 3 4 2 1
=====
1 1 2 0 1 1 
*/
