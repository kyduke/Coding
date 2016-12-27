// https://www.hackerrank.com/contests/w27/challenges/drawing-book

#include <iostream>

using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    
    n = n / 2;
    p = p / 2;
    
    if (n - p < p) {
        cout << n - p << "\n";
    } else {
        cout << p << "\n";
    }
    
    return 0;
}

/*
6
2
=====
1

5
4
=====
0
*/
