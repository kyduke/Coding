// http://codeforces.com/contest/723/problem/B

#include <iostream>

using namespace std;

int n;
char str[256];

void solve() {
	int i, outLength, inCount, temp;
	bool parenthese;

	parenthese = false;
	outLength = 0;
	inCount = 0;
	temp = 0;
	for (i = 0; i < n; i++) {
		if (str[i] == '_' || str[i] == '(' || str[i] == ')') {
			if (parenthese == true) {
				if ((str[i] == '_' || str[i] == ')') && temp > 0) {
					inCount++;
				}
			} else {
				outLength = max(outLength, temp);
			}
			if (str[i] == '(') {
				parenthese = true;
			} else if (str[i] == ')') {
				parenthese = false;
			}
			temp = 0;
			continue;
		}
		temp++;
	}
	outLength = max(outLength, temp);

	cout << outLength << " " << inCount;
}

int main(int argc, char* argv[]) {
	cin >> n;
	cin >> str;

	solve();

	return 0;
}

/*
37
_Hello_Vasya(and_Petya)__bye_(and_OK)
=====
5 4

37
_a_(_b___c)__de_f(g_)__h__i(j_k_l)m__
=====
2 6

27
(LoooonG)__shOrt__(LoooonG)
=====
5 2

5
(___)
=====
0 0
*/
