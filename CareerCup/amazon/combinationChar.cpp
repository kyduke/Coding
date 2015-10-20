// http://careercup.com/question?id=5714443633688576

#include <iostream>
#include <queue>
#include <string>

using namespace std;

void printCombination(vector<char> arr) {
	queue< pair<string, pair<vector<int>, int> > > q;
	string str;
	vector<int> visit;
	vector<string> result;
	int i;

	str = "";
	visit.assign(arr.size(), 0);
	for (i = 0; i < arr.size(); i++) {
		visit[i] = 1;
		q.push(make_pair(str + arr[i], make_pair(visit, i)));
		visit[i] = 0;
	}
	visit.clear();

	while (q.size()) {
		str = q.front().first;
		visit = q.front().second.first;
		i = q.front().second.second + 1;
		q.pop();
		result.push_back(str);
		for (; i < arr.size(); i++) {
			visit[i] = 1;
			q.push(make_pair(str + arr[i], make_pair(visit, i)));
			visit[i] = 0;
		}
	}

	for (i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i < result.size() - 1) cout << ",";
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
