// https://projecteuler.net/problem=120
// http://www.mathblog.dk/project-euler-120-maximum-remainder/

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int a, r;

	r = 0;
	for (a = 3; a <= 1000; a++) {
		r += 2 * a * ((a - 1) / 2);
	}

	cout << r << "\n";

	return 0;
}
