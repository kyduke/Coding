// https://algospot.com/judge/problem/read/ZIMBABWE

#include <iostream>
#include <string.h>

using namespace std;

const int MOD = 1000000007;

int cache[20][32768];
int elements[15];
unsigned long long priceSteps[16];
int m, length, visitAll;
unsigned long long e;
bool reachToPrice;

void makeDigits() {
	unsigned long long n;
	int i, j;
	int temp[10] = {0, };

	length = 0;
	n = e;
	j = 0;
	while (n) {
		i = n % 10;
		priceSteps[j++] = n;
		temp[i]++;
		n /= 10;
		length++;
	}
	priceSteps[j++] = 0;

	visitAll = (1 << length) - 1;

	j = 0;
	for (i = 0; i < 10; i++) {
		while (temp[i]) {
			elements[j++] = i;
			temp[i]--;
		}
	}
}

int getChance(unsigned long long t, int remainStep, int c, int visit) {
	if (reachToPrice == true) return 0;
	
	if (remainStep == 0) {
		if (t >= e) {
			reachToPrice = true;
			return 0;
		}
		return (c % m == 0) ? 1 : 0;
	}

	int& ret = cache[c][visit];
	int i, prev;
	unsigned long long a;

	if (t != priceSteps[remainStep]) {
		if (ret != -1) return ret;
	}

	ret = 0;

	prev = -1;
	for (i = 0; i < length; i++) {
		if ((visit & (1 << i)) == 0 && elements[i] != prev) {
			prev = elements[i];
			a = t * 10 + elements[i];
			ret = (ret + getChance(a, remainStep - 1, a % m, visit + (1 << i))) % MOD;
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	int c;

	cin >> c;
	while (c--) {
		cin >> e >> m;
		makeDigits();
		memset(cache, -1, sizeof(int) * 20 * 32768);
		reachToPrice = false;
		cout << getChance(0, length, 0, 0) << "\n";
	}

	return 0;
}

/*
4
321 3
123 3
422 2
12738173912 7
=====
5
0
2
11033
*/
