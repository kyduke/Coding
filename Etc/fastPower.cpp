#include <iostream>

using namespace std;

typedef long long INT64;

const INT64 MOD = 1000000007

INT64 fastPower(INT64 base, INT64 power) {
    INT64 ans;
    
    ans = 1;
    while (power > 0) {
        // Can also use (power & 1) to make code even faster
        if(power % 2 == 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        // Can also use power >>= 1; to make code even faster
        power = power / 2;
    }
    
    return ans;
}

int main() {
    cout << fastPower(2, 1) << endl; // Output: 2
    cout << fastPower(2, 2) << endl; // Output: 4
    cout << fastPower(2, 4) << endl; // Output: 16
    cout << fastPower(2, 5) << endl; // Output: 32
    cout << fastPower(-2, 5) << endl; // Output: -32
    cout << fastPower(3, 4) << endl; // Output: 81
    cout << fastPower(2, 100) << endl; // Output: 976371285
    
    return 0;
}
