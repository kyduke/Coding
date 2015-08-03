// http://codeforces.com/problemset/problem/566/A

#include <iostream>
#include <string.h>
#include <set>
#include <map>

using namespace std;

int names[100000];
int pseudonyms[100000];
char buffers[1000000];
int n;

int getQuality(char* a, char* b) {
	int quality;

	quality = 0;
	while (*a == *b && *a != 0 && *b != 0) {
		quality++;
		a++;
		b++;
	}

	return quality;
}

void solve() {
	int i, maxA, maxB, maxQuality, tempQuality;
	set<int> a, b;
	set<int>::iterator ita;
	map<int, pair<int, int>> results;
	map<int, pair<int, int>>::iterator it;

	for (i = 0; i < n; i++) {
		a.insert(i);
		b.insert(i);
	}

	while (a.size()) {
		ita = a.begin();
		maxQuality = -1;
		for (i = 0; i < n; i++) {
			tempQuality = getQuality(&buffers[names[*ita]], &buffers[pseudonyms[i]]);
			if (tempQuality > maxQuality) {
				it = results.find(i);
				if (it != results.end()) {
					if (tempQuality > it->second.second) {
						maxQuality = tempQuality;
						maxA = *ita;
						maxB = i;
						a.insert(it->second.first);
						b.insert(it->first);
						results.erase(it);
					}
				} else {
					maxQuality = tempQuality;
					maxA = *ita;
					maxB = i;
				}
			}
		}
		results.insert(make_pair(maxB, make_pair(maxA, maxQuality)));
		a.erase(a.find(maxA));
		b.erase(b.find(maxB)); 
	}

	maxQuality = 0;
	for (it = results.begin(); it != results.end(); it++) {
		maxQuality += it->second.second;
	}
	cout << maxQuality << "\n";
	for (it = results.begin(); it != results.end(); it++) {
		cout << (it->second.first + 1) << " " << (it->first + 1) << "\n";
	}
}

int main(int argc, char* argv[]) {
	int i, index;
	char* buffer;

	cin >> n;

	index = 0;

	i = 0;
	while (i < n) {
		names[i] = index;
		buffer = &buffers[index];
		cin >> buffer;
		index += strlen(buffer) + 1;
		i++;
	}
	i = 0;
	while (i < n) {
		pseudonyms[i] = index;
		buffer = &buffers[index];
		cin >> buffer;
		index += strlen(buffer) + 1;
		i++;
	}

	solve();

	return 0;
}

/*
5
gennady
galya
boris
bill
toshik
bilbo
torin
gendalf
smaug
galadriel
=====
11
4 1
2 5
1 3
5 2
3 4
*/
