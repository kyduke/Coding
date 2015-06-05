//https://algospot.com/judge/problem/read/PACKING

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N, W;
int cache[1001][100];
char name[100][64];
int volume[100];
int urgency[100];

int getMaxUrgency(int item, int capacity) {
	if (item == N) return 0;

	int& ret = cache[capacity][item];
	if (ret != -1) return ret;

	ret = getMaxUrgency(item + 1, capacity);
	if (capacity >= volume[item]) {
		ret = max(ret, getMaxUrgency(item + 1, capacity - volume[item]) + urgency[item]);
	}

	return ret;
}

void makePackedList(int item, int capacity, vector<int>& packed) {
	if (item == N) return;
	if (getMaxUrgency(item, capacity) == getMaxUrgency(item + 1, capacity)) {
		makePackedList(item + 1, capacity, packed);
	} else {
		packed.push_back(item);
		makePackedList(item + 1, capacity - volume[item], packed);
	}
}

void solve() {
	int i, urgency;
	vector<int> packed;

	urgency = getMaxUrgency(0, W);
	makePackedList(0, W, packed);
	cout << urgency << " " << packed.size() << "\n";
	for (i = 0; i < packed.size(); i++) {
		cout << name[packed[i]] << "\n";
	}
}

int main(int argc, char *argv[]) {
	int C, i;

	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(int) * 1001 * 100);

		cin >> N >> W;

		i = 0;
		while (i < N) {
			cin >> name[i];
			cin >> volume[i];
			cin >> urgency[i];
			i++;
		}

		solve();
	}

	return 0;
}

/*
2
6 10
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4
6 17
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4
=====
24 3
laptop
camera
grinder
30 4
laptop
camera
xbox
grinder
*/
