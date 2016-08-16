// https://www.hackerrank.com/contests/w22/challenges/cookie-party

#include <iostream>

using namespace std;

int main(){
    int n;
    int m;
    int r;
    cin >> n >> m;
    
    r = m % n;
    if (r != 0) r = n - r;
    
    cout << r;
    
    return 0;
}
