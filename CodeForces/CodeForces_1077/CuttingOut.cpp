// https://codeforces.com/contest/1077/problem/D
// ing...

#include <iostream>
#include <map>

using namespace std;

typedef long long INT64;

const int SIZE = 200001;

int arr[SIZE] = {0, };

int main() {
	int n, k, i;
	map<int, int> c;
	map<int, int>::iterator ct;
	multimap<INT64, int> f, b;
	multimap<INT64, int>::iterator it, jt;
	
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		c[ arr[i] ]++;
	}
	
	for (ct = c.begin(); ct != c.end(); ct++) {
		b.insert(make_pair((ct->second * 10000000 + ct->first) * -1, ct->first));
	}
	
	i = 0;
	for (it = b.begin(); it != b.end(); it++) {
		if (i == k) break;
		f.insert(make_pair(it->first * -1, it->second));
	}
	while (it != b.end()) {
		jt = it;
		it++;
		b.erase(jt);
	}
	
	for (it = f.begin(); it != f.end(); it++) {
		cout << it->first << ": " << it->second << "\n";
	}
	for (it = b.begin(); it != b.end(); it++) {
		cout << it->first << ": " << it->second << "\n";
	}
	
	
	
	return 0;
}

/*
7 3
1 2 3 2 4 3 1
=====
1 2 3 

10 4
1 3 1 3 10 3 7 7 12 3
=====
7 3 1 3

15 2
1 2 1 1 1 2 1 1 2 1 2 1 1 1 1
=====
1 1 
*/
