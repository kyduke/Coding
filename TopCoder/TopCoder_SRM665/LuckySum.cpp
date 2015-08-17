// http://community.topcoder.com/stat?c=problem_statement&pm=13964&rd=16514

#include <iostream>
#include <string>

using namespace std;

class LuckySum {
private:
	long long makeNextLuckyNumber(string&);
public:
	long long construct(string);
};

long long LuckySum::makeNextLuckyNumber(string& a) {
	long long n;
	int i;
	bool found;

	found = false;
	i = a.size();
	while (i) {
		i--;
		if (a[i] == '4') {
			a[i] = '7';
			found = true;
			i++;
			while (i < a.size()) {
				a[i] = '4';
				i++;
			}
			break;
		}
	}

	if (found == false) {
		i = 0;
		while (i < a.size()) {
			a[i] = '4';
			i++;
		}
		a = "4" + a;
	}

	n = 0;
	i = 0;
	while (i < a.size()) {
		n = n * 10 + (a[i] - '0');
		i++;
	}

	return n;
}

long long LuckySum::construct(string note) {
	long long minNumber, maxNumber, n, m;
	long long ret;
	string a, b;
	int i, j;

	minNumber = 0;
	maxNumber = 0;
	i = 0;
	while (i < note.size()) {
		if (note[i] == '?') {
			if (i == 0) {
				minNumber = minNumber * 10 + 1;
			} else {
				minNumber = minNumber * 10;
			}
			maxNumber = maxNumber * 10 + 9;
		} else {
			n = note[i] - '0';
			minNumber = minNumber * 10 + n;
			maxNumber = maxNumber * 10 + n;
		}
		i++;
	}

	cout << minNumber << ", " << maxNumber << "\n";

	ret = -1;

	n = 0;
	a = "";
	while (true) {
		n = makeNextLuckyNumber(a);
		if (n > maxNumber) break;
		m = 0;
		b = "";
		while (true) {
			m = makeNextLuckyNumber(b);
			if (n + m >= minNumber && n + m <= maxNumber) {
				if (ret == -1) {
					ret = n + m;
				} else {
					ret = min(ret, n + m);
				}
			} else if (n + m > maxNumber) {
				break;
			}
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	LuckySum luckySum;

	cout << luckySum.construct("?") << "\n";
	cout << luckySum.construct("?1") << "\n";
	cout << luckySum.construct("4?8") << "\n";
	cout << luckySum.construct("2??") << "\n";
	cout << luckySum.construct("?????") << "\n";

	return 0;
}

/*
?
=====
8
    	
?1
=====
11
    	
4?8
=====
448
    	
2??
=====
-1
    	
?????
=====
11888
*/
