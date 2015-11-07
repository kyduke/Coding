// http://www.careercup.com/question?id=5651322294501376

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void matchStringWithStream(vector<string>& list, string str) {
	vector<string> candidates;
	vector<string> temp;
	vector<string>::iterator it;
	int i, j, k, l;
	bool match;
	
	for (i = 0; i < str.size(); i++) {
		temp = candidates;
		temp.push_back("");
		candidates.clear();
		for (j = 0; j < temp.size(); j++) {
			for (k = 0; k < list.size(); k++) {
				if (list[k].size() <= temp[j].size()) continue;
				match = true;
				for (l = 0; l < temp[j].size(); l++) {
					if (list[k][l] != temp[j][l]) {
						match = false;
						break;
					}
				}
				if (match == true && list[k][l] == str[i]) {
					it = find(candidates.begin(), candidates.end(), temp[j] + str[i]);
					if (it == candidates.end()) candidates.push_back(temp[j] + str[i]);
					if (list[k].size() == temp[j].size() + 1) cout << list[k] << "\n";
				}
			}
		}
	}
}

int main(int argc, char* argv[]) {
	vector<string> list;
	list.push_back("ok");
	list.push_back("test");
	list.push_back("one");
	list.push_back("try");
	list.push_back("trying");
	
	matchStringWithStream(list, "abcokdeftrying");

	return 0;
}
