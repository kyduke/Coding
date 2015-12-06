// https://www.hackerrank.com/contests/round-2-holiday-cup/challenges/skyline

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, h, i;
    cin >> n;
    vector<int> H(n);
	bool perfect;

    for (i = 0; i < n; i++) {
       cin >> H[i];
    }

	perfect = false;
	if (n % 2 == 1) {
		perfect = true;
		h = n / 2;
		for (i = 0; i < h; i++) {
			if (H[i] != H[n - i - 1]) {
				perfect = false;
				break;
			}
		}
		for (i = 0; i < h; i++) {
			if (H[i] >= H[i + 1]) {
				perfect = false;
				break;
			}
		}
	}

	if (perfect) {
		cout << "Perfect\n";
	} else {
		cout << "Not perfect\n";
	}

	return 0;
}

/*
7
1 5 10 20 10 5 1
=====
Perfect

7
1 5 10 20 9 8 7
=====
Not perfect

5
9 8 5 8 9
=====
Not perfect
*/
