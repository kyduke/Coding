// http://www.careercup.com/question?id=4855286160424960

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findMinimumConsecutiveSubString(string s, string t) {
	vector<int> idx;
	int cnt, minLength, start, end, from, to, i, j, k;
	
	cnt = t.size();
	idx.assign(cnt, -1);
	
	minLength = s.size();
	
	for (i = 0; i < s.size(); i++) {
		for (j = 0; j < t.size(); j++) {
			if (s[i] == t[j]) {
				if (idx[j] == -1) cnt--;
				idx[j] = i;
				if (cnt == 0) {
					from = idx[0];
					to = idx[0];
					for (k = 1; k < idx.size(); k++) {
						from = min(from, idx[k]);
						to = max(to, idx[k]);
					}
					if (minLength > to - from + 1) {
						minLength = to - from + 1;
						start = from;
						end = to;
					}
				}
				break;
			}
		}
	}
	
	if (cnt != 0) return "";
	
	return s.substr(start, end - start + 1);
}

int main(int argc, char* argv[]) {
	cout << findMinimumConsecutiveSubString("adobecodebanc", "abc") << "\n";
	
	return 0;
}
