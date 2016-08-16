// https://www.hackerrank.com/contests/w22/challenges/sequential-prefix-function
// pass 18 of 25 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int SIZE = 200002;

int a[SIZE] = {0, };
set<int> b[SIZE];
vector<int> firsts;
vector<int> seconds;
vector<int> patterns;

bool isPattern() {
	int i, dist, last;

	if (firsts.size() < 5) return false;

	for (last = patterns.size() - 1; last > 2; last--) {
		if (patterns[ last ] == 1) break;
	}

	dist = seconds[last];

	for (i = last - 1; i < firsts.size() - 1; i++) {
		if (firsts[i] + dist != firsts[i + 1]) return false;
		patterns[i] = 1;
	}

	return true;
}

int main() {
	set<int>::iterator it;
    int i, j, n, x;
    char c;
    
	firsts.push_back(0);
	seconds.push_back(0);
	patterns.push_back(0);

    cin >> n;
    i = 0;
    while (n--) {
        cin >> c;
        if (c == '+') {
            cin >> x;
            a[i] = x;
            if (i == 0) {
				firsts.push_back(i);
				seconds.push_back(1);
				patterns.push_back(0);

				b[0].insert(0);
				x = 0;
            } else {
				b[i].insert(0);
				j = 0;
				for (it = b[i - 1].begin(); it != b[i - 1].end(); it++) {
					j = *it;
					if (a[j] == a[i]) {
						b[i].insert(j + 1);
					}
				}
				if (j > 0 && a[j] == a[i] && a[i] != a[0]) {
					seconds[ seconds.size() - 1 ]++;
				}
				if (a[0] == a[i]) {
					firsts.push_back(i);
					seconds.push_back(1);
					patterns.push_back(0);

					if (isPattern() == true) {
						x = *(b[i].rbegin());
						b[i].clear();
						b[i].insert(x);
					}

					b[i].insert(1);
				}

				x = *(b[i].rbegin());
            }
            i++;
        } else {
			if (i == 0) {
				x = 0;
			} else if (i == 1) {
				i = 0;
				b[i].clear();
				x = 0;

				firsts.pop_back();
				seconds.pop_back();
				patterns.pop_back();
			} else {
				i--;

				if (a[i] == a[0]) {
					firsts.pop_back();
					seconds.pop_back();
					patterns.pop_back();
				}

				b[i].clear();
				x = *(b[i - 1].rbegin());
			}
        }
        cout << x << "\n";
    }
    
    return 0;
}
