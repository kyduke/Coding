// https://www.hackerrank.com/challenges/luck-balance

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& contests, int k, int sum) {
    int ans, i;
    
    sort(contests.begin(), contests.end(), greater<int>());
    
    ans = sum;
    
    if (k > contests.size()) k = contests.size();
    for (i = 0; i < k; i++) {
        ans += contests[i];
    }
    
    for (; i < contests.size(); i++) {
        ans -= contests[i];
    }
    
    return ans;
}

int main() {
    vector<int> contests;
    int n, k, l, t, sum;
    
    sum = 0;
    cin >> n >> k;
    
    while (n--) {
        cin >> l >> t;
        if (t == 0) {
            sum += l;
        } else {
            contests.push_back(l);
        }
    }
    
    cout << solve(contests, k, sum) << "\n";
    
    return 0;
}

/*
6 3
5 1
2 1
1 1
8 1
10 0
5 0
=====
29
*/
