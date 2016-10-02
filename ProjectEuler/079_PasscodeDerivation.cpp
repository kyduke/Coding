// https://projecteuler.net/problem=79

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char keys[50][4];

void solve() {
	int before[10][10] = {0, };
	int after[10][10] = {0, };
	int beforeLength[10] = {0, };
	int afterLength[10] = {0, };
	vector<int> passcode;
	int i, j, a, b, c;

	for (i = 0; i < 50; i++) {
		a = keys[i][0];
		b = keys[i][1];
		c = keys[i][2];
		before[b][a] = 1;
		before[c][b] = 1;
		before[c][a] = 1;
		after[a][b] = 1;
		after[a][c] = 1;
		after[b][c] = 1;
	}

	for (i = 0; i < 10; i++) {
		cout << "before " << i << ": ";
		for (j = 0; j < 10; j++) {
			if (before[i][j] == 1) {
				cout << j << " ";
				beforeLength[i]++;
			}
		}
		cout << "\n";
	}

	for (i = 0; i < 10; i++) {
		cout << "after " << i << ": ";
		for (j = 0; j < 10; j++) {
			if (after[i][j] == 1) {
				cout << j << " ";
				afterLength[i]++;
			}
		}
		cout << "\n";
	}

	while (true) {
		j = passcode.size();

		for (i = 0; i < 10; i++) {
			if (beforeLength[i] == j) {
				if (j > 0 || (j == 0 && afterLength[i] > 0)) {
					passcode.push_back(i);
					break;
				}
			}
		}

		if (j == passcode.size()) {
			break;
		}
	}

	for (i = 0; i < passcode.size(); i++) {
		cout << passcode[i];
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	ifstream keyFile;
	int i;

	keyFile.open("D:/workspace/ProjectEuler_79_PasscodeDerivation/79_PasscodeDerivation.txt");
	i = 0;
	while (true) {
		keyFile >> keys[i];
		keys[i][0] -= '0';
		keys[i][1] -= '0';
		keys[i][2] -= '0';
		i++;
		if (keyFile.eof()) break;
	}
	keyFile.close();

	solve();

	return 0;
}
