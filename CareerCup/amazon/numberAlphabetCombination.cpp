// https://careercup.com/question?id=5647443522748416

#include <iostream>
#include <map>

using namespace std;

int numberAlphabetCombination(int n, map<int, int>& cache) {
	map<int, int>::iterator it;
	int count;

	if (n <= 0) return 1;

	it = cache.find(n);
	if (it != cache.end()) {
		return it->second;
	}

	count = numberAlphabetCombination(n / 10, cache);
	if ((n % 100) >= 10 && (n % 100) <= 26) {
		count += numberAlphabetCombination(n / 100, cache);
	}

	cache.insert(make_pair(n, count));
	
	return count;
}

int solve(int n) {
	map<int, int> cache;

	return numberAlphabetCombination(n, cache);
}

int main(int argc, char* argv[]) {
	cout << solve(1123) << "\n";
	cout << solve(0) << "\n";
	cout << solve(99999) << "\n";

	return 0;
}
