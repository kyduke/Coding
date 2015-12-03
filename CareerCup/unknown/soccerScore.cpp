// http://careercup.com/question?id=5640253559799808

#include <iostream>
#include <vector>

using namespace std;

int casesOfSoccerScore(int a, int b) {
	int i, j, ret;
	vector<int> even, odd; 

	if (a < b) {
		i = a;
		a = b;
		b = i;
	}

	even.assign(a + 1, 1);
	odd.assign(a + 1, 1);

	for (i = 1; i <= b; i++) {
		if (i % 2 == 0) {
			for (j = 1; j <= a; j++) {
				even[j] = even[j - 1] + odd[j];
			}
		} else {
			for (j = 1; j <= a; j++) {
				odd[j] = odd[j - 1] + even[j];
			}
		}
	}

	if (b % 2 == 0) {
		ret = even[a];
	} else {
		ret = odd[a];
	}

	return ret;
}

int main(int argc, char* argv[]) {
	cout << casesOfSoccerScore(2, 5) << "\n";

	return 0;
}
