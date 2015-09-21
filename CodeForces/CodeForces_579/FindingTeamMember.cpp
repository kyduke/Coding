//
//  main.cpp
//  CodeForces_579_FindingTeamMember
//
//  Created by Youngduke Koh on 9/21/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//

// http://codeforces.com/problemset/problem/579/B

#include <iostream>
#include <map>

using namespace std;

const int SIZE = 801;

map<int, pair<int, int>> strengths;
int matchs[SIZE];
int used[SIZE];
int n;

void solve() {
    map<int, pair<int, int>>::reverse_iterator it;
    int i;
    
    it = strengths.rbegin();
    while (it != strengths.rend()) {
        if (used[it->second.first] == 0 && used[it->second.second] == 0) {
            used[it->second.first] = 1;
            used[it->second.second] = 1;
            matchs[it->second.first] = it->second.second;
            matchs[it->second.second] = it->second.first;
        }
        it++;
    }
    
    for (i = 1; i <= n; i++) {
        cout << matchs[i] << " ";
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    int i, j, s;
    
    cin >> n;
    i = 2;
    n += n;
    while (i <= n) {
        j = 1;
        while (j < i) {
            cin >> s;
            strengths.insert(make_pair(s, make_pair(i, j)));
            j++;
        }
        i++;
    }
    
    solve();
    
    return 0;
}

/*
2
6
1 2
3 4 5
=====
2 1 4 3

3
487060
3831 161856
845957 794650 976977
83847 50566 691206 498447
698377 156232 59015 382455 626960
=====
6 5 4 3 2 1
*/
