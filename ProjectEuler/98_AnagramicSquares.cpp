// https://projecteuler.net/problem=98

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

set<string> words;
map<string, vector<string>> anagrams;
set<int> squares;

void parseNumbersAndCheckOthers(string key, string str, int n) {
	map<string, vector<string>>::iterator it;
	int alphabets[26] = {0, };
	int i, j, m;

	i = str.size() - 1;
	m = n;
	while (i >= 0) {
		alphabets[ str[i] - 'A' ] = m % 10;
		i--;
		m /= 10;
	}

	it = anagrams.find(key);
	for (i = 1; i < it->second.size(); i++) {
		m = 0;
		for (j = 0; j < key.size(); j++) {
			m = m * 10 + alphabets[ it->second[i][j] - 'A' ];
		}
		j = sqrt((double)m);
		if (j * j == m) {
			cout << str << ", " << it->second[i] << "\n";
			squares.insert(n);
			squares.insert(m);
		}
	}
}

void fillNumbers(string key, string str, int n, int visit, int step) {
	int i;

	if (step > key.size()) {
		i = sqrt((double)n);
		if (i * i == n) parseNumbersAndCheckOthers(key, str, n);
		return;
	}

	for (i = 1; i < 10; i++) {
		if (visit & (1 << i)) continue;
		fillNumbers(key, str, n * 10 + i, visit | (1 << i), step + 1);
	}
}

//0~9 숫자를 하나씩 문자와 치환
//첫 숫자만 치환해서 제곱수가 나오면
//나머지 숫자들을 같은 숫자로 치환해서 제곱수가 나오는지 확인
//제곱수는 sqrt를 이용 sqrt 나온 정수를 제곱해서 원래 숫자인지 비교
void solve() {
	map<string, vector<string>>::iterator it;
	set<int>::iterator squaresIt;

	it = anagrams.begin();
	while (it != anagrams.end()) {
		//cout << it->first << ": " << it->second[0] << "\n";
		fillNumbers(it->first, it->second[0], 0, 0, 1);
		it++;
	}

	squaresIt = squares.begin();
	while (squaresIt != squares.end()) {
		cout << *squaresIt << " ";
		squaresIt++;
	}
	cout << "\n";

	cout << *squares.rbegin() << "\n";
}

int main(int argc, char* argv[]) {
	ifstream wordFile;
	char buffer[64];
	int length;
	string str, key;
	int isStart, i;
	map<string, vector<string>> temp;
	map<string, vector<string>>::iterator it;
	vector<string> values;

	wordFile.open("D:/workspace/Coding/ProjectEuler_98_AnagramicSquares/98_AnagramicSquares.txt");
	wordFile.seekg(0, wordFile.end);
	length = wordFile.tellg();
	wordFile.seekg(0, wordFile.beg);

	isStart = false;
	while (length > 0) {
		wordFile.read(buffer, 63);
		buffer[min(63, length)] = '\0';
		length -= 63;
		i = 0;
		while (buffer[i] != '\0') {
			if (buffer[i] == '"') {
				if (isStart == false) {
					isStart = true;
					str = "";
				} else {
					isStart = false;
					if (str.size() > 1) {
						words.insert(str);
						key = str;
						sort(key.begin(), key.end());
						it = temp.find(key);
						if (it == temp.end()) {
							values.clear();
							values.push_back(str);
							temp.insert(make_pair(key, values));
						} else {
							it->second.push_back(str);
						}
					}

				}
			} else if (buffer[i] != ',') {
				str += buffer[i];
			}
			i++;
		}
	}
	wordFile.close();

	//anagram 쌍이 존재하지 않는 혼자 있는 문자 제거
	it = temp.begin();
	while (it != temp.end()) {
		if (it->second.size() > 1) {
			anagrams.insert(*it);
		}
		it++;
	}
	temp.clear();

	//남은 문자들 출력
	/*
	it = anagrams.begin();
	while (it != anagrams.end()) {
		cout << it->first << "\n";
		it++;
	}
	*/

	//최대 9자리 문자만 남음

	solve();

	return 0;
}
