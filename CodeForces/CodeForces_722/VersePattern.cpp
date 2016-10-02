// http://codeforces.com/contest/722/problem/B

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countVowels(string str) {
	int i, count;

	count = 0;
	for (i = 0; i < str.size(); i++) {
		switch (str[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			count++;
			break;

		}
	}

	return count;
}

int main(int argc, char* argv[]) {
	vector<int> arr;
	string str;
	int n, i;
	bool ans;
	
	ans = true;

	cin >> n;
	arr.assign(n, 0);
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	getline(cin, str);
	for (i = 0; i < n; i++) {
		getline(cin, str);
		if (countVowels(str) != arr[i]) ans = false;
	}

	if (ans) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	return 0;
}

/*
3
2 2 3
intel
code
ch allenge
=====
YES

4
1 2 3 1
a
bcdefghi
jklmnopqrstu
vwxyz
=====
NO

4
13 11 15 15
to be or not to be that is the question
whether tis nobler in the mind to suffer
the slings and arrows of outrageous fortune
or to take arms against a sea of troubles
=====
YES
*/
