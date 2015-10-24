// http://careercup.com/question?id=6273553081040896

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int distanceTwoWordsInString(string str, string wordA, string wordB) {
	vector<int> positionA;
	vector<int> positionB;
	string sub;
	int i, start, wordIndex, indexA, indexB, distance;

	i = 0;
	start = 0;
	wordIndex = 0;
	while (i <= str.size()) {
		if (i == str.size() || str[i] == ' ') {
			sub = str.substr(start, i - start);
			start = i + 1;
			if (sub.compare(wordA) == 0) positionA.push_back(wordIndex);
			if (sub.compare(wordB) == 0) positionB.push_back(wordIndex);
			wordIndex++;
			if (i == str.size()) break;
		}
		i++;
	}
	
	if (positionA.size() == 0 || positionB.size() == 0) return -1;

	indexA = 0;
	indexB = 0;
	distance = wordIndex;
	while (indexA < positionA.size() && indexB < positionB.size()) {
		if (positionA[indexA] > positionB[indexB]) {
			distance = min(distance, positionA[indexA] - positionB[indexB]);
			indexB++;
		} else if (positionA[indexA] < positionB[indexB]) {
			distance = min(distance, positionB[indexB] - positionA[indexA]);
			indexA++;
		} else {
			indexA++;
		}
	}

	return distance;
}

int main(int argc, char* argv[]) {
	cout << distanceTwoWordsInString("the brown qucik frog quick the", "the", "quick") << "\n";
	cout << distanceTwoWordsInString("the quick the brown quick brown the frog", "the", "the") << "\n";

	return 0;
}
