// https://www.hackerrank.com/contests/w26/challenges/best-divisor

#include <iostream>

using namespace std;

int digitSum(int n) {
    int s;
    
    s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    
    return s;
}

int solve(int n) {
    int i, t, sum, ans;
    
    ans = 0;
    sum = 0;
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            t = digitSum(i);
            if (t > sum) {
                sum = t;
                ans = i;
            }
        }
    }
    
    return ans;
}

int main(){
    int n;
    
    cin >> n;
    
    cout << solve(n) << "\n";
    
    return 0;
}

/*
12
=====
6
*/
