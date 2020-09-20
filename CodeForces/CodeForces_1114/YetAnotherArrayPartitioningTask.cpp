// http://codeforces.com/contest/1114/problem/B

#include <iostream>
#include <map>
#include <set>
#include <vector>
 
using namespace std;
 
typedef long long INT64;
 
const int SIZE = 200001;
 
int arr[SIZE] = {0, };
 
INT64 bestSum(int from, int to, int m) {
	multiset<int> s;
	multiset<int>::reverse_iterator rit;
	INT64 sum;
	int i;
		
	for (i = from; i < to; i++) {
		s.insert(arr[i]);
	}
	
	sum = 0;
	i = 0;
	for (rit = s.rbegin(); rit != s.rend(); rit++) {
		sum += *rit;
		i++;
		if (i >= m) break;
	}
	
	//cout << from << " " << to << " " << sum << "\n";
	return sum;
}
 
int main() {
	multimap<int, int> mm;
	multimap<int, int>::iterator it;
	set<int> idxSet;
	set<int>::iterator sit;
	vector<int> ans;
	int n, m, k, i, z, p;
	INT64 sum;
	
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		idxSet.insert(i);
		mm.insert(make_pair(arr[i], i));
	}
	idxSet.insert(n);
	
	z = n - m * k;
	it = mm.begin();
	while (z) {
		idxSet.erase(idxSet.find(it->second));
		z--;
		it++;
	}
	
	ans.push_back(0);
	p = 0;
	sum = 0;
	i = 0;
	for (sit = idxSet.begin(); sit != idxSet.end(); sit++) {
		if (i > 0 && i % m == 0) {
			ans.push_back(*sit);
			sum += bestSum(p, *sit, m);
			p = *sit;
		}
		i++;
	}
	
	cout << sum << "\n";
	for (i = 1; i < k; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	return 0;
}

/*
9 2 3
5 2 5 2 4 1 1 3 2
=====
21
3 5 

6 1 4
4 1 3 2 2 3
=====
12
1 3 5 

2 1 2
-1000000000 1000000000
=====
0
1 
*/
