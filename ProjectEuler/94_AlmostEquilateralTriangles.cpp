// http://projecteuler.net/problem=94
// http://www.mathblog.dk/project-euler-94-almost-equilateral-triangles/

#include <iostream>
#include <math.h>

using namespace std;

const unsigned long long LIMIT = 333333334;

void mathblogSolution() {
	unsigned long long x = 2;
	unsigned long long y = 1;
	unsigned long long limit = 1000000000;
	unsigned long long result = 0;
 
	while(true){
		// b = a+1
		unsigned long long aTimes3 = 2 * x - 1;
		unsigned long long areaTimes3 = y * (x - 2);
		if (aTimes3 > limit) break;
 
		if (aTimes3 > 0 &&
			areaTimes3 > 0 &&
			aTimes3 % 3 == 0 &&
			areaTimes3 % 3 == 0) {
 
			unsigned long long a = aTimes3 / 3;
			unsigned long long area = areaTimes3 / 3;
 
			result += 3 * a + 1;
			cout << a << "\n";
		}
 
		//b = a-1
		aTimes3 = 2 * x + 1;
		areaTimes3 = y * (x + 2);
 
		if (aTimes3 > 0 &&
			areaTimes3 > 0 &&
			aTimes3 % 3 == 0 &&
			areaTimes3 % 3 == 0) {
 
			unsigned long long a = aTimes3 / 3;
			unsigned long long area = areaTimes3 / 3;
 
			result += 3 * a - 1;
			cout << a << "\n";
		}
 
		unsigned long long nextx = 2 * x + y * 3;
		unsigned long long nexty = y * 2 + x;
 
		x = nextx;
		y = nexty;
	}

	cout << result << "\n";
}

int main(int argc, char* argv[]) {
	unsigned long long a, b, aa, b2, sumOfPerimeters;
	double c;

	sumOfPerimeters = 0;
	for (a = 3; a <= LIMIT; a += 2) {
		aa = a * a;
		for (b = a - 1; b <= a + 1; b += 2) {
			b2 = b / 2;
			c = sqrt((double)(aa - b2 * b2));
			if (c == (int)c) {
				sumOfPerimeters += a + a + b;
				cout << a << ", " << b << ", " << (unsigned long long)c << "\n";
			}
		}
	}

	cout << sumOfPerimeters << "\n";
	
	mathblogSolution();

	return 0;
}
