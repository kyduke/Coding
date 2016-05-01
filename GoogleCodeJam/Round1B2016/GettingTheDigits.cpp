// Google Code Jam Round1B 2016 Problem A. Getting the Digits

#include <iostream>
#include <string>

using namespace std;

string solve(string str) {
	string answer;
	int alphabets[26] = {0, };
	int digits[10] = {0, };
	int i, j;

	for (i = 0; i < str.size(); i++) {
		alphabets[str[i] - 'A']++;
	}

	//(Z)ERO T(W)O T(H)REE SI(X) EI(G)HT
	i = alphabets['Z' - 'A'];
	digits[0] = i;
	alphabets['Z' - 'A'] -= i;
	alphabets['E' - 'A'] -= i;
	alphabets['R' - 'A'] -= i;
	alphabets['O' - 'A'] -= i;

	i = alphabets['W' - 'A'];
	digits[2] = i;
	alphabets['T' - 'A'] -= i;
	alphabets['W' - 'A'] -= i;
	alphabets['O' - 'A'] -= i;

	i = alphabets['X' - 'A'];
	digits[6] = i;
	alphabets['S' - 'A'] -= i;
	alphabets['I' - 'A'] -= i;
	alphabets['X' - 'A'] -= i;

	i = alphabets['G' - 'A'];
	digits[8] = i;
	alphabets['E' - 'A'] -= i;
	alphabets['I' - 'A'] -= i;
	alphabets['G' - 'A'] -= i;
	alphabets['H' - 'A'] -= i;
	alphabets['T' - 'A'] -= i;

	//T(H)REE FOU(R) (S)EVEN
	i = alphabets['H' - 'A'];
	digits[3] = i;
	alphabets['T' - 'A'] -= i;
	alphabets['H' - 'A'] -= i;
	alphabets['R' - 'A'] -= i;
	alphabets['E' - 'A'] -= i;
	alphabets['E' - 'A'] -= i;

	i = alphabets['R' - 'A'];
	digits[4] = i;
	alphabets['F' - 'A'] -= i;
	alphabets['O' - 'A'] -= i;
	alphabets['U' - 'A'] -= i;
	alphabets['R' - 'A'] -= i;

	i = alphabets['S' - 'A'];
	digits[7] = i;
	alphabets['S' - 'A'] -= i;
	alphabets['E' - 'A'] -= i;
	alphabets['V' - 'A'] -= i;
	alphabets['E' - 'A'] -= i;
	alphabets['N' - 'A'] -= i;

	//(O)NE (F)IVE
	i = alphabets['O' - 'A'];
	digits[1] = i;
	alphabets['O' - 'A'] -= i;
	alphabets['N' - 'A'] -= i;
	alphabets['E' - 'A'] -= i;

	i = alphabets['F' - 'A'];
	digits[5] = i;
	alphabets['F' - 'A'] -= i;
	alphabets['I' - 'A'] -= i;
	alphabets['V' - 'A'] -= i;
	alphabets['E' - 'A'] -= i;

	//N(I)NE
	i = alphabets['I' - 'A'];
	digits[9] = i;
	alphabets['N' - 'A'] -= i;
	alphabets['I' - 'A'] -= i;
	alphabets['N' - 'A'] -= i;
	alphabets['E' - 'A'] -= i;

	answer = "";
	for (i = 0; i < 10; i++) {
		for (j = 0; j < digits[i]; j++) {
			answer += (char)('0' + i);
		}
	}

	return answer;
}

int main(int argc, char* argv[]) {
	int T, t;
	string str;

	cin >> T;
	t = 0;
	while (t < T) {
		cin >> str;
		t++;
		cout << "Case #" << t << ": " << solve(str) << "\n";
	}

	return 0;
}

/*
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER
=====
Case #1: 012
Case #2: 2468
Case #3: 114
Case #4: 3
*/
