// Suffix Array & LCP

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 100;

int ord[SIZE];
int nord[SIZE];
int cnt[SIZE];
int aux[SIZE];
int rev[SIZE];
int sfx[SIZE];
int lcp[SIZE];
char str[SIZE];

void printSuffixArrayAndLCP(int n) {
	int i;
	
	printf("%s\n", str);
	for (i = 0; i < n; i++) {
		printf("%s %d %d\n", &str[ sfx[i] ], sfx[i], lcp[i]);
	}
	printf("\n");
}

void SuffixArray(int n) {
	int i, p, pnt;

	for (i = 0; i < n; i++) {
		sfx[i] = i;
		ord[i] = str[i] - 'a' + 1;
	}
	
	p = 1;
	pnt = 1;
	while (true) {
		for (i = 0; i <= max(n, 26); i++) {
			cnt[i] = 0;
		}

		for (i = 0; i < n; i++) {
			cnt[ ord[min(i + p, n)] ]++;
		}

		for (i = 1; i <= max(n, 26); i++) {
			cnt[i] += cnt[i - 1];
		}

		for (i = n - 1; i >= 0; i--) {
			cnt[ ord[min(i + p, n)] ]--;
			aux[ cnt[ ord[min(i + p, n)] ] ] = i;
		}

		for (i = 0; i <= max(n, 26); i++) {
			cnt[i] = 0;
		}

		for (i = 0; i < n; i++) {
			cnt[ ord[i] ]++;
		}

		for (i = 1; i <= n || i <= 26; i++) {
			cnt[i] += cnt[i - 1];
		}

		for (i = n - 1; i >= 0; i--) {
			cnt[ ord[ aux[i] ] ]--;
			sfx[ cnt[ ord[ aux[i] ] ] ] = aux[i];
		}

		if (pnt == n) break;

		pnt = 1;
		nord[ sfx[0] ] = 1;

		for (i = 1; i < n; i++) {
			if (ord[ sfx[i - 1] ] != ord[ sfx[i] ] || ord[sfx[i - 1] + p] != ord[sfx[i] + p]) {
				pnt++;
			}
			nord[ sfx[i] ] = pnt;
		}

		for (i = 0; i <= n; i++) {
			ord[i] = nord[i];
		}

		p *= 2;
	}

	for (i = 0; i < n; i++) {
		rev[ sfx[i] ] = i;
	}
}

void LCP(int n) {
	int i, h, prev;

	h = 0;
	for (i = 0; i < n; i++) {
		if (rev[i]) {
			prev = sfx[rev[i] - 1];
			while (str[prev + h] == str[i + h]) h++;
			lcp[ rev[i] ] = h;
		}
		h = max(h - 1, 0);
	}
}

int main(int argc, char* argv[]) {
	strncpy(str, "banana", 6);
	str[6] = 0;

	SuffixArray(strlen(str));
	LCP(strlen(str));

	printSuffixArrayAndLCP(strlen(str));

	strncpy(str, "abracadabra", 11);
	str[11] = 0;

	SuffixArray(strlen(str));
	LCP(strlen(str));

	printSuffixArrayAndLCP(strlen(str));

	return 0;
}

/*
banana
=====
a 5 0
ana 3 1
anana 1 3
banana 0 0
na 4 0
nana 2 2

abracadabra
=====
a 10 0
abra 7 1
abracadabra 0 4
acadabra 3 1
adabra 5 1
bra 8 0
bracadabra 1 3
cadabra 4 0
dabra 6 0
ra 9 0
racadabra 2 2
*/
