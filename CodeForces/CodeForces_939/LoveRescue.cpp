// http://codeforces.com/contest/939/problem/D

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int SIZE = 100001;

int arr[26][26] = {0, };

char strA[SIZE];
char strB[SIZE];

int main(int argc, char* argv[]) {
	vector<set<int>> ss;
	set<int> s;
	set<int>::iterator it;
	int i, j, a, b, x, y, n;

	for (i = 0; i < 26; i++) {
		arr[i][i] = 1;
	}

	scanf("%d", &n);
	scanf("%s", strA);
	scanf("%s", strB);

	for (i = 0; i < n; i++) {
		a = strA[i] - 'a';
		b = strB[i] - 'a';
		if (arr[a][b] == 0) {
			for (j = 0; j < 26; j++) {
				if (arr[a][j] == 1) {
					arr[b][j] = 1;
					arr[j][b] = 1;
				}
				if (arr[b][j] == 1) {
					arr[a][j] = 1;
					arr[j][a] = 1;
				}
			}
			x = -1;
			y = -1;
			for (j = 0; j < ss.size(); j++) {
				if (ss[j].find(a) != ss[j].end() || ss[j].find(b) != ss[j].end()) {
					if (x == -1) {
						x = j;
					} else if (y == -1) {
						y = j;
					}
				}
			}
			if (x == -1) {
				s.clear();
				s.insert(a);
				s.insert(b);
				ss.push_back(s);
			} else {
				ss[x].insert(a);
				ss[x].insert(b);
				if (y != -1) {
					for (it = ss[y].begin(); it != ss[y].end(); it++) {
						ss[x].insert(*it);
					}
					ss[y].clear();
					ss.erase(ss.begin() + y);
				}
			}
		}
	}

	n = 0;
	for (i = 0; i < ss.size(); i++) {
		n += ss[i].size() - 1;
	}

	printf("%d\n", n);
	for (i = 0; i < ss.size(); i++) {
		j = 0;
		for (it = ss[i].begin(); j < ss[i].size() - 1; it++, j++) {
			printf("%c ", *it + 'a');
			it++;
			printf("%c\n", *it + 'a');
			it--;
		}
	}

	return 0;
}

/*
3
abb
dad
=====
2
a d
b a

8
drpepper
cocacola
=====
7
l e
e d
d c
c p
p o
o r
r a
*/
