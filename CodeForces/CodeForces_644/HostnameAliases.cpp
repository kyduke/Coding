// http://codeforces.com/contest/644/problem/C

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

string url;
string hostname;
string path;
map<int, set<int>> umap;
map<string, int> dic;
map<int, string> hosts;
int idx = 0;

void parse() {
	int i, k;

	k = url.size() - 7;
	for (i = 7; i < url.size(); i++) {
		if (url[i] == '/') {
			k = i - 7;
			break;
		}
	}

	hostname = url.substr(7, k);
	path = "" + url.substr(7 + k);
}

void fillMap() {
	map<int, set<int>>::iterator it;
	map<string, int>::iterator dt;
	set<int> s;
	int m, n;

	dt = dic.find(hostname);
	if (dt != dic.end()) {
		m = dt->second;
	} else {
		idx++;
		m = idx;
		dic.insert(make_pair(hostname, m));
		hosts.insert(make_pair(m, hostname));
	}

	dt = dic.find(path);
	if (dt != dic.end()) {
		n = dt->second;
	} else {
		idx++;
		n = idx;
		dic.insert(make_pair(path, n));
	}

	it = umap.find(m);
	if (it != umap.end()) {
		it->second.insert(n);
	} else {
		s.insert(n);
		umap.insert(make_pair(m, s));
	}
}

bool comparePath(set<int>& a, set<int>& b) {
	set<int>::iterator at, bt;

	if (a.size() != b.size()) return false;

	at = a.begin();
	bt = b.begin();
	while (at != a.end()) {
		if (*at != *bt) return false;
		at++;
		bt++;
	}

	return true;
}

void solve() {
	vector<set<int>> answer;
	set<int> s, ss;
	set<int>::iterator st;
	map<int, set<int>>::iterator it, jt;
	int i;

	for (it = umap.begin(); it != umap.end(); it++) {
		if (ss.find(it->first) != ss.end()) continue;
		s.clear();
		jt = it;
		jt++;
		while (jt != umap.end()) {
			if (comparePath(it->second, jt->second) == true) {
				s.insert(it->first);
				s.insert(jt->first);
				ss.insert(jt->first);
			}
			jt++;
		}
		if (s.size() > 0) answer.push_back(s);
	}

	cout << answer.size() << "\n";
	for (i = 0; i < answer.size(); i++) {
		s = answer[i];
		for (st = s.begin(); st != s.end(); st++) {
			cout << "http://" << hosts.find(*st)->second << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char* argv[]) {
	int n;

	cin >> n;

	while (n--) {
		cin >> url;
		parse();
		fillMap();
	}
	solve();

	return 0;
}

/*
10
http://abacaba.ru/test
http://abacaba.ru/
http://abacaba.com
http://abacaba.com/test
http://abacaba.de/
http://abacaba.ru/test
http://abacaba.de/test
http://abacaba.com/
http://abacaba.com/t
http://abacaba.com/test
=====
1
http://abacaba.de http://abacaba.ru 

14
http://c
http://ccc.bbbb/aba..b
http://cba.com
http://a.c/aba..b/a
http://abc/
http://a.c/
http://ccc.bbbb
http://ab.ac.bc.aa/
http://a.a.a/
http://ccc.bbbb/
http://cba.com/
http://cba.com/aba..b
http://a.a.a/aba..b/a
http://abc/aba..b/a
=====
2
http://cba.com http://ccc.bbbb 
http://a.a.a http://a.c http://abc 
*/
