// https://projecteuler.net/problem=87

#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

const int LIMIT = 50000000;

int limitTwo;
int limitThree;
int limitFour;

int nums[LIMIT] = {0, };
vector<int> primes;
vector<int> powerTwos;
vector<int> powerThrees;
vector<int> powerFours;
set<int> results;

void findLimits() {
	limitTwo = (int)ceil(pow(LIMIT, (double)1 / 2));
	limitThree = (int)ceil(pow(LIMIT, (double)1 / 3));
	limitFour = (int)ceil(pow(LIMIT, (double)1 / 4));

	cout << limitTwo << ", " << limitThree << ", " << limitFour << "\n";
}

void findPrimes() {
	int i, j;

	for (i = 2; i <= limitTwo; i++) {
		if (nums[i] == 0) {
			primes.push_back(i);
			for (j = i + i; j <= limitTwo; j = j + i) {
				nums[j] = 1;
			}
		}
	}

	cout << primes.size() << "\n";
}

void findPowers() {
	int i;

	i = 0;
	while (i < primes.size() && primes[i] <= limitTwo) {
		powerTwos.push_back(primes[i] * primes[i]);
		i++;
	}
	i = 0;
	while (primes[i] <= limitThree) {
		powerThrees.push_back(powerTwos[i] * primes[i]);
		i++;
	}
	i = 0;
	while (primes[i] <= limitFour) {
		powerFours.push_back(powerThrees[i] * primes[i]);
		i++;
	}
}

int getCombinations() {
	int i, j, k, t1, t2, s;
	
	for (i = 0; i < powerTwos.size(); i++) {
		t1 = powerTwos[i];
		for (j = 0; j < powerThrees.size(); j++) {
			t2 = t1 + powerThrees[j];
			if (t2 >= LIMIT) continue;
			for (k = 0; k < powerFours.size(); k++) {
				s = t2 + powerFours[k];
				if (s <= LIMIT) {
					results.insert(s);
				}
			}
		}
	}

	return results.size();
}

int main(int argc, char* argv[]) {
	findLimits();
	findPrimes();
	findPowers();

	cout << getCombinations() << "\n";

	return 0;
}
