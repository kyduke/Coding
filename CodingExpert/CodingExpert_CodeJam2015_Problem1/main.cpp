//LGE CodeJam 2015 Problem1

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int getPoint(char* number) {
	char line[30][4] = {"123", "321", "456", "654", "789", "987", "147", "741", "258", "852", "580", "085", "369", "963", "159", "951", "357", "753", "700", "077", "900", "099", "488", "844", "688", "866", "422", "244", "622", "266"};
	int point, i, j;
	bool matched, prevMatched;
	char a, b, c;

	point = 0;
	i = 1;
	prevMatched = false;
	while (number[i] != 0) {
		b = number[i - 1];
		c = number[i];

		matched = false;

		if (b == c) {
			matched = true;
			prevMatched = false;
		}

		if (prevMatched == true) {
			prevMatched = false;
			a = number[i - 2];
			for (j = 0; j < 18; j++) {
				if (line[j][0] == a && line[j][1] == b && line[j][2] == c) {
					matched = true;
					break;
				}
			}

			if (matched == true) {
				point += 1;
			}
		}
		
		if (matched == false) {
			for (j = 0; j < 30; j++) {
				if (line[j][0] == b && line[j][1] == c) {
					matched = true;
					prevMatched = true;
					break;
				} else if (line[j][1] == b && line[j][2] == c) {
					matched = true;
					prevMatched = true;
					break;
				}
			}

			if (matched == true) {
				point += 2;
			} else {
				point += 3;
			}

			if (i == 1) {
				point--;
			}
		}

		i++;
	}

	return point;
}

int main(int argc, char* argv[]) {
	ifstream dataFile;
	int T, N;
	char buffer[300];
	char minNumber[300];
	int minPoint, t;

	if (argc > 1) {
		dataFile.open(argv[1]);
		dataFile >> T;
		while (T--) {
			dataFile >> N;
			minPoint = 1000;
			while (N--) {
				dataFile >> buffer;

				t = getPoint(buffer);
				if (minPoint > t) {
					minPoint = t;
					strcpy(minNumber, buffer);
				}
			}
			cout << minNumber << "\n";
		}
		dataFile.close();
	} else {
		cin >> T;
		while (T--) {
			cin >> N;
			minPoint = 1000;
			while (N--) {
				cin >> buffer;

				t = getPoint(buffer);
				if (minPoint > t) {
					minPoint = t;
					strcpy(minNumber, buffer);
				}
			}
			cout << minNumber << "\n";
		}
	}

	

	return 0;
}

/*
2
4
114
119
159
158
4
1397
1793
2846
1596
=====
114
1596
*/
