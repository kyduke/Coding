// http://codeforces.com/problemset/problem/557/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int n, mi1, mi2, mi3, ma1, ma2, ma3;

	cin >> n;
	cin >> mi1 >> ma1;
	cin >> mi2 >> ma2;
	cin >> mi3 >> ma3;

	n = n - mi1 - mi2 - mi3;

	ma1 = ma1 - mi1;
	if ((n - ma1) >= 0) {
		n = n - ma1;
		mi1 = mi1 + ma1;
	} else {
		mi1 = mi1 + n;
		n = 0;
	}

	ma2 = ma2 - mi2;
	if ((n - ma2) >= 0) {
		n = n - ma2;
		mi2 = mi2 + ma2;
	} else {
		mi2 = mi2 + n;
		n = 0;
	}

	mi3 = mi3 + n;

	cout << mi1 << " " << mi2 << " " << mi3 << "\n";

	return 0;
}

/*
6
1 5
2 6
3 7
=====
1 2 3 

10
1 2
1 3
1 5
=====
2 3 5 

6
1 3
2 2
2 2
=====
2 2 2 
*/
