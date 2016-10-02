// https://projecteuler.net/problem=130

#include <iostream>

using namespace std;

const int SIZE = 20000;

int arr[SIZE] = {0, };

int functionA(int div) {
	int a, k;

	k = 0;
	a = 1;
	while (true) {
		k++;
		a %= div;
		if (a == 0) break;
		a = a * 10 + 1;
	}

	return k;
}

void removePrimes() {
	int i, j;

	for (i = 2; i < SIZE; i++) {
		if (arr[i] == 1) continue;
		for (j = i + i; j < SIZE; j += i) {
			arr[j] = 1;
		}
	}

	i = 2;
	for (j = i; j < SIZE; j += i) {
		arr[j] = 0;
	}

	i = 5;
	for (j = i; j < SIZE; j += i) {
		arr[j] = 0;
	}
}

int solve() {
	int i, a, k, ans;

	ans = 0;

	i = 0;
	k = 25;
	while (k) {
		i++;
		if (arr[i] == 0) continue;
		a = functionA(i);
		if ((i - 1) % a == 0) {
			k--;
			ans += i;
			cout << "A(" << i << ") = " << a << "\n";
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	removePrimes();

	cout << solve() << "\n";

	return 0;
}
