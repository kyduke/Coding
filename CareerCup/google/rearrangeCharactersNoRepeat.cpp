// http://careercup.com/question?id=5693863291256832

#include <iostream>
#include <map>
#include <string>

using namespace std;

string rearrange(string str) {
	string result, last, temp;
	map<string, int> counts;
	map<string, int>::iterator it;
	multimap<int, string> remains;
	multimap<int, string>::reverse_iterator rit;
	int i;

	for (i = 0; i < str.size(); i++) {
		temp = str.substr(i, 1);
		it = counts.find(temp);
		if (it != counts.end()) {
			it->second++;
		} else {
			counts.insert(make_pair(temp, 1));
		}
	}

	for (it = counts.begin(); it != counts.end(); it++) {
		remains.insert(make_pair(it->second, it->first));
	}
	counts.clear();

	result = "";
	if (remains.size() > 0) {
		rit = remains.rbegin();
		if (rit->first * 2 - 2 >= str.size()) return "No valid output";
		last = "";
		while (remains.size()) {
			rit = remains.rbegin();
			if (last.compare(rit->second) == 0) rit++;
			i = rit->first;
			last = rit->second;
			result.append(last);
			if (i > 1) remains.insert(make_pair(i - 1, last));
			remains.erase(next(rit).base());
		}
	}

	return result;
}

int main(int argc, char* argv[]) {
	cout << rearrange("aaabc") << "\n";
	cout << rearrange("aa") << "\n";
	cout << rearrange("aaaabc") << "\n";
	cout << rearrange("aaaaabbbcc") << "\n";
	cout << rearrange("aaaaaaabcdefg") << "\n";

	return 0;
}
