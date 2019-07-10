// https://codeforces.com/contest/1080/problem/C

#include <iostream>
 
using namespace std;
 
typedef unsigned long long UINT64;
 
struct Rect {
	UINT64 x1;
	UINT64 y1;
	UINT64 x2;
	UINT64 y2;
};
 
struct Node {
	UINT64 all;
	UINT64 white;
	UINT64 black;
};
 
Rect intersect(Rect a, Rect b) {
	Rect rect;
	
	rect.x1 = 0;
	rect.y1 = 0;
	rect.x2 = 0;
	rect.y2 = 0;
	if (a.x1 <= b.x2 && b.x1 <= a.x2 && a.y1 <= b.y2 && b.y1 <= a.y2) {
		rect.x1 = max(a.x1, b.x1);
		rect.y1 = max(a.y1, b.y1);
		rect.x2 = min(a.x2, b.x2);
		rect.y2 = min(a.y2, b.y2);
	}
	
	return rect;
}
 
Node solve(Rect rect) {
	Node node;
	
	node.all = (rect.x2 - rect.x1 + 1) * (rect.y2 - rect.y1 + 1);
	node.white = node.all / 2;
	node.black = node.all / 2;
	if (node.all % 2 == 1) {
		if ((rect.x1 + rect.y1) % 2 == 0) {
			node.white++;
		} else {
			node.black++;
		}
	}
	
	return node;
}
 
int main() {
	Rect board, a, b, c;
	Node nBoard, nA, nB, nC;
	int t;
	UINT64 white, black;
	
	cin >> t;
	board.x1 = 1;
	board.y1 = 1;
	while (t--) {
		cin >> board.x2 >> board.y2;
		cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
		cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
		c = intersect(a, b);
		
		nBoard = solve(board);
		nA = solve(a);
		nB = solve(b);
		nC = solve(c);
		
		white = nBoard.white - nA.white - nB.white + nC.white;
		black = nBoard.black - nA.black - nB.black + nC.black;
		
		white = white + nA.all - nC.all;
		black = black + nB.all;
		
		cout << white << " " << black << "\n";
	}
	
	return 0;
}

/*
5
2 2
1 1 2 2
1 1 2 2
3 4
2 2 3 2
3 1 4 3
1 5
1 1 5 1
3 1 5 1
4 4
1 1 4 2
1 3 4 4
3 4
1 2 4 2
2 1 3 3
=====
0 4
3 9
2 3
8 8
4 8
*/
