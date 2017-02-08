// CodeForces 766 B.Mahmoud and a Triangle
// http://codeforces.com/contest/766/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

bool solve(vector<UINT64>& arr) {
  int i, j;

  sort(arr.begin(), arr.end());

  for (i = 0; i < arr.size() - 2; i++) {
    for (j = i + 1; j < arr.size() - 1; j++) {
      if (arr[i] + arr[j] > arr[j + 1]) return true;
    }
  }

  return false;
}

int main() {
  vector<UINT64> arr;
  int n, i;

  cin >> n;
  arr.assign(n, 0);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (solve(arr)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}

/*
5
1 5 3 2 4
=====
YES

3
4 1 2
=====
NO
*/
