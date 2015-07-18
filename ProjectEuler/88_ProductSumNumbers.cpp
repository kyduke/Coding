// https://projecteuler.net/problem=88

#include <iostream>
#include <set>

using namespace std;

int result[12001] = {0, };

void productSum(int product, int sum, int limit, int depth) {
	int i, end, tempProduct, tempSum, tempDiff;

	if (limit < depth) return;

	i = 2;
	end = limit / 2;
	if (end < 2) end = 2;
	while (i <= end) {
		tempProduct = product * i;
		tempSum = sum + i;
		tempDiff = tempProduct - tempSum + depth;
		if (depth > 1) {
			if (tempDiff > limit) break;
			if (result[tempDiff] == 0 || result[tempDiff] > tempProduct) {
				result[tempDiff] = tempProduct;
			}
		}
		productSum(tempProduct, tempSum, limit, depth + 1);
		i++;
	}
}

int main(int argc, char* argv[]) {
	int i, limit;
	unsigned long long resultSum;
	set<int> sum;
	set<int>::iterator it;

	limit = 12000;
	productSum(1, 0, limit, 1);

	for (i = 2; i <= limit; i++) {
		sum.insert(result[i]);
	}

	resultSum = 0;
	it = sum.begin();
	while (it != sum.end()) {
		if (*it < 0) {
			cout << *it << "\n";
			break;
		}
		resultSum += *it;
		it++;
	}

	cout << resultSum << "\n";

	return 0;
}
