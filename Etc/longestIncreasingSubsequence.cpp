#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int>& arr) {
	vector<int> cache;
	int i, j, ans;
	
	ans = 1;
	
	cache.assign(arr.size(), 1);
	
	for (i = 1; i < arr.size(); i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j] && cache[i] < cache[j] + 1) {
				cache[i] = cache[j] + 1;
			}
		}
	}
	
	for (i = 0; i < arr.size(); i++) {
		if (ans < cache[i]) {
			ans = cache[i];
		}
	}
	
	return ans;
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	int data[] = {10, 22, 9, 33, 21, 50, 41, 60};
	int n;
	
	n = sizeof(data) / sizeof(int);
	arr.assign(data, data + n);
	printf("%d\n", lis(arr));
	
	return 0;
}
