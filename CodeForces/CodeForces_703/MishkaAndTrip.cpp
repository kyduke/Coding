//
//  main.cpp
//  CodeForces_703_MishkaAndTrip
//
//  Created by Young Duke Koh on 8/5/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
//  http://codeforces.com/contest/703/problem/B
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

UINT64 solve(vector<int>& costs, vector<int>& capitals) {
    UINT64 answer, kCostSum, sum, kSum, temp;
    vector<UINT64> neighborCosts;
	set<int> s;
    int i, c, d, n, k;
    
    n = (int)costs.size();
    neighborCosts.assign(n, 0);
    
    answer = 0;
    sum = 0;
    for (i = 0; i < n; i++) {
        sum += costs[i];
        neighborCosts[i] = costs[(i + 1) % n] + costs[(i - 1 + n) % n];
        answer += costs[i] * costs[(i + 1) % n];
    }
    
    k = (int)capitals.size();
    kSum = 0;
    for (i = 0; i < k; i++) {
        c = capitals[i];
        answer += (sum - costs[c] - neighborCosts[c]) * costs[c];
		kSum += costs[c];
		s.insert(c);
    }

	kCostSum = 0;
	for (i = 0; i < k; i++) {
        c = capitals[i];
		temp = kSum - costs[c];
		d = (c + 1) % n;
		if (s.find(d) != s.end()) temp -= costs[d];
		d = (c - 1 + n) % n;
		if (s.find(d) != s.end()) temp -= costs[d];
        kCostSum += temp * costs[c];
    };

    return answer - kCostSum / 2;
}

int main(int argc, const char * argv[]) {
    vector<int> costs, capitals;
    int n, k, i;
    
    cin >> n >> k;
    
    costs.assign(n, 0);
    capitals.assign(k, 0);
    
    for (i = 0; i < n; i++) {
        cin >> costs[i];
    }
    
    for (i = 0; i < k; i++) {
        cin >> capitals[i];
        capitals[i]--;
    }
    
    cout << solve(costs, capitals);
    
    return 0;
}

/*
4 1
2 3 1 2
3
=====
17

5 2
3 5 2 2 4
1 4
=====
71
*/
