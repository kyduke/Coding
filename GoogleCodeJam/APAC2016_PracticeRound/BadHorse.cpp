// https://code.google.com/codejam/contest/6234486/dashboard

#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[]) {
	set<string> setA, setB;
	queue<pair<string, string>> unknown;
	int T, M, c, loopCount;
	string a, b;
	bool success;

	freopen("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	cin >> T;
	c = 0;
	while (c < T) {
		cin >> M;

		setA.clear();
		setB.clear();
		while (!unknown.empty()) unknown.pop();
		success = true;

		while (M--) {
			cin >> a >> b;
			if (success == false) continue;

			if (setA.find(a) != setA.end()) {
				if (setA.find(b) != setA.end()) {
					success = false;
					continue;
				}
				setB.insert(b);
			} else if (setB.find(a) != setB.end()) {
				if (setB.find(b) != setB.end()) {
					success = false;
					continue;
				}
				setA.insert(b);
			} else if (setA.find(b) != setA.end()) {
				setB.insert(a);
			} else if (setB.find(b) != setB.end()) {
				setA.insert(a);
			} else if (setA.size() == 0) {
				setA.insert(a);
				setB.insert(b);
			} else {
				unknown.push(make_pair(a, b));
			}
		}

		if (success) {
			while (!unknown.empty()) {
				loopCount = 1000; // n by n
				while (!unknown.empty() && loopCount--) {
					a = unknown.front().first;
					b = unknown.front().second;
					unknown.pop();

					if (setA.find(a) != setA.end()) {
						if (setA.find(b) != setA.end()) {
							success = false;
							break;
						}
						setB.insert(b);
					} else if (setB.find(a) != setB.end()) {
						if (setB.find(b) != setB.end()) {
							success = false;
							break;
						}
						setA.insert(b);
					} else if (setA.find(b) != setA.end()) {
						setB.insert(a);
					} else if (setB.find(b) != setB.end()) {
						setA.insert(a);
					} else {
						unknown.push(make_pair(a, b));
					}
				}

				if (!unknown.empty()) {
					a = unknown.front().first;
					b = unknown.front().second;
					unknown.pop();
					setA.insert(a);
					setB.insert(b);
				}
			}
		}

		c++;
		cout << "Case #" << c << ": ";
		if (success) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}


/*
2
1
Dead_Bowie Fake_Thomas_Jefferson
3
Dead_Bowie Fake_Thomas_Jefferson
Fake_Thomas_Jefferson Fury_Leika
Fury_Leika Dead_Bowie
=====
Case #1: Yes
Case #2: No
*/
