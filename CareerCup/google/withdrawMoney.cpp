// http://careercup.com/question?id=5765503882625024

#include <iostream>

typedef unsigned short UINT16;

using namespace std;

const UINT16 MAX_UINT16 = 65535;

int totalMoney = 15531;

UINT16 withdraw(UINT16 n) {
	if (totalMoney < n) return 0;
	totalMoney -= n;
	return n;
}

void withdrawAll() {
	UINT16 money;

	money = MAX_UINT16;
	while (money) {
		if (withdraw(money) == 0) money /= 2;
		cout << money << ": " << totalMoney << "\n";
	}
}

int main(int argc, char* argv[]) {
	withdrawAll();

	return 0;
}
