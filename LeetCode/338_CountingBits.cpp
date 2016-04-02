// https://leetcode.com/problems/counting-bits/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int bits[1025];
public:
	Solution() {
		int i, j, k, c;

		bits[0] = 0;
		bits[1] = 1;

		k = 2;
		i = 2;
		while (i < 1025) {
			if (i == k * 2) {
				bits[i] = 1;
				i++;
				k *= 2;
				continue;
			}
			c = 0;
			j = i;
			while (j) {
				c += bits[j % k];
				j /= k;
			}
			bits[i] = c;
			i++;
		}
	}
    vector<int> countBits(int num) {
        vector<int> result;
		int i, n, c;
		
		result.assign(num + 1, 0);
		for (i = 0; i <= num; i++) {
			if (i < 1025) {
				result[i] = bits[i];
			} else {
				c = 0;
				n = i;
				while (n) {
					c += bits[n % 1024];
					n /= 1024;
				}
				result[i] = c;
			}
		}

		return result;
    }
};

void printVector(vector<int> arr) {
	int i;

	for (i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	Solution s;

	printVector(s.countBits(5));
	printVector(s.countBits(100));
	printVector(s.countBits(2048));

	return 0;
}

/*
5
=====
0 1 1 2 1 2
*/
