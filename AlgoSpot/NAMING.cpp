// https://algospot.com/judge/problem/read/NAMING

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

char name[400001];
int fail[400000] = {0, };

void KMPfail(int n) {
	int i, j;

	fail[0] = -1;
	for (i = 1; i < n; i++) {
		j = fail[i - 1] + 1;
		while (name[i] != name[j] && j > 0) {
			j = fail[j - 1] + 1;
		}
		if (name[i] == name[j]) {
			fail[i] = j;
		} else {
			fail[i] = -1;
		}
	}
}

int main(int argc, char* argv[]) {
	int l;
	vector<int> result;

	scanf("%s", name);
	l = strlen(name);
	scanf("%s", &name[l]);
	l = strlen(name);

	KMPfail(l);

	while (l > 0) {
		result.push_back(l);
		l = fail[l - 1] + 1;
	}

	l = result.size() - 1;
	while (l >= 0) {
		printf("%d ", result[l]);
		l--;
	}
	printf("\n");

	return 0;
}

/*
ala
la
=====
1 3 5

ababcabababa
bcabab
=====
2 4 9 18
*/
