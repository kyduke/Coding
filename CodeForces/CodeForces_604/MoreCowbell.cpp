// http://codeforces.com/contest/604/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int k, vector<int>& arr) {
    vector<int> packs;
    int i, j, s;

    sort(arr.begin(), arr.end());
    packs.assign(k, 0);

    i = arr.size() - 1;
    j = k - 1;
    while (i >= 0 && j >= 0) {
        packs[j] = arr[i];
        i--;
        j--;
    }

    j = 0;
    while (i >= 0) {
        packs[j] += arr[i];
        i--;
        j++;
    }

    s = 0;
    for (i = 0; i < k; i++) {
        if (s < packs[i]) s = packs[i];
    }

    return s;
}

int main(int argc, char* argv[]) {
    vector<int> sizes;
    int i, n, k;

    cin >> n >> k;
    sizes.assign(n, 0);
    i = 0;
    while (i < n) {
        cin >> sizes[i];
        i++;
    }

    cout << solve(k, sizes) << "\n";

    return 0;
}

/*
2 1
2 5
=====
7

4 3
2 3 5 9
=====
9

3 2
3 5 7
=====
8
*/
