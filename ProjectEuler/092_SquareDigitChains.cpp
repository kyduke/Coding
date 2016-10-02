// https://projecteuler.net/problem=92

#include <iostream>
#include <set>

using namespace std;

const int CACHE_MAX = 649; // (9 x 9) x 8 = 648

int cache[CACHE_MAX] = {0, };
int squares[CACHE_MAX] = {0, };
set<int> hit;

int getSquareDigitChain(int n) {
	int x, sum, temp;
	int num[10] = {0, };
	
	if (n < CACHE_MAX && squares[n] != 0) {
		return squares[n];
	}

	sum = 0;
	x = n;
	while (x) {
		temp = x % 10;
		sum += temp * temp;
		x /= 10;
	}

	x = sum;
	while (x) {
		temp = x % 10;
		num[temp]++;
		x /= 10;
	}

	// 150 -> 15
	sum = 0;
	for (x = 1; x < 10; x++) {
		while (num[x]) {
			sum = sum * 10 + x;
			num[x]--;
		}
	}

	if (n < CACHE_MAX) {
		squares[n] = sum;
	}

	return sum;
}

int getRepeatNumber(int n) {
	set<int>::iterator it;

	hit.clear();

	if (n >= CACHE_MAX) {
		n = getSquareDigitChain(n);
	}

	while (1) {
		if (cache[n] != 0) {
			for (it = hit.begin(); it != hit.end(); it++) {
				cache[*it] = cache[n];
			}
			return cache[n];
		}

		if (n == 1 || n == 89) {
			hit.insert(n);
			for (it = hit.begin(); it != hit.end(); it++) {
				cache[*it] = n;
			}
			return n;
		}

		hit.insert(n);

		n = getSquareDigitChain(n);
	}

	return 0;
}

int main(int argc, char* argv[]) {
	int i, count;

	count = 0;
	for (i = 1; i <= 10000000; i++) {
		if (getRepeatNumber(i) == 89) {
			count++;
		}
	}

	cout << count << "\n";

	return 0;
}
