// http://codeforces.com/problemset/problem/555/A
// http://codeforces.com/problemset/problem/556/C

#include <iostream>
#include <vector>

using namespace std;

int disassembleCount(vector<int>& num) {
	int disassembleCount;
	int i;
	bool continued;

	if (num[0] != 1) {
		return num.size() * 2 - 1;
	}

	disassembleCount = 0;
	while (true) {
		continued = true;
		for (i = 0; i < num.size() - 1; i++) {
			if (num[i] + 1 != num[i + 1]) {
				continued = false;
				disassembleCount++;
				num.erase(num.end() - 1, num.end());
				break;
			}
		}
		if (continued == true) break;
	}

	return disassembleCount * 2 + 1;
}

int main(int argc, char* argv[]) {
	int n, k, t, result;
	vector<int> num;

	result = -1;
	cin >> n >> k;
	while (k--) {
		cin >> n;
		num.clear();
		while (n--) {
			cin >> t;
			num.push_back(t);
		}
		result += disassembleCount(num);
	}
	cout << result << "\n";

	return 0;
}

/*
3 2
2 1 2
1 3
=====
1
7 3
3 1 3 7
2 2 5
2 4 6
=====
10
*/
