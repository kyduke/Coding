// Ant Sequence

#include <iostream>
#include <string>

using namespace std;

string nextSequence(string& seed) {
	string result;
	int i, cnt;

	result = "";
	cnt = 1;
	for (i = 1; i <= seed.size(); i++) {
		if (i == seed.size() || seed[i - 1] != seed[i]) {
			result += seed[i - 1];
			result += cnt + '0';
			cnt = 1;
			continue;
		}
		cnt++;
	}

	return result;
}

int main(int argc, char* argv[]) {
	string seed;
	int i;

	seed = "1";
	for (i = 0; i < 30; i++) {
		cout << seed << "\n";
		seed = nextSequence(seed);
	}

	return 0;
}


/*
1
11
12
1121
122111
*/
