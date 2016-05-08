// http://codeforces.com/contest/637/problem/B

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void solve(vector<string> senders) {
	vector<string> chats;
	set<string> s;
	int i;

	for (i = senders.size() - 1; i >= 0; i--) {
		if (s.find(senders[i]) == s.end()) {
			s.insert(senders[i]);
			chats.push_back(senders[i]);
		}
	}
	
	for (i = 0; i < chats.size(); i++) {
		cout << chats[i] << "\n";
	}
}

int main(int argc, char* argv[]) {
	vector<string> senders;
	int n, i;

	cin >> n;
	senders.assign(n, "");
	for (i = 0; i < n; i++) {
		cin >> senders[i];
	}

	solve(senders);

	return 0;
}

/*
4
alex
ivan
roman
ivan
=====
ivan
roman
alex

8
alina
maria
ekaterina
darya
darya
ekaterina
maria
alina
=====
alina
maria
ekaterina
darya
*/
