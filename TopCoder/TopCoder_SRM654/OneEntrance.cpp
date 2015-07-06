// http://community.topcoder.com/stat?c=problem_statement&pm=13698

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 9;

class OneEntrance {
private:
	int parent[SIZE];
	int visit[SIZE];
	void fillParent(vector<int>& a, vector<int>& b, int s) {
		queue<int> q;
		int i, t;

		parent[s] = -1;
		q.push(s);
		while (q.empty() == false) {
			t = q.front();
			q.pop();
			for (i = 0; i < a.size(); i++) {
				if (a[i] == t && b[i] != -1) {
					parent[ b[i] ] = t;
					q.push(b[i]);
					b[i] = -1;
				}
				if (b[i] == t && a[i] != -1) {
					parent[ a[i] ] = t;
					q.push(a[i]);
					a[i] = -1;
				}
			}
		}
	}
	void initVisit() {
		int i;
		for (i = 0; i < SIZE; i++) {
			visit[i] = 0;
		}
	}
	int countPath(int len, int depth) {
		int i, p, c;

		if (len == depth) return 1;

		c = 0;
		for (i = 0; i < len; i++) {
			p = parent[i];
			if (visit[i] == 0 && (p == -1 || visit[p] == 0)) {
				visit[i] = 1;
				c += countPath(len, depth + 1);
				visit[i] = 0;
			}
		}

		return c;
	}
public:
	int count(vector<int> a, vector<int> b, int s) {
		if (a.size() == 0) return 1;

		fillParent(a, b, s);
		initVisit();

		return countPath(a.size() + 1, 0);
	}
};

int main(int argc, char* argv[]) {
	OneEntrance ent;
	vector<int> a, b;
	
	a.clear();
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	b.clear();
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	cout << ent.count(a, b, 0) << "\n";

	a.clear();
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	b.clear();
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	cout << ent.count(a, b, 2) << "\n";

	a.clear();
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	b.clear();
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	cout << ent.count(a, b, 0) << "\n";
	
	a.clear();
	a.push_back(7);
	a.push_back(4);
	a.push_back(1);
	a.push_back(0);
	a.push_back(1);
	a.push_back(1);
	a.push_back(6);
	a.push_back(0);
	b.clear();
	b.push_back(6);
	b.push_back(6);
	b.push_back(2);
	b.push_back(5);
	b.push_back(0);
	b.push_back(3);
	b.push_back(8);
	b.push_back(4);
	cout << ent.count(a, b, 4) << "\n";

	a.clear();
	b.clear();
	cout << ent.count(a, b, 0) << "\n";
	
	return 0;
}

/*
{0, 1, 2}
{1, 2, 3}
0
=====
1

{0, 1, 2}
{1, 2, 3}
2
=====
3

{0, 0, 0, 0}
{1, 2, 3, 4}
0
=====
24

{7, 4, 1, 0, 1, 1, 6, 0}
{6, 6, 2, 5, 0, 3, 8, 4}
4
=====
896

{}
{}
0
=====
1
*/
