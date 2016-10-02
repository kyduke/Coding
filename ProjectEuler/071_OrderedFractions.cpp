//https://projecteuler.net/problem=71

#include <iostream>

using namespace std;

int compare(int an, int ad, int bn, int bd) {
	return ((long long)an * bd) < ((long long)bn * ad) ? 1 : 0;
}

int getGCD(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main(int argc, char* argv[]) {
	int i, j, maxN, maxD;

	maxN = 2;
	maxD = 5;

	i = 1000000;
	while (i) {
		j = i * 0.428572;
		while (j) {
			if (compare(j, i, 3, 7) == 1 && getGCD(i, j) == 1) {
				if (compare(j, i, maxN, maxD) == 0) {
					maxN = j;
					maxD = i;
					cout << j << ", " << i << "\n";
					break;
				}
			}
			if (compare(j, i, maxN, maxD) == 1) {
				break;
			}
			j--;
		}
		i--;
	}

	return 0;
}
