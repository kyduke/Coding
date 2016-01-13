// https://algospot.com/judge/problem/read/NAMING

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> KMPFail(string& str) {
	vector<int> fail;
	int i, pos;

	fail.assign(str.size() + 1, -1);

	for (i = 1; i <= str.size(); i++) {
		pos = fail[i - 1];
		while (pos != -1 && str[pos] != str[i - 1]) {
			pos = fail[pos];
		}
		fail[i] = pos + 1;
	}

	return fail;
}

void solve(string& a, string& b) {
	vector<int> fail;
	vector<int> result;
	string str;
	int k;

	str = a + b;

	fail = KMPFail(str);

	k = str.size();
	while (k > 0) {
		result.push_back(k);
		k = fail[k];
	}

	k = result.size() - 1;
	while (k >= 0) {
		cout << result[k] << " ";
		k--;
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	
	string a, b;

	cin >> a;
	cin >> b;

	solve(a, b);

	return 0;
}

/*
ala
la
=====
1 3 5

ababcabababa
bcabab
=====
2 4 9 18
*/
