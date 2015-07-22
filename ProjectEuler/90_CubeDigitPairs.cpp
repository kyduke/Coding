// https://projecteuler.net/problem=90

#include <iostream>
#include <set>

using namespace std;

set<unsigned long long> result;
int cubeOne[6];
int cubeTwo[6];
int visitOne[10] = {0, };
int visitTwo[10] = {0, };

void judgeCubes() {
	bool t01, t04, t06, t16, t18, t25, t36, t46;
	int i, j;
	unsigned long long n, m;

	t01 = t04 = t06 = t16 = t18 = t25 = t36 = t46 = false;

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (cubeOne[i] <= cubeTwo[j]) {
				n = cubeOne[i] * 10 + cubeTwo[j];
			} else {
				n = cubeTwo[j] * 10 + cubeOne[i];
			}
			if (n == 1) {
				t01 = true;
			} else if (n == 4) {
				t04 = true;
			} else if (n == 6 || n == 9) {
				t06 = true;
			} else if (n == 16 || n == 19) {
				t16 = true;
			} else if (n == 18) {
				t18 = true;
			} else if (n == 25) {
				t25 = true;
			} else if (n == 36 || n == 39) {
				t36 = true;
			} else if (n == 46 || n == 49) {
				t46 = true;
			}
		}
	}

	if (t01 && t04 && t06 && t16 && t18 && t25 && t36 && t46) {
		n = 0;
		i = 0;
		while (i < 6) {
			n = n * 10 + cubeOne[i];
			i++;
		}
		m = 0;
		j = 0;
		while (j < 6) {
			m = m * 10 + cubeTwo[j];
			j++;
		}
		if (n <= m) {
			n = n * 1000000 + m;
		} else {
			n = m * 1000000 + n;
		}
		cout << n << "\n";
		result.insert(n);
	}
}

void fillCubeTwo(int index, int start) {
	int i;

	if (index == 6) {
		judgeCubes();
		return;
	}

	for (i = start; i < 10; i++) {
		if (visitTwo[i] == 1) continue;
		visitTwo[i] = 1;
		cubeTwo[index] = i;
		fillCubeTwo(index + 1, i + 1);
		visitTwo[i] = 0;
	}
}

void fillCubeOne(int index, int start) {
	int i;

	if (index == 6) {
		fillCubeTwo(0, 0);
		return;
	}

	for (i = start; i < 10; i++) {
		if (visitOne[i] == 1) continue;
		visitOne[i] = 1;
		cubeOne[index] = i;
		fillCubeOne(index + 1, i + 1);
		visitOne[i] = 0;
	}
}

int main(int argc, char* argv[]) {

	fillCubeOne(0, 0);

	cout << result.size() << "\n";

	return 0;
}
