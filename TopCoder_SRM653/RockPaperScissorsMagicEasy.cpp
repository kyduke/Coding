#include <iostream>
#include <vector>

using namespace std;

class RockPaperScissorsMagicEasy {
private:
	static const long MOD = 1000000007;

	int getPowerOf2(int);
	long long getGCD(long long, long long);
	int getCombination(int, int);
public:
	int count(vector<int>, int);
};

int RockPaperScissorsMagicEasy::getPowerOf2(int x) {
	int i;
	long long num;

	if (x == 0) return 1;

	num = 1;
	for (i = 0; i < x; i++) {
		num = (num * 2) % MOD;
	}

	return (int)num;
}

long long RockPaperScissorsMagicEasy::getGCD(long long a, long long b) {
	long long x;

	while (a > 0 && b > 0) {
		x = max(a, b);
		b = min(a, b);
		a = x - b;
	}

	return a + b;
}

int RockPaperScissorsMagicEasy::getCombination(int n, int m) {
	long long num, div, gcd;

	m = min(m, n - m);

	num = 1;
	div = 1;
	while (m) {
		num = num * n--;
		div = div * m--;
		gcd = getGCD(num, div);
		num /= gcd;
		div /= gcd;
		if (div == 1) num = num % MOD;
	}

	return (int)num;
}

int RockPaperScissorsMagicEasy::count(vector<int> card, int score) {
	long long combination, power, result;

	if (card.size() < score) return 0;

	combination = getCombination(card.size(), score);
	power = getPowerOf2(card.size() - score);

	result = (combination * power) % MOD;

	return (int)result;
}


int main(int argc, char* argv[]) {
	RockPaperScissorsMagicEasy rps;
	vector<int> card;

	card.clear();
	card.push_back(0);
	card.push_back(1);
	card.push_back(2);

	cout << rps.count(card, 2) << "\n";

	card.clear();
	card.push_back(1);
	card.push_back(2);

	cout << rps.count(card, 0) << "\n";

	card.clear();
	card.push_back(2);
	card.push_back(2);
	card.push_back(1);
	card.push_back(0);
	card.push_back(0);

	cout << rps.count(card, 10) << "\n";

	card.clear();
	card.push_back(0);
	card.push_back(0);
	card.push_back(0);
	card.push_back(0);
	card.push_back(0);
	card.push_back(0);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(1);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);
	card.push_back(2);

	cout << rps.count(card, 7) << "\n";

	card.clear();
	card.push_back(0);
	card.push_back(1);
	card.push_back(2);
	card.push_back(0);
	card.push_back(1);
	card.push_back(2);
	card.push_back(2);
	card.push_back(1);
	card.push_back(0);

	cout << rps.count(card, 8) << "\n";


	return 0;
}

/*
{0,1,2}
2
=====
6

{1,2}
0
=====
4

{2,2,1,0,0}
10
=====
0

{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
7
=====
286226628

{0,1,2,0,1,2,2,1,0}
8
=====
18
*/
