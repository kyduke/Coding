// https://code.google.com/codejam/contest/4374486/dashboard#s=p2

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	vector<int> arr;
	string a, b;
	char str[4];
	int t, n, i, j, x, y, z;
	map<string, int>::iterator mit;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		map<string, int> mi;
		vector<string> vs;
		vector<int> vc, vd;
		vector<vector<int>> vt;

		scanf("%d", &n);
		z = 0;
		while (n--) {
			scanf("%s", str);
			a = string(str);
			mit = mi.find(a);
			if (mit == mi.end()) {
				mi.insert(make_pair(a, z));
				x = z;
				z++;
				vs.push_back(a);
				vc.push_back(1);
				vd.push_back(1);
				vt.push_back(arr);
			} else {
				x = mit->second;
				vc[x]++;
				vd[x]++;
			}

			scanf("%s", str);
			b = string(str);
			mit = mi.find(b);
			if (mit == mi.end()) {
				mi.insert(make_pair(b, z));
				y = z;
				z++;
				vs.push_back(b);
				vc.push_back(-1);
				vd.push_back(1);
				vt.push_back(arr);
			} else {
				y = mit->second;
				vc[y]--;
				vd[y]++;
			}

			vt[x].push_back(y);
		}

		x = -1;
		y = -1;
		for (j = 0; j < z; j++) {
			if (vc[j] == 1) {
				x = j;
			} else if (vc[j] == -1) {
				y = j;
			}
		}

		if (x == -1) {
			x = 0;
			y = 0;
		}

		printf("Case #%d:", i);
		while (true) {
			if (vt[x].size() == 0) break;
			j = vt[x].size() - 1;
			z = vt[x][j];
			if (z == y) {
				if (j != 0 || vd[z] > 1) {
					vt[x].pop_back();
					j--;
					z = vt[x][j];
					vt[x].pop_back();
					vt[x].push_back(y);
				} else {
					vt[x].pop_back();
				}
			} else {
				vt[x].pop_back();
			}
			printf(" %s-%s", vs[x].c_str(), vs[z].c_str());
			vd[x]--;
			vd[z]--;
			x = z;
		}
		printf("\n");
	}

	return 0;
}

/*
2
1
SFO
DFW
4
MIA
ORD
DFW
JFK
SFO
DFW
JFK
MIA
=====
Case #1: SFO-DFW
Case #2: SFO-DFW DFW-JFK JFK-MIA MIA-ORD
*/
