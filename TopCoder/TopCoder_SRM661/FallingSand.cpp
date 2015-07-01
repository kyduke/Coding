// http://community.topcoder.com/stat?c=problem_statement&pm=13768&rd=16464

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FallingSand {
private:
	void moveSand(string& str) {
		int start, end, oCount, i, j;

		start = 0;
		end = str.size();
		oCount = 0;
		i = 0;
		while (i < str.size()) {
			if (str[i] == 'o') {
				oCount++;
			} else if (str[i] == 'x') {
				end = i;
				for (j = start; j < end - oCount; j++) {
					str[j] = '.';
				}
				for (j = end - oCount; j < end; j++) {
					str[j] = 'o';
				}
				start = i + 1;
				end = str.size();
				oCount = 0;
			}
			i++;
		}
		if (oCount > 0 && start < end) {
			for (j = start; j < end - oCount; j++) {
				str[j] = '.';
			}
			for (j = end - oCount; j < end; j++) {
				str[j] = 'o';
			}
		}
	}
public:
	vector<string> simulate(vector<string>& board) {
		int i, j, w, h;
		string str;
		vector<string> result = board;

		w = board[0].size();
		h = board.size();
		
		for (j = 0; j < w; j++) {
			str.clear();
			for (i = 0; i < h; i++) {
				str.push_back(board[i][j]);
			}
			moveSand(str);
			for (i = 0; i < h; i++) {
				result[i][j] = str[i];
			}
		}

		return result;
	}
};

void printBoard(vector<string>& board) {
	int i;

	for (i = 0; i < board.size(); i++) {
		cout << board[i] << "\n";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	FallingSand fs;
	vector<string> board;

	board.clear();
	board.push_back("ooooo");
	board.push_back("..x..");
	board.push_back("....x");
	board.push_back(".....");
	board.push_back("....o");
	printBoard(fs.simulate(board));

	board.clear();
	board.push_back("..o..");
	board.push_back("..x.o");
	board.push_back("....x");
	board.push_back(".....");
	board.push_back("oo.oo");
	printBoard(fs.simulate(board));

	board.clear();
	board.push_back("ooooxooo.ooxo.oxoxoooox.....x.oo");
	printBoard(fs.simulate(board));

	board.clear();
	board.push_back("o");
	board.push_back(".");
	board.push_back("o");
	board.push_back(".");
	board.push_back("o");
	board.push_back(".");
	board.push_back(".");
	printBoard(fs.simulate(board));

	board.clear();
	board.push_back("oxxxxooo");
	board.push_back("xooooxxx");
	board.push_back("..xx.ooo");
	board.push_back("oooox.o.");
	board.push_back("..x.....");
	printBoard(fs.simulate(board));

	board.clear();
	board.push_back("..o..o..o..o..o..o..o..o..o..o..o");
	board.push_back("o..o..o..o..o..o..o..o..o..o..o..");
	board.push_back(".o..o..o..o..o..o..o..o..o..o..o.");
	board.push_back("...xxx...xxx...xxxxxxxxx...xxx...");
	board.push_back("...xxx...xxx...xxxxxxxxx...xxx...");
	board.push_back("...xxx...xxx......xxx......xxx...");
	board.push_back("...xxxxxxxxx......xxx......xxx...");
	board.push_back("...xxxxxxxxx......xxx......xxx...");
	board.push_back("...xxxxxxxxx......xxx......xxx...");
	board.push_back("...xxx...xxx......xxx............");
	board.push_back("...xxx...xxx...xxxxxxxxx...xxx...");
	board.push_back("...xxx...xxx...xxxxxxxxx...xxx...");
	board.push_back("..o..o..o..o..o..o..o..o..o..o..o");
	board.push_back("o..o..o..o..o..o..o..o..o..o..o..");
	board.push_back(".o..o..o..o..o..o..o..o..o..o..o.");
	printBoard(fs.simulate(board));
	
	return 0;
}

/*
ooooo
..x..
....x
.....
....o
=====
..o..
..x.o
....x
.....
oo.oo
	
..o..
..x.o
....x
.....
oo.oo
=====
..o..
..x.o
....x
.....
oo.oo
	
ooooxooo.ooxo.oxoxoooox.....x.oo
=====
ooooxooo.ooxo.oxoxoooox.....x.oo
	
o
.
o
.
o
.
.
=====
.
.
.
.
o
o
o
	
oxxxxooo
xooooxxx
..xx.ooo
oooox.o.
..x.....
=====
oxxxxooo
x.oo.xxx
..xxo...
.oo.x.o.
ooxo.ooo
	
..o..o..o..o..o..o..o..o..o..o..o
o..o..o..o..o..o..o..o..o..o..o..
.o..o..o..o..o..o..o..o..o..o..o.
...xxx...xxx...xxxxxxxxx...xxx...
...xxx...xxx...xxxxxxxxx...xxx...
...xxx...xxx......xxx......xxx...
...xxxxxxxxx......xxx......xxx...
...xxxxxxxxx......xxx......xxx...
...xxxxxxxxx......xxx......xxx...
...xxx...xxx......xxx............
...xxx...xxx...xxxxxxxxx...xxx...
...xxx...xxx...xxxxxxxxx...xxx...
..o..o..o..o..o..o..o..o..o..o..o
o..o..o..o..o..o..o..o..o..o..o..
.o..o..o..o..o..o..o..o..o..o..o.
=====
.................................
.................................
...ooo...ooo...ooooooooo...ooo...
...xxx...xxx...xxxxxxxxx...xxx...
...xxx...xxx...xxxxxxxxx...xxx...
...xxxoooxxx......xxx......xxx...
...xxxxxxxxx......xxx......xxx...
...xxxxxxxxx......xxx......xxx...
...xxxxxxxxx......xxx......xxx...
...xxx...xxx......xxx............
...xxx...xxx...xxxxxxxxx...xxx...
...xxx...xxx...xxxxxxxxx...xxx...
.................................
ooo.........ooo.........ooo...ooo
ooooooooooooooooooooooooooooooooo
*/
