#include <iostream>
#include <string>

typedef unsigned long long UINT64;

using namespace std;

int main(int argc, char* argv[]) {
	string a, s;
	int alphabets[256];
	UINT64 positions[10];
	int i, k;
	UINT64 answer;

	cin >> a >> s;

	answer = 0;

	for (i = 0; i < a.size(); i++) {
		alphabets[ a[i] ] = i;
	}

	k = 1;
	for (i = 0; i < s.size(); i++) {
		positions[i] = k;
		answer += k;
		k *= a.size();
	}

	for (i = 0; i < s.size(); i++) {
		answer += alphabets[ s[i] ] * positions[s.size() - i - 1];
	}

	cout << answer << "\n";

	return 0;
}

/*
Lexica
For this problem, you will write a program that reads in two strings, one representing an alphabet, and the other representing a valid word over the alphabet. After the input is parsed, output the position of the string over the alphabet in lexicographic order.

More explanation is given in the sample input and outputs.

Input Format
The first line of each data set contains a string A (1 ≤ A.length ≤ 12), representing an alphabet. The second line in the dataset contains a word S (1 ≤ S.length ≤ 10), representing a valid string over the alphabet.

Output Format
Output to STDIN a single integer representing the lexicographic position of the given word over the given alphabet.

Sample Input
01
110

Sample Output
13

Explanation
Lexicographical ordering of a set of words can be described as sort by length preceeded by alphabetical ordering. This means all words of length 0 will be preceding all words of length 1.

In the sample input, the given alphabet is 01 . The given alphabet of length consists of symbols 0 and 1. This means 0 is "alphabetically" smaller than 1 . Alphabets will not have repeated symbols.

Words over this alphabet can only contain the symbols in the alphabet.

Words over this lexicographic order with its position are as follows:
1: 0
2: 1
3: 00
4: 01
5: 10
6: 11
7: 000
8: 001
9: 010
10: 011
11: 100
12: 101
13: 110
14: 111
15: 0000

As you can see, the given word, 110 , is the 13th word in lexicographical order. Therefore, the output reads 13 .
Hints: If you brute force this problem, your program will time out. Consider the problem mathematically; scratch paper is recommended. If you need any clarifications, ask Tim for help.
*/
