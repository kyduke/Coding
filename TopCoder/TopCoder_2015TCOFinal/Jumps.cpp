//
//  main.cpp
//  TopCoder_2015TCOFinal_Jumps
//
//  Created by Youngduke Koh on 11/15/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// https://community.topcoder.com/stat?c=problem_statement&pm=13975&rd=16615

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long INT64;

const INT64 LIMIT = 1000000000000000000;

struct Object {
    INT64 n;
    INT64 step;
    int count;
    Object(int v, int s, int c) : n(v), step(s), count(c) {}
};

class Jumps {
private:
    vector<INT64> p;
    vector<int> v;
    bool visitLimit;
    bool isValid(INT64 n, INT64 step, int count) {
        INT64 left, right;
        int i;
        bool leftFound, rightFound, finish;
        
        if (count == p.size()) return true;
        
        left = n - step;
        if (left < 0) left = 0;
        right = n + step;
        if (right > LIMIT) {
            right = LIMIT;
            if (visitLimit == true) right = LIMIT + 1;
        }
        
        leftFound = false;
        rightFound = false;
        finish = true;
        for (i = 0; i < p.size(); i++) {
            if (v[i] == 1) continue;
            if (p[i] == left) {
                leftFound = true;
                v[i] = 1;
                if (isValid(p[i], step * 2, count + 1) == true) return true;
                v[i] = 0;
            } else if (p[i] == right) {
                rightFound = true;
                if (right == LIMIT) visitLimit = true;
                v[i] = 1;
                if (isValid(p[i], step * 2, count + 1) == true) return true;
                v[i] = 0;
            
            } else if (p[i] < left || p[i] > right) {
                finish = false;
            }
        }
        if (finish == false) {
            if (leftFound == false && left > 0 && isValid(left, step * 2, count) == true) return true;
            if (rightFound == false && right == LIMIT) visitLimit = true;
            if (rightFound == false && right <= LIMIT && isValid(right, step * 2, count) == true) return true;
        }
        
        return false;
    }
public:
    string isValidList(vector<INT64> positions) {
        int i;
        
        p = positions;
        v.clear();
        v.assign(p.size(), 0);
        
        for (i = 0; i < p.size(); i++) {
            visitLimit = false;
            v[i] = 1;
            if (isValid(p[i], 1, 1) == true) return "Valid";
            v[i] = 0;
        }
        
        return "Invalid";
    }
};

int main(int argc, const char * argv[]) {
    Jumps jumps;
    vector<INT64> positions;
    INT64 data0[] = {1, 2, 8, 16, 4};
    INT64 data1[] = {1, 2, 3};
    INT64 data2[] = {1, 2, 3, 4};
    INT64 data3[] = {6, 62, 30, 11, 10, 12};
    INT64 data4[] = {1, 1000000000000000000, 2};
    INT64 data5[] = {1, 1000000000000000000, 2, 999999999999999999};
    INT64 data6[] = {1, 1};
    
    positions.clear();
    positions.assign(data0, data0 + 5);
    cout << jumps.isValidList(positions) << "\n";
    
    positions.clear();
    positions.assign(data1, data1 + 3);
    cout << jumps.isValidList(positions) << "\n";
    
    positions.clear();
    positions.assign(data2, data2 + 4);
    cout << jumps.isValidList(positions) << "\n";
    
    positions.clear();
    positions.assign(data3, data3 + 6);
    cout << jumps.isValidList(positions) << "\n";
    
    positions.clear();
    positions.assign(data4, data4 + 3);
    cout << jumps.isValidList(positions) << "\n";
    
    positions.clear();
    positions.assign(data5, data5 + 4);
    cout << jumps.isValidList(positions) << "\n";
    
    positions.clear();
    positions.assign(data6, data6 + 2);
    cout << jumps.isValidList(positions) << "\n";
    
    return 0;
}

/*
{1, 2, 8, 16, 4}
=====
Valid

{1, 2, 3}
=====
Valid

{1, 2, 3, 4}
=====
Invalid

{6, 62, 30, 11, 10, 12}
=====
Valid

{1, 1000000000000000000, 2}
=====
Valid

{1, 1000000000000000000, 2, 999999999999999999}
=====
Invalid"

{1, 1}
=====
Invalid
 */
