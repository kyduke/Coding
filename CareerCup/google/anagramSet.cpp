// http://www.careercup.com/question?id=5639359996887040

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int countOfAnagram(vector<string>& list) {
	set<string> anagrams;
	int i;

	for (i = 0; i < list.size(); i++) {
		sort(list[i].begin(), list[i].end());
		anagrams.insert(list[i]);
	}

	return anagrams.size();
}

int main(int argc, char* argv[]) {
	vector<string> list;

	list.push_back("abc");
	list.push_back("cab");
	list.push_back("dac");
	list.push_back("beed");
	list.push_back("deb");
	list.push_back("few");
	list.push_back("acd");

	cout << countOfAnagram(list) << "\n";

	return 0;
}

/*
{"abc", "cab", "dac", "beed", "deb", "few", "acd"}
=====
5
*/
