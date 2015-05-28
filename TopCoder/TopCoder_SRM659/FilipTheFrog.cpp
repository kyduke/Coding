//http://community.topcoder.com/stat?c=problem_statement&pm=13779&rd=16462

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class FilipTheFrog {
public:
	int countReachableIslands(vector<int>, int);
};

int FilipTheFrog::countReachableIslands(vector<int> positions, int L) {
	vector<int> visit;
	queue<int> q;
	int i, c, count;

	for (i = 0; i < positions.size(); i++) {
		visit.push_back(0);
	}

	q.push(0);
	visit[0] = 1;
	count = 1;

	while (q.size()) {
		c = q.front();
		q.pop();

		for (i = 0; i < positions.size(); i++) {
			if (visit[i] == 1) continue;
			if (abs(positions[i] - positions[c]) <= L) {
				q.push(i);
				visit[i] = 1;
				count++;
			}
		}
	}

	return count;
}

int main(int argc, char *argv[]) {
	FilipTheFrog frog;
	vector<int> positions;
	int data0[] = {4, 7, 1, 3, 5};
	int data1[] = {100, 101, 103, 105, 107};
	int data2[] = {17, 10, 22, 14, 6, 1, 2, 3};
	int data3[] = {0};

	positions.clear();
	positions.assign(data0, data0 + 5);
	cout << frog.countReachableIslands(positions, 1) << "\n";

	positions.clear();
	positions.assign(data1, data1 + 5);
	cout << frog.countReachableIslands(positions, 2) << "\n";

	positions.clear();
	positions.assign(data2, data2 + 8);
	cout << frog.countReachableIslands(positions, 4) << "\n";

	positions.clear();
	positions.assign(data3, data3 + 1);
	cout << frog.countReachableIslands(positions, 1000) << "\n";

	return 0;
}
