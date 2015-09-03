// http://community.topcoder.com/stat?c=problem_statement&pm=13744&rd=16515

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DevuAndGame {
public:
	string canWin(vector<int> nextLevel) {
		int i, t;

		i = 0;
		while (nextLevel[i] >= 0) {
			t = nextLevel[i];
			nextLevel[i] = -2;
			i = t;
		}

		return nextLevel[i] == -1 ? "Win" : "Lose";
	}
};

int main(int argc, char* argv[]) {
	int data[6][48] = {
		{1, -1},
		{1, 0, -1},
		{0, 1, 2},
		{29, 33, 28, 16, -1, 11, 10, 14, 6, 31, 7, 35, 34, 8, 15, 17, 26, 12, 13, 22, 1, 20, 2, 21, -1, 5, 19, 9, 18, 4, 25, 32, 3, 30, 23, 10, 27},
		{17, 43, 20, 41, 42, 15, 18, 35, -1, 31, 7, 33, 23, 33, -1, -1, 0, 33, 19, 12, 42, -1, -1, 9, 9, -1, 39, -1, 31, 46, -1, 20, 44, 41, -1, -1, 12, -1, 36, -1, -1, 6, 47, 10, 2, 4, 1, 29},
		{3, 1, 1, 2, -1, 4}
	};
	vector<int> nextLevel;
	DevuAndGame game;

	nextLevel.assign(data[0], data[0] + 2);
	cout << game.canWin(nextLevel) << "\n";

	nextLevel.assign(data[1], data[1] + 3);
	cout << game.canWin(nextLevel) << "\n";

	nextLevel.assign(data[2], data[2] + 3);
	cout << game.canWin(nextLevel) << "\n";

	nextLevel.assign(data[3], data[3] + 37);
	cout << game.canWin(nextLevel) << "\n";

	nextLevel.assign(data[4], data[4] + 48);
	cout << game.canWin(nextLevel) << "\n";

	nextLevel.assign(data[5], data[5] + 6);
	cout << game.canWin(nextLevel) << "\n";

	return 0;
}

/*
{1, -1}
=====
Win

{1, 0, -1}
=====
Lose

{0, 1, 2}
=====
Lose

{29, 33, 28, 16, -1, 11, 10, 14, 6, 31, 7, 35, 34, 8, 15, 17, 26, 12, 13, 22, 1, 20, 2, 21, -1, 5, 19, 9, 18, 4, 25, 32, 3, 30, 23, 10, 27}
=====
Win

{17, 43, 20, 41, 42, 15, 18, 35, -1, 31, 7, 33, 23, 33, -1, -1, 0, 33, 19, 12, 42, -1, -1, 9, 9, -1, 39, -1, 31, 46, -1, 20, 44, 41, -1, -1, 12, -1, 36, -1, -1, 6, 47, 10, 2, 4, 1, 29}
=====
Win

{3, 1, 1, 2, -1, 4}
=====
Lose
*/
