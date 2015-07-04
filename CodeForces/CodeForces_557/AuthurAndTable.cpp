// http://codeforces.com/problemset/problem/557/C

#include <iostream>
#include <map>

using namespace std;

int in[100000];
int legs[100001] = {0, };
int costs[201] = {0, };

int main(int argc, char* argv[]) {
    int n, i, j, k, t;
    int maxLeg;
	int countOfLeg;
    int costOfBigger, costOfSmaller;
    int result;
	multimap<int, int> orderedLeg;
    multimap<int, int>::reverse_iterator it;

    cin >> n;
    
    maxLeg = 0;
    i = 0;
    while (i < n) {
        cin >> in[i];
        legs[in[i]]++;
        maxLeg = max(maxLeg, in[i]);
        i++;
    }

    i = 0;
    while (i < n) {
        cin >> t;
		orderedLeg.insert(pair<int, int>(in[i], t));
		costs[t]++;
        i++;
    }

    result = 20000000;
	countOfLeg = n;
    costOfBigger = 0;
	it = orderedLeg.rbegin();
	while (it != orderedLeg.rend()) {
		t = 0;
		k = it->first;
		for (i = 0; i < legs[k]; i++) {
			j = it->second;
			costs[j]--;
			t += j;
			it++;
		}

		costOfSmaller = costOfBigger;

		countOfLeg -= legs[k];
		k = countOfLeg - legs[k] + 1;
		i = 0;
		j = 1;
		while (i < k) {
			if (i + costs[j] < k) {
				costOfSmaller += j * costs[j];
				i += costs[j];
			} else {
				costOfSmaller += j * (k - i);
				i = k;
			}
			j++;
		}

		costOfBigger += t;

        result = min(result, costOfSmaller);
	}

    cout << result << "\n";

    return 0;
}

/*
2
1 5
3 2
=====
2

3
2 4 4
1 1 1
=====
0

6
2 2 1 1 3 3
4 3 5 5 2 1
=====
8
*/
