// https://algospot.com/judge/problem/read/SENTENCE

#include <iostream>
#include <string.h>

using namespace std;

char book[1000][61];
int length[1000];
int N, M;

int stringCompare(char* str) {
	int i, j, l;
	bool match;

	l = strlen(str);
	for (i = 0; i < N; i++) {
		if (length[i] >= l && book[i][0] == str[0]) {
			match = true;
			for (j = 1; j < l; j++) {
				if (book[i][j] != str[j]) {
					match = false;
					break;
				}
			}
			if (match == true) return 1;
		}
	}

	return 0;
}

int main(int argc, char* argv[]) {
	int i;
	int result;
	char str[61];

	cin >> N >> M;
	cin.getline(str, 61);

	i = 0;
	while (i < N) {
		cin.getline(book[i], 61);
		length[i] = strlen(book[i]);
		i++;
	}

	result = 0;
	while (M--) {
		cin.getline(str, 61);
		result += stringCompare(str);
	}

	cout << result << "\n";

	return 0;
}

/*
3 4
I will not buy this record, it is scratched.
My hovercraft is full of eels.
Do you want to come back to my place? Bouncy, bouncy.
I will not buy this rec
My helicopter is
Do you want to come back
I will not buy this cat.
*/
