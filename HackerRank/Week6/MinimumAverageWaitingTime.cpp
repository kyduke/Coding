// https://www.hackerrank.com/contests/w6/challenges/minimum-average-waiting-time

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef unsigned long long UINT64;

struct Node {
    int t;
    int l;
};
struct Compare {
    bool operator() (const Node& a, const Node& b) {
        return a.l > b.l;
    }
};

map<int, vector<int>> m;

UINT64 solve(int n) {
    priority_queue<Node, vector<Node>, Compare> q;
    map<int, vector<int>>::iterator it;
    Node node;
    UINT64 sum, curr;
	int i;
    
    sum = 0;
    curr = 0;
    it = m.begin();
    while (it != m.end() || !q.empty()) {
        while (it != m.end() && it->first <= curr) {
            node.t = it->first;
			for (i = 0; i < it->second.size(); i++) {
				node.l = it->second[i];
				q.push(node);
			}
            it++;
        }
        
        if (!q.empty()) {
            node = q.top();
            q.pop();
            sum += curr + node.l - node.t;
            curr += node.l;
        } else {
            if (it != m.end()) {
                curr = it->first;
            }
        }
    }
    
    return sum / (UINT64)n;
}

int main() {
	map<int, vector<int>>::iterator it;
	vector<int> arr;
    int n, t, l, i;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &t, &l);
		it = m.find(t);
		if (it == m.end()) {
			arr.clear();
			arr.push_back(l);
			m.insert(make_pair(t, arr));
		} else {
			it->second.push_back(l);
		}
    }
    
    printf("%llu\n", solve(n));
    
    return 0;
}

/*
3
0 3
1 9
2 6
=====
9

3
0 3
1 9
2 5
=====
8
*/
