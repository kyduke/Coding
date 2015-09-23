// https://projecteuler.net/problem=122

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 200;
const int DEPTH = 11;

int counts[SIZE + 1];
int trees[SIZE + 1];

void calcCount(int depth, int num) {
	int i, n;
	if (depth > DEPTH || num > SIZE) return;

	for (i = depth - 1; i >= 0; i--) {
		n = num + trees[i];
		if (n <= SIZE && (counts[n] == 0 || counts[n] >= depth)) {
			counts[n] = depth;
			trees[depth] = n;
			calcCount(depth + 1, n);
		}
	}
}

int main(int argc, char* argv[]) {
	int sum;

	trees[0] = 1;
	calcCount(1, 1);

	sum = 0;
	for (int i = 0; i <= SIZE; i++) {
		sum += counts[i];
	}

	cout << sum << "\n";

	return 0;
}
