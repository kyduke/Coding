#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int>& arr) {
	vector<int> last;
	int i, longest, left, right, mid;
	
	longest = 0;
	
	last.assign(arr.size() + 1, 0);
	
	for (i = 0; i < arr.size(); i++) {
		if (last[longest] < arr[i]) {
			longest++;
			last[longest] = arr[i];
			continue;
		}
		
		left = 0;
		right = longest;
		while (left < right) {
			mid = (left + right + 1) / 2;
			if (last[mid] < arr[i]) {
				left = mid;
			} else {
				right = mid - 1;
			}
		}
		if (last[left + 1] > arr[i]) {
			last[left + 1] = arr[i];
		}
	}
	
	return longest;
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
