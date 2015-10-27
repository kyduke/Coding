// http://community.topcoder.com/stat?c=problem_statement&pm=14074&rd=16552

#include <iostream>
#include <string>

using namespace std;

class SubstitutionCipher {
public:
	string decode(string a, string b, string y) {
		char dictionary[26] = {0, };
		char used[26] = {0, };
		string x;
		int i, j, cnt;

		x = "";

		cnt = 0;
		for (i = 0; i < a.size(); i++) {
			if (dictionary[ b[i] - 'A' ] == 0) {
				dictionary[ b[i] - 'A' ] = a[i];
				used[ a[i] - 'A' ] = 1;
				cnt++;
			}
		}
		
		if (cnt == 25) {
			for (i = 0; i < 26; i++) {
				if (dictionary[i] == 0) {
					for (j = 0; j < 26; j++) {
						if (used[j] == 0) {
							dictionary[i] = j + 'A';
							break;
						}
					}
					break;
				}
			}
		}

		for (i = 0; i < y.size(); i++) {
			if (dictionary[ y[i] - 'A' ] == 0) return "";
			x += dictionary[ y[i] - 'A' ];
		}

		return x;
	}
};

int main(int argc, char* argv[]) {
	SubstitutionCipher cipher;

	cout << cipher.decode("CAT", "DOG", "GOD") << "\n";
	cout << cipher.decode("BANANA", "METETE", "TEMP") << "\n";
	cout << cipher.decode("THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG", "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH", "DIDYOUNOTICESKIPPEDLETTER") << "\n";

	return 0;
}

/*
CAT
DOG
GOD
=====
TAC

BANANA
METETE
TEMP
=====
""

THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG
UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH
DIDYOUNOTICESKIPPEDLETTER
=====
CHCXNTMNSHBDRJHOODCKDSSDQ
*/
