// http://codeforces.com/problemset/problem/575/D
// https://www.dropbox.com/s/bm4n1pu75ihj8bo/editorial.pdf

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int i;

	cout << "2000\n";
	for (i = 1; i < 1001; i++) cout << i << " 1 " << i << " 2\n";
	for (i = 1000; i > 0; i--) cout << i << " 1 " << i << " 2\n";

	return 0;
}
