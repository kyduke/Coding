// https://algospot.com/judge/problem/read/WILDCARD

#include <iostream>
#include <string>
#include <set>

using namespace std;

char wildcard[101];
char suffix[101];
set<string> results;

bool checkMatch(int w, int s) {
	int i;
	bool result;

	if (wildcard[w] == 0 && suffix[s] == 0) {
		return true;
	} else if (suffix[s] == 0) {
		while (wildcard[w] != 0) {
			if (wildcard[w] != '*') {
				return false;
			}
			w++;
		}
		return true;
	} else if (wildcard[w] == 0) {
		return false;
	}
	
	if (wildcard[w] == '?') {
		return checkMatch(w + 1, s + 1);
	} else if (wildcard[w] == '*') {
		i = s;
		while (suffix[i] != 0) {
			if (checkMatch(w + 1, i) == true) return true;
			i++;
		}
		if (checkMatch(w + 1, i) == true) return true;
	} else if (wildcard[w] == suffix[s]) {
		return checkMatch(w + 1, s + 1);
	}

	return false;
}

int main(int argc, char* argv[]) {
	int C, N;
	set<string>::iterator it;

	cin >> C;
	while (C--) {
		cin >> wildcard;
		results.clear();
		cin >> N;
		while (N--) {
			cin >> suffix;
			if (checkMatch(0, 0) == true) {
				results.insert(suffix);
			}
		}
		for (it = results.begin(); it != results.end(); it++) {
			cout << *it << "\n";
		}
	}

	return 0;
}

/*
2
he?p
3
help
heap
helpp
*p*
3
help
papa
hello
=====
heap
help
help
papa
*/
