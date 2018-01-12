// http://codeforces.com/problemset/problem/911/C

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	int arr[3];
	
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	sort(arr, arr + 3);
	
	if (arr[0] == 1) {
		printf("YES\n");
	} else if (arr[0] == 2 && (arr[1] == 2 || (arr[1] == 4 && arr[2] == 4))) {
		printf("YES\n");
	} else if (arr[0] == 3 && arr[1] == 3 && arr[2] == 3) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}

/*
2 2 3
=====
YES

4 2 3
=====
NO
*/
