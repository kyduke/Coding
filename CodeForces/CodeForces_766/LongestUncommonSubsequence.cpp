// CodeForces 766 A.Longest Uncommon Subsequence
// http://codeforces.com/contest/766/problem/A

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argvp[]) {
    string a, b;
    
    cin >> a >> b;
    
    if (a == b) {
        cout << "-1\n";
    } else {
        cout << max(a.size(), b.size()) << "\n";
    }
    
    return 0;
}

/*
abcd
defgh
=====
5

a
a
=====
-1
*/
