// https://projecteuler.net/problem=112

#include <iostream>

using namespace std;

enum NumberType {Unknown, Increase, Decrease, Bouncy};

NumberType cache[10000];

NumberType decisionNumberType(int n) {
	NumberType t;
	int m, c;

	t = Unknown;
	m = n % 10;
	n /= 10;
	while (n) {
		c = n % 10;
		if ((t == Increase && m < c) || (t == Decrease && m > c)) {
			t = Bouncy;
			break;
		} else if (t == Unknown) {
			if (m > c) {
				t = Increase;
			} else if (m < c) {
				t = Decrease;
			}
		}
		m = c;
		n /= 10;
	}

	return t;
}

NumberType decisionFromCache(int n) {
	NumberType t, s;
	int m;

	t = Unknown;
	while (n) {
		m = n % 10000;
		s = cache[m];
		if (s == Bouncy || (t == Increase && s == Decrease) || (t == Decrease && s == Increase)) {
			t = Bouncy;
			break;
		}
		if (s != Unknown) t = s;

		if (n / 1000 < 1000) {
			if (n / 100 < 1000) {
				if (n / 10 < 1000) {
					break;
				} else {
					n = n / 10;
				}
			} else {
				n = n / 100;
			}
		} else {
			n = n / 1000;
		}
	}

	return t;
}

int main(int argc, char* argv[]) {
	int i, count;

	cache[0] = Decrease;
	for (i = 1; i < 1000; i++) cache[i] = Bouncy;

	count = 0;
	for (i = 1; i < 1000; i++) {
		if (decisionNumberType(i) == Bouncy) count += 100;
		//cout << i << ": " << count / i << "\n";
	}

	for (i = 1000; i < 10000; i++) {
		cache[i] = decisionNumberType(i);
		if (cache[i] == Bouncy) count += 100;
		//cout << i << ": " << count / i << "\n";
	}

	i = 10000;
	while (true) {
		if (decisionFromCache(i) == Bouncy) count += 100;
		if (count / i == 99) break;
		i++;
	}

	cout << i << ": " << count / i << "\n";

	return 0;
}
