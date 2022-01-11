// http://codeforces.com/contest/1143/problem/B

#include <iostream>
#include <vector>
 
using namespace std;
 
int productOfArray(vector<int>& arr) {
	int i, ans;
	
	ans = 1;
	for (i = 0; i < arr.size(); i++) {
		if (arr[i] != 0) {
			ans *= arr[i];
		}
	}
	return ans;
}
 
int main() {
	vector<int> arr;
	int n, i, j, ans, temp;
	
	scanf("%d", &n);
	while (n) {
		arr.push_back(n % 10);
		n /= 10;
	}
	
	ans = productOfArray(arr);
	for (i = 1; i < arr.size(); i++) {
		arr[i - 1] = 9;
		if (arr[i] == 0) {
			continue;
		}
		arr[i]--;
		temp = productOfArray(arr);
		ans = max(ans, temp);
	}
	
	printf("%d\n", ans);
	
	return 0;
}

/*
390
==========
216

7
==========
7

1000000000
==========
387420489
*/
