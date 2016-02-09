// https://www.hackerrank.com/challenges/lonely-integer

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int lonelyinteger(vector < int > a) {
    int i, res;
    
    res = 0;
    for (i = 0; i < a.size(); i++) {
        res ^= a[i];
    }
    
    return res;
}

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}

/*
1
1
=====
1

3
1 1 2
=====
2

5
0 0 1 2 1
=====
2
*/
