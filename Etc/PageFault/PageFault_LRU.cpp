#include <iostream>

using namespace std;

const int PAGE = 4;

int cache[PAGE];

int hitCache(int n) {
	int i;

	for (i = 0; i < PAGE; i++) {
		if (cache[i] == n) return i;
	}

	return -1;
}

void printCache() {
	int i;

	for (i = 0; i < PAGE; i++) {
		cout << i << " | ";
		if (cache[i] >= 0) {
			cout << cache[i];
		}
		cout << "\n";
	}
}

int main(int argc, char* argv[]) {
	int idx;
	int faults;
	int i;
	int n;
	int LRU[PAGE];
	int latest;

	for (i = 0; i < PAGE; i++) {
		cache[i] = -1;
		LRU[i] = 0;
	}
	idx = 0;

	faults = 0;
	while (1) {
		cin >> n;
		
		latest = hitCache(n);
		if (latest == -1) {
			idx = -1;
			for (i = 0; i < PAGE; i++) {
				if (LRU[i] == 0) {
					if (idx == -1) idx = i;
				} else {
					LRU[i]--;
				}
			}
			cache[idx] = n;
			LRU[idx] = PAGE - 1;
			faults++;
		} else {
			for (i = 0; i < PAGE; i++) {
				if (LRU[i] > LRU[latest]) {
					LRU[i]--;
				}
			}
			LRU[latest] = PAGE - 1;
		}

		cout << "\n\n";
		printCache();
		cout << "fault: " << faults << "\n\n";
	}
}
