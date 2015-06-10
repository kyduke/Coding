//https://projecteuler.net/problem=66
//C++에서는 Big Interger 없이는 안 풀림

#include <iostream>
#include <cmath>

using namespace std;

unsigned long long getMinimumX(int D) {
	unsigned long long limit, m, d, a, num, numm1, numm2, den, denm1, denm2;

	limit = (long long)sqrt((double)D);
    if (limit * limit == D) return 0;
 
    m = 0;
    d = 1;
    a = limit;
 
    numm1 = 1;
    num = a;
 
    denm1 = 0;
    den = 1;
 
    while(num * num - D * den * den != 1){
        m = d * a - m;
        d = (D - m * m) / d;
        a = (limit + m) / d;
 
        numm2 = numm1;
        numm1 = num;
        denm2 = denm1;
        denm1 = den;
 
        num = a*numm1 + numm2;
        den = a * denm1 + denm2;
    }

	return num;
}

int main(int argc, char* argv) {
	unsigned long long d, x, md, mx;

	mx = 0;
	for (d = 2; d <= 9; d++) {
		x = getMinimumX(d);
		cout << x << ": " << d << "\n";
		if (mx < x) {
			mx = x;
			md = d;
		}
	}
	cout << "=====\n";
	cout << mx << ": " << md << "\n";

	return 0;
}
