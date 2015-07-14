// http://codeforces.com/contest/558/problem/A
// Lala Land and Apple Trees

#include <iostream>
#include <map>

using namespace std;

map<int, int> leftTrees;
map<int, int> rightTrees;

int getApples() {
	map<int, int>::iterator iLeft;
	map<int, int>::iterator iRight;
	int leftFirstCount, rightFirstCount;
	int turn;

	leftFirstCount = 0;
	turn = -1;
	iLeft = leftTrees.begin();
	iRight = rightTrees.begin();
	while (1) {
		if (turn == -1) {
			turn = 1;
			if (iLeft == leftTrees.end()) break;
			leftFirstCount += iLeft->second;
			iLeft++;
		} else {
			turn = -1;
			if (iRight == rightTrees.end()) break;
			leftFirstCount += iRight->second;
			iRight++;
		}
	}

	rightFirstCount = 0;
	turn = 1;
	iLeft = leftTrees.begin();
	iRight = rightTrees.begin();
	while (1) {
		if (turn == -1) {
			turn = 1;
			if (iLeft == leftTrees.end()) break;
			rightFirstCount += iLeft->second;
			iLeft++;
		} else {
			turn = -1;
			if (iRight == rightTrees.end()) break;
			rightFirstCount += iRight->second;
			iRight++;
		}
	}

	return max(leftFirstCount, rightFirstCount);
}

int main(int argc, char* argv[]) {
	int n, tree, apple;

	cin >> n;
	while (n--) {
		cin >> tree >> apple;

		if (tree < 0) {
			tree *= -1;
			leftTrees.insert(make_pair(tree, apple));
		} else {
			rightTrees.insert(make_pair(tree, apple));
		}
	}

	cout << getApples() << "\n";

	return 0;
}

/*
2
-1 5
1 5
=====
10

3
-2 2
1 4
-1 3
=====
9

3
1 9
3 5
7 10
=====
9
*/
