//
//  main.cpp
//  ProjectEuler_129_RepunitDivisibility
//
//  Created by Young Duke Koh on 8/9/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
// https://projecteuler.net/problem=129

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BitMath {
public:
    vector<int> intToBigMath(int n) {
        vector<int> b;
        
        while (n) {
            b.push_back(n % 10);
            n /= 10;
        }
        
        if (b.size() == 0) b.push_back(0);
        
        return b;
    }
    vector<int> add(vector<int>& a, vector<int>& b) {
        vector<int> c;
        int i, n, m, p;
        
        i = 0;
        p = 0;
        while (i < a.size() || i < b.size()) {
            n = 0;
            m = 0;
            if (i < a.size()) n = a[i];
            if (i < b.size()) m = b[i];
            p = n + m + p;
            c.push_back(p % 10);
            p /= 10;
            i++;
        }
        
        if (p != 0) c.push_back(p);
        
        return c;
    }
    vector<int> multiply(vector<int>& b, int n) {
        vector<int> c;
        int i, r;
        
        c = b;
        for (i = 0; i < c.size(); i++) {
            c[i] *= n;
        }
        
        r = 0;
        for (i = 0; i < c.size(); i++) {
            c[i] += r;
            r = c[i] / 10;
            c[i] %= 10;
            if (i == c.size() - 1 && r > 0) {
                c.push_back(r);
                r = 0;
            }
        }
        
        return c;
    }
    string bitMathToString(vector<int>& b) {
        string str;
        int i;
        
        str = "";
        
        if (b.size() == 0) return str;
        
        for (i = (int)b.size() - 1; i >= 0; i--) {
            str += (b[i] + '0');
        }
        
        return str;
    }
};

int firsts[10][10] = {0, };

void buildFirsts() {
    int i, j;
    
    for (i = 1; i < 10; i++) {
        j = 1;
        firsts[(i * j) % 10][j] = i;
        j = 3;
        firsts[(i * j) % 10][j] = i;
        j = 7;
        firsts[(i * j) % 10][j] = i;
        j = 9;
        firsts[(i * j) % 10][j] = i;
    }
}

int calcA(vector<int>& b) {
    BitMath bm;
    vector<int> a, c;
    int f, i, j, answer;
    
    c = bm.intToBigMath(0);
    j = b[0];
    answer = 0;
    
    while (c.size()) {
        f = c[0];
        if (f != 1) {
            if (f == 0) {
                i = 1;
            } else {
                i = 11 - f;
            }
            if (firsts[i][j] == 0) return 0;
            a = bm.multiply(b, firsts[i][j]);
            c = bm.add(a, c);
        }
        answer++;
        c.erase(c.begin());
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    BitMath bm;
    vector<int> b1, b3, b7, b9, b10, answer;
    int a, target;
    
    buildFirsts();
    
    b1 = bm.intToBigMath(1);
    b3 = bm.intToBigMath(3);
    b7 = bm.intToBigMath(7);
    b9 = bm.intToBigMath(9);
    b10 = bm.intToBigMath(10);
    
    target = 10;
    while (true) {
        a = calcA(b1);
        if (a > target) {
            answer = b1;
            break;
        }
        a = calcA(b3);
        if (a > target) {
            answer = b3;
            break;
        }
        a = calcA(b7);
        if (a > target) {
            answer = b7;
            break;
        }
        a = calcA(b9);
        if (a > target) {
            answer = b9;
            break;
        }
        b1 = bm.add(b1, b10);
        b3 = bm.add(b3, b10);
        b7 = bm.add(b7, b10);
        b9 = bm.add(b9, b10);
    }
    cout << bm.bitMathToString(answer) << ": " << a << "\n";
    
    return 0;
}
