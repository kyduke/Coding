// https://careercup.com/

#include <iostream>
#include <string>

using namespace std;

string intToString(int n) {
	string str;
	int m, k;

	if (n < 0) {
		str = "-";
		m = -n;
	} else {
		str = "";
		m = n;
	}

	k = 1;
	while ((m / k) >= 10) {
		k *= 10;
	}

	while (k > 0) {
		str += (m / k) + '0';
		m %= k;
		k /= 10;
	}

	return str;
}

int main(int argc, char* argv[]) {

	cout << 123 << ", " << intToString(123) << "\n";
	cout << -12345 << ", " << intToString(-12345) << "\n";
	cout << 0 << ", " << intToString(0) << "\n";
	cout << 2090871823 << ", " << intToString(2090871823) << "\n";
	cout << -2090871823 << ", " << intToString(-2090871823) << "\n";

	return 0;
}
