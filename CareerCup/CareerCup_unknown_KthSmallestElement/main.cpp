//http://www.careercup.com/question?id=5668868003463168
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int getKthSmallestElement(vector<int> num, int k) {
	set<int> s;
	set<int>::iterator it;
	int i, l;

	l = num.size();
	for (i = 0; i < l; i++) {
		s.insert(num[i]);
	}

	i = 0;
	for (it = s.begin(); it != s.end(); it++) {
		i++;
		if (i == k) return *it;
	}

	return -1;
}

int main(int argc, char* argv[]) {
	int arr[] = {12, 3, 17, 0, 9, 6, 100};
	vector<int> num(arr, arr + sizeof(arr) / sizeof(arr[0]));

	cout << getKthSmallestElement(num, 3) << "\n";

	return 0;
}
