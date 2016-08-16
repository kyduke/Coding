// https://www.hackerrank.com/contests/w22/challenges/polygon-making

#include <iostream>

using namespace std;

int main(){
    int i, n, a, m, sum;
    cin >> n;
    
    m = 0;
    sum = 0;
    
    i = 0;
    while (i < n){
       cin >> a;
       sum += a;
       m = max(m, a);
       i++;
    }
    
    if (n == 1) {
        cout << 2;
    } else if (n == 2) {
        m += m;
        if (m == sum) {
            cout << 2;
        } else {
            cout << 1;
        }
    } else {
        m += m;
        if (m >= sum) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    
    return 0;
}
