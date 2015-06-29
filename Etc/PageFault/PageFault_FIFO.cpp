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

	for (i = 0; i < PAGE; i++) {
		cache[i] = -1;
	}
	idx = 0;

	faults = 0;
	while (1) {
		cin >> n;
		
		if (hitCache(n) == -1) {
			cache[idx] = n;
			idx = (idx + 1) % PAGE;
			faults++;
		}

		cout << "\n\n";
		printCache();
		cout << "fault: " << faults << "\n\n";
	}
}
