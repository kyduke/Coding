// http://www.careercup.com/question?id=5956505037701120

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> dic;

void initDic() {
	dic.push_back("all");
	dic.push_back("about");
	dic.push_back("coding");
}

bool checkString(string str) {
	int i;
	
	cout << str << "\n";
	
	for (i = 0; i < dic.size(); i++) {
		if (dic[i].compare(str) == 0) return true;
	}
	
	return false;
}

string findLongestLegalWord(string str) {
	int i, j;
	
	for (i = 0; i < str.size() - 1; i++) {
		for (j = 0; j <= i; j++) {
			if (checkString(str.substr(j, str.size() - i)) == true) return str.substr(j, str.size() - i);
		}
	}
	
	return "";
}

int main(int argc, char* argv[]) {
	initDic();
	
	cout << findLongestLegalWord("allaboutcoding") << "\n";
	
	return 0;
}
