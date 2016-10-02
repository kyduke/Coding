//https://projecteuler.net/problem=68

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

long long permutation3Gon(int (&visit)[10], vector<int>& n) {
	int i, a, b, c;
	string s = "";
	char buffer[32];
	long long z;
	if (n.size() == 6) {
		a = n[0] + n[3] + n[5];
		b = n[2] + n[5] + n[4];
		c = n[1] + n[4] + n[3];
		if (a != b || a != c) {
			return 0;
		}
		cout << a << ": ";
		itoa(n[0], buffer, 10); s.append(buffer);
		itoa(n[3], buffer, 10); s.append(buffer);
		itoa(n[5], buffer, 10); s.append(buffer);
		itoa(n[2], buffer, 10); s.append(buffer);
		itoa(n[5], buffer, 10); s.append(buffer);
		itoa(n[4], buffer, 10); s.append(buffer);
		itoa(n[1], buffer, 10); s.append(buffer);
		itoa(n[4], buffer, 10); s.append(buffer);
		itoa(n[3], buffer, 10); s.append(buffer);

		z = stoll(s);
		cout << z << "\n";
		return z;
	}

	if (n.size() == 2 && n[0] > n[1]) {
		return 0;
	}

	if (n.size() == 3 && n[0] > n[2]) {
		return 0;
	}

	z = 0;
	for (i = 0; i < 6; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			n.push_back(i + 1);
			z = max(z, permutation3Gon(visit, n));
			n.pop_back();
			visit[i] = 0;
		}
	}

	return z;
}

long long permutation5Gon(int (&visit)[10], vector<int>& n) {
	int i, a, b, c, d, e;
	string s = "";
	char buffer[32];
	long long z;
	if (n.size() == 10) {
		a = n[0] + n[5] + n[9];
		b = n[4] + n[9] + n[8];
		c = n[3] + n[8] + n[7];
		d = n[2] + n[7] + n[6];
		e = n[1] + n[6] + n[5];
		if (a != b || a != c || a != d || a != e) {
			return 0;
		}
		cout << a << ": ";
		itoa(n[0], buffer, 10); s.append(buffer);
		itoa(n[5], buffer, 10); s.append(buffer);
		itoa(n[9], buffer, 10); s.append(buffer);
		itoa(n[4], buffer, 10); s.append(buffer);
		itoa(n[9], buffer, 10); s.append(buffer);
		itoa(n[8], buffer, 10); s.append(buffer);
		itoa(n[3], buffer, 10); s.append(buffer);
		itoa(n[8], buffer, 10); s.append(buffer);
		itoa(n[7], buffer, 10); s.append(buffer);
		itoa(n[2], buffer, 10); s.append(buffer);
		itoa(n[7], buffer, 10); s.append(buffer);
		itoa(n[6], buffer, 10); s.append(buffer);
		itoa(n[1], buffer, 10); s.append(buffer);
		itoa(n[6], buffer, 10); s.append(buffer);
		itoa(n[5], buffer, 10); s.append(buffer);

		if (s.length() != 16) {
			return 0;
		}

		z = stoll(s);
		cout << z << "\n";
		return z;
	}

	if (n.size() == 2 && n[0] > n[1]) {
		return 0;
	}

	if (n.size() == 3 && n[0] > n[2]) {
		return 0;
	}

	if (n.size() == 4 && n[0] > n[3]) {
		return 0;
	}

	if (n.size() == 5 && n[0] > n[4]) {
		return 0;
	}

	z = 0;
	for (i = 0; i < 10; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			n.push_back(i + 1);
			z = max(z, permutation5Gon(visit, n));
			n.pop_back();
			visit[i] = 0;
		}
	}

	return z;
}

int main(int argc, char* argv[]) {
	long long z;
	int visit[10] = {0, };
	vector<int> n;

	n.clear();
	z = permutation3Gon(visit, n);
	cout << z << "\n";

	n.clear();
	z = permutation5Gon(visit, n);
	cout << z << "\n";

	return 0;
}
