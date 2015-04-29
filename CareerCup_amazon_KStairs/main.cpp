#include <iostream>
#include <vector>

using namespace std;

bool makeStairs(vector<int>& stairs, int k, int s) {
	int i;

	if (k == 0) return true;
	if (k < s) return false;

	for (i = s; i <= k; i++) {
		stairs.push_back(i);
		if (makeStairs(stairs, k - i, i + 1)) {
			return true;
		} else {
			stairs.erase(stairs.begin() + stairs.size() - 1);
		}
	}

	return false;
}

int main(int argc, char* argv[]) {
	vector<int> stairs;
	int i, j, l, c;

	makeStairs(stairs, 50, 1);

	j = 1;
	l = stairs.size();
	for (i = 0; i < l; i++) {
		c = stairs[i];
		for (; j < c; j++) {
			cout << "0 ";
		}
		cout << c << " ";
		j++;
	}
	cout << "\n";

	return 0;
}
