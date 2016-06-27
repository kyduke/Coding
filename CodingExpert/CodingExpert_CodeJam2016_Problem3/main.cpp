// LGE CodeJam 2016 Problem 3

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int solveN(string& str) {
	map<unsigned int, int> even, odd;
	map<unsigned int, int>::iterator it;
    int i, j, c;
	unsigned int mask;

	mask = 0;
	even.insert(make_pair(mask, 1));
    for (i = 0; i < str.size(); i++) {
		mask ^= 1 << (str[i] - 'a');
		if (i % 2 == 1) {
			it = even.find(mask);
			if (it == even.end()) {
				even.insert(make_pair(mask, 1));
			} else {
				it->second++;
			}
		} else {
			it = odd.find(mask);
			if (it == odd.end()) {
				odd.insert(make_pair(mask, 1));
			} else {
				it->second++;
			}
		}
    }
    
    c = 0;
    for (it = even.begin(); it != even.end(); it++) {
		c += it->second * (it->second - 1) / 2;
    }
    for (it = odd.begin(); it != odd.end(); it++) {
		c += it->second * (it->second - 1) / 2;
    }
    
    return c;
}

int solveNN(string& str) {
    vector<unsigned int> v;
    int i, j, c;
    
    v.assign(str.size() + 1, 0);
    
    for (i = 0; i < str.size(); i++) {
        v[i + 1] = v[i] ^ (1 << (str[i] - 'a'));
    }
    
    c = 0;
    for (i = 0; i < str.size(); i++) {
        for (j = i + 2; j <= str.size(); j += 2) {
            if ((v[i] ^ v[j]) == 0) c++;
        }
    }
    
    return c;
}

int main(int argc, char* argv[]) {
    int t;
    string str;
    
    cin >> t;
    while (t--) {
        cin >> str;
        cout << solveN(str) << "\n";
    }
    
    return 0;
}

/*
2
appall
mississippi
=====
4
12
*/
