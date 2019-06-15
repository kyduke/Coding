// https://www.coderbyte.com/results/kyduke:Maximal%20Square:Cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MaximalSquare(string str[]) {
  vector<int> odd, even;
  int ans, l, i, j;
  
  ans = 0;
  
  l = str[0].size();
  if (l == 0) return ans;
  
  odd.assign(l, 0);
  even.assign(l, 0);

  i = 0;
  while (true) {
    if (str[i].size() == 0) {
      break;
    }
    if (i % 2 == 0) {
      even[0] = str[i][0] - '0';
      for (j = 1; j < l; j++) {
        if (str[i][j] == '0') {
          even[j] = 0;
          continue;
        }
        even[j] = min(min(odd[j - 1], odd[j]), even[j - 1]) + 1;
        ans = max(ans, even[j]);
      }
    } else {
      odd[0] = str[i][0] - '0';
      for (j = 1; j < l; j++) {
        if (str[i][j] == '0') {
          odd[j] = 0;
          continue;
        }
        odd[j] = min(min(even[j - 1], even[j]), odd[j - 1]) + 1;
        ans = max(ans, odd[j]);
      }
    }
    i++;
  }
  
  return ans * ans;
}

int main() {
  string str[] = {"0111", "1111", "1111", "1111"};
  cout << MaximalSquare(str) << "\n";
  
  return 0;
}

/*
{"0111", "1111", "1111", "1111"}
=====
9
*/
