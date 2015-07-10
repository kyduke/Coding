// http://codeforces.com/problemset/problem/555/B

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<pair<unsigned long long, unsigned long long>, int> island;
typedef pair<unsigned long long, int> bridge;

const int SIZE = 200000;

vector<island> islands;
multiset<bridge> bridges;
int results[SIZE] = {0, };
int n, m;

bool sortIslandsDESC (island a, island b) {
	return (a.first.second < b.first.second);
}

bool useBridges() {
	int i, idx;
	unsigned long long start, end;
	multiset<bridge>::iterator it;

	sort(islands.begin(), islands.end(), sortIslandsDESC);
	for (i = 0; i < islands.size(); i++) {
		idx = islands[i].second;
		start = islands[i].first.first;
		end = islands[i].first.second;
		it = bridges.lower_bound(make_pair(start, 0));
        if (it == bridges.end() || it->first > end) {
            return false;
        }
		results[idx] = it->second;
		bridges.erase(it);
	}

    return true;
}

int main(int argc, char* argv[]) {
    int i;
    unsigned long long left, right, prevLeft, prevRight, t;

    scanf("%d %d", &n, &m);

    scanf("%I64d %I64d", &prevLeft, &prevRight);

    i = 0;
    n--;
    while (i < n) {
        scanf("%I64d %I64d", &left, &right);
		islands.push_back(make_pair(make_pair(left - prevRight, right - prevLeft), i));
        prevLeft = left;
        prevRight = right;
        i++;
    }

    i = 0;
    while (i < m) {
        scanf("%I64d", &t);
		bridges.insert(make_pair(t, ++i));
    }

    if (n <= m && useBridges() == true) {
        printf("Yes\n");
        for (i = 0; i < n; i++) {
            printf("%d ", results[i]);
        }
        printf("\n");
    } else {
        printf("No\n");
    }

    return 0;
}

/*
4 4
1 4
7 8
9 10
12 14
4 5 3 8
=====
Yes
2 3 1 

2 2
11 14
17 18
2 9
=====
No

2 1
1 1
1000000000000000000 1000000000000000000
999999999999999999
=====
Yes
1 
*/
