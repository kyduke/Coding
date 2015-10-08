// https://projecteuler.net/problem=125

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

const int SIZE = 4000;
const int LIMIT = 100000000;

vector<int> arr;
UINT64 squareSums[SIZE];

bool isPalindrome(int n) {
	int i, j;

	if (n < 10) return true;

	arr.clear();

	while (n) {
		arr.push_back(n % 10);
		n /= 10;
	}

	i = 0;
	j = arr.size() - 1;
	while (i < j) {
		if (arr[i] != arr[j]) return false;
		i++;
		j--;
	}

	return true;
}

void solve() {
	int i, j, n;
	UINT64 sum;
	set<int> nums;
	set<int>::iterator it;

	for (i = 1; i < SIZE; i++) {
		squareSums[i] = squareSums[i - 1] + i * i;
	}

	for (i = 0; i < SIZE; i++) {
		for (j = i + 2; j < SIZE; j++) {
			n = squareSums[j] - squareSums[i];
			if (n >= LIMIT) break;
			if (isPalindrome(n)) {
				nums.insert(n);
				cout << n << "  ";
			}
		}
	}
	cout << "\n";

	sum = 0;
	for (it = nums.begin(); it != nums.end(); it++) {
		sum += (UINT64)*it;
	}
	cout << sum << "\n";
}

int main(int argc, char* argv[]) {
	solve();

	return 0;
}
