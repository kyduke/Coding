// http://careercup.com/question?id=5714443633688576

#include <iostream>
#include <queue>
#include <string>

using namespace std;

void printCombination(vector<char> arr) {
	queue< pair<string, int> > q;
	string str;
	int i;

	str = "";
	for (i = 0; i < arr.size(); i++) {
		q.push(make_pair(str + arr[i], i));
	}

	while (q.size()) {
		str = q.front().first;
		i = q.front().second + 1;
		q.pop();
		for (; i < arr.size(); i++) {
			q.push(make_pair(str + arr[i], i));
		}
		cout << str;
		if (q.size()) cout << ",";
	}
	cout << "\n";
}

int main(int argc, char* argv[]) {
	vector<char> arr;

	arr.push_back('A');
	arr.push_back('B');
	arr.push_back('C');
	arr.push_back('D');

	printCombination(arr);

	return 0;
}
