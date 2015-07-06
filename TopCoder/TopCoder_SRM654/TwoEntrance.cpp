// http://community.topcoder.com/stat?c=problem_statement&pm=13692&rd=16318

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 3000;

class TwoEntrance {
private:
	int parent[SIZE][2];
	int visit[SIZE];
	int depth[SIZE];
	void fillParent(vector<int>& a, vector<int>& b, int s1, int s2) {
		queue<int> q;
		int i, t;

		for (i = 0; i < SIZE; i++) {
			parent[i][0] = -1;
			parent[i][1] = -1;
			depth[i] = -1;
		}

		q.push(s1);
		q.push(s2);
		depth[s1] = 0;
		depth[s2] = 0;
		while (q.empty() == false) {
			t = q.front();
			q.pop();
			for (i = 0; i < a.size(); i++) {
				if (a[i] == t && b[i] != -1) {
					if (parent[ b[i] ][0] == -1) {
						parent[ b[i] ][0] = t;
					} else {
						parent[ b[i] ][1] = t;
					}
					if (depth[ b[i] ] == -1) {
						q.push(b[i]);
						depth[ b[i] ] = depth[t] + 1;
						b[i] = -1;
					}
				}
				if (b[i] == t && a[i] != -1) {
					if (parent[ a[i] ][0] == -1) {
						parent[ a[i] ][0] = t;
					} else {
						parent[ a[i] ][1] = t;
					}
					if (depth[ a[i] ] == -1) {
						q.push(a[i]);
						depth[ a[i] ] = depth[t] + 1;
						a[i] = -1;
					}
				}
			}
		}
		parent[s1][0] = -1;
		parent[s2][0] = -1;
	}
	void initVisit() {
		int i;
		for (i = 0; i < SIZE; i++) {
			visit[i] = 0;
		}
	}
	int countPath(int len, int depth) {
		int i, p1, p2, c;

		if (len == depth) return 1;

		c = 0;
		for (i = 0; i < len; i++) {
			p1 = parent[i][0];
			p2 = parent[i][1];
			if (visit[i] == 0 && (p1 == -1 || visit[p1] == 0 || (p2 != -1 && visit[p2] == 0))) {
				visit[i] = 1;
				c += countPath(len, depth + 1);
				visit[i] = 0;
			}
		}

		return c;
	}
public:
	int count(vector<int> a, vector<int> b, int s1, int s2) {
		int c;

		if (a.size() == 0) return 1;

		fillParent(a, b, s1, s2);
		initVisit();
		
		return countPath(a.size() + 1, 0);
	}
};

int main(int argc, char* argv[]) {
	TwoEntrance ent;
	vector<int> a, b;
	
	a.clear();
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	b.clear();
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	cout << ent.count(a, b, 0, 1) << "\n";

	a.clear();
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	b.clear();
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	cout << ent.count(a, b, 0, 2) << "\n";
	
	a.clear();
	a.push_back(0);
	a.push_back(1);
	a.push_back(1);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(6);
	a.push_back(7);
	a.push_back(6);
	b.clear();
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);
	b.push_back(9);
	cout << ent.count(a, b, 1, 9) << "\n";
	
	a.clear();
	a.push_back(0);
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(1);
	a.push_back(2);
	a.push_back(0);
	a.push_back(6);
	a.push_back(5);
	a.push_back(10);
	a.push_back(10);
	b.clear();
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);
	b.push_back(9);
	b.push_back(10);
	b.push_back(11);
	b.push_back(12);
	cout << ent.count(a, b, 3, 6) << "\n";
	
	a.clear();
	a.push_back(0);
	b.clear();
	b.push_back(1);
	cout << ent.count(a, b, 0, 1) << "\n";
	
	return 0;
}

/*
{0, 1, 2}
{1, 2, 3}
0
1
=====
4

{0, 1, 2}
{1, 2, 3}
0
2
=====
9

{0, 1, 1, 3, 3, 3, 6, 7, 6}
{1, 2, 3, 4, 5, 6, 7, 8, 9}
1
9
=====
16000

	
{0, 0, 1, 2, 3, 1, 2, 0, 6, 5, 10, 10}
{1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10, 11, 12}
3
6
=====
310464

{0}
{1}
0
1
=====
1
*/
