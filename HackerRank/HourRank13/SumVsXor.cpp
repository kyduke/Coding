// https://www.hackerrank.com/contests/hourrank-13/challenges/sum-vs-xor

#include <iostream>

using namespace std;

typedef unsigned long long UINT64;

int main(){
    UINT64 n, ans;
    
    cin >> n;
    
    ans = 1;
    while (n) {
        if (n % 2 == 0) {
            ans *= 2;
        }
        n /= 2;
    }
    
    cout << ans;
    
    return 0;
}
