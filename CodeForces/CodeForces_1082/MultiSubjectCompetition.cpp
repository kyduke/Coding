// http://codeforces.com/contest/1082/problem/C

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int SIZE = 100001;

multiset<int> ss[SIZE];
vector<int> arr[SIZE];

int main(int argc, const char * argv[]) {
    map<int, vector<int>> mm;
    map<int, vector<int>>::iterator mit;
    multiset<int>::iterator it;
    multiset<int> candis;
    vector<int> aa;
    int n, m, i, s, r, k, sum, ans;
    
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &s, &r);
        r = -r;
        ss[s].insert(r);
    }
    
    for (i = 1; i <= m; i++) {
        sum = 0;
        for (it = ss[i].begin(); it != ss[i].end(); it++) {
            sum -= *it;
            if (sum <= 0) break;
            arr[i].push_back(sum);
        }
        if (arr[i].size() == 0) continue;
        mit = mm.find((int)arr[i].size());
        if (mit == mm.end()) {
            aa.clear();
            aa.push_back(i);
            mm.insert(make_pair((int)arr[i].size(), aa));
        } else {
            mit->second.push_back(i);
        }
        candis.insert(i);
    }
    
    ans = 0;
    i = 0;
    while (candis.size()) {
        sum = 0;
        for (it = candis.begin(); it != candis.end(); it++) {
            sum += arr[*it][i];
        }
        ans = max(ans, sum);
        mit = mm.find(i + 1);
        if (mit != mm.end()) {
            for (k = 0; k < mit->second.size(); k++) {
                candis.erase(mit->second[k]);
            }
        }
        i++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}

/*
6 3
2 6
3 6
2 5
3 5
1 9
3 1
=====
22

5 3
2 6
3 6
2 5
3 5
1 11
=====
23

5 2
1 -1
1 -5
2 -1
2 -1
1 -10
=====
0
*/
