// http://careercup.com/question?id=5765503882625024

#include <iostream>

typedef unsigned short UINT16;

using namespace std;

const UINT16 MAX_UINT16 = 65535;

int totalMoney;

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

UINT16 withdrawAndReturnAll() {
	UINT16 money, all;

	money = MAX_UINT16;
	all = 0;
	while (money) {
		if (withdraw(money) == 0) money /= 2;
		else all += money;
		cout << money << ": " << totalMoney << "\n";
	}

	return all;
}

int main(int argc, char* argv[]) {
	totalMoney = 15531;
	withdrawAll();

	totalMoney = 15531;
	cout << withdrawAndReturnAll() << "\n";

	return 0;
}
