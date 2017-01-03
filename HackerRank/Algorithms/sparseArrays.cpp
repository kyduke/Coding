// https://www.hackerrank.com/challenges/sparse-arrays

#include <iostream>
#include <map>
#include <string>

using namespace std;

unsigned int RSHash(const std::string& str) {
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    int i;

    for(i = 0; i < str.size(); i++) {
        hash = hash * a + str[i];
        a = a * b;
    }

    return (hash & 0x7FFFFFFF);
}

int main() {
    int n, q, i;
    unsigned int h;
    string str;
    map<unsigned int, int> m;
    map<unsigned int, int>::iterator it;
    
    cin >> n;
    while (n--) {
        cin >> str;
        h = RSHash(str);
        it = m.find(h);
        if (it == m.end()) {
            m[h] = 1;
        } else {
            m[h]++;
        }
    }
    
    cin >> q;
    while (q--) {
        cin >> str;
        h = RSHash(str);
        it = m.find(h);
        if (it == m.end()) {
            cout << "0\n";
        } else {
            cout << m[h] << "\n";
        }
    }
    
    return 0;
}

/*
4
aba
baba
aba
xzxb
3
aba
xzxb
ab
=====
2
1
0
*/
