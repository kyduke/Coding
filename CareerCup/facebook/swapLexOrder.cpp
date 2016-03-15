// https://careercup.com/question?id=5652404478410752

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

string swapLexOrder(string str, vector<pair<int, int>> pairs) {
	string result;
	queue<pair<int, int>> q;
	set<int> s;
	set<int>::iterator it;
	vector<char> c;
	int i, l, a, b;

	result = str;

	for (i = 0; i < pairs.size(); i++) {
		q.push(pairs[i]);
	}

	while (!q.empty()) {
		l = q.size();
		s.clear();
		while (l--) {
			a = q.front().first;
			b = q.front().second;
			q.pop();
			if (s.size() == 0 || s.find(a) != s.end() || s.find(b) != s.end()) {
				s.insert(a);
				s.insert(b);
				l = q.size();
				continue;
			}

			q.push(make_pair(a, b));
		}

		c.clear();
		for (it = s.begin(); it != s.end(); it++) {
			c.push_back(result[*it - 1]);
		}
		sort(c.begin(), c.end(), greater<char>());
		i = 0;
		for (it = s.begin(); it != s.end(); it++) {
			result[*it - 1] = c[i];
			i++;
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	string str;
	vector<pair<int, int>> pairs;

	str = "abcd";
	pairs.push_back(make_pair(1, 4));
	pairs.push_back(make_pair(3, 4));

	cout << str << ", " << swapLexOrder(str, pairs) << "\n";


	str = "acxrabdz";
	pairs.push_back(make_pair(1, 3));
	pairs.push_back(make_pair(6, 8));
	pairs.push_back(make_pair(3, 8));
	pairs.push_back(make_pair(2, 7));

	cout << str << ", " << swapLexOrder(str, pairs) << "\n";

	return 0;
}
