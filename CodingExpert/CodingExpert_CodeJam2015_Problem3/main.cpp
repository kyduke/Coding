//LGE CodeJam 2015 Problem3
//brute force ½º¸ô¸¸ Åë°ú

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N;
map<int, set<int>> pairs;

int getPairDistance(vector<int>& line) {
	int dist, currentDist;
	int i;
	map<int, set<int>>::iterator it;
	set<int>::iterator friendsIt;
	vector<int>::iterator lineIt;

	dist = 0;

	for (lineIt = line.begin(); lineIt != line.end(); lineIt++) {
		it = pairs.find(*lineIt);
		if (it == pairs.end()) continue;

		for (friendsIt = it->second.begin(); friendsIt != it->second.end(); friendsIt++) {
			currentDist = distance(lineIt, find(line.begin(), line.end(), *friendsIt));
			if (currentDist <= 0) continue;
			dist += currentDist;
		}
	}

	return dist;
}

int getPairCount(vector<int>& line, int n) {
	int count;
	map<int, set<int>>::iterator it;
	set<int>::iterator friendsIt;

	it = pairs.find(n);
	if (it == pairs.end()) return 0;

	count = 0;

	for (friendsIt = it->second.begin(); friendsIt != it->second.end(); friendsIt++) {
		if (find(line.begin(), line.end(), *friendsIt) != line.end()) count++;
	}

	return count;
}

int bruteForceMakeLine(int beginIndex, int endIndex, vector<int>& line, vector<int>& newLine) {
	if (newLine.size() == N) return getPairDistance(newLine);

	int useBegin, useEnd;

	newLine.push_back(line[beginIndex]);
	useBegin = bruteForceMakeLine(beginIndex + 1, endIndex, line, newLine);
	newLine.pop_back();
	
	newLine.push_back(line[endIndex]);
	useEnd = bruteForceMakeLine(beginIndex, endIndex - 1, line, newLine);
	newLine.pop_back();

	return min(useBegin, useEnd);
}

int bruteforce() {
	vector<int> line, newLine;
	int i;

	for (i = 1; i <= N; i++) line.push_back(i);

	return bruteForceMakeLine(0, N-1, line, newLine);
}

int makeLine(int beginIndex, int endIndex, vector<int>& line, vector<int>& newLine) {
	if (newLine.size() == N) return getPairDistance(newLine);

	int useBegin, useEnd;
	int i, j;

	i = 0;
	while (beginIndex + i <= endIndex - i) {
		useBegin = getPairCount(newLine, line[beginIndex + i]);
		useEnd = getPairCount(newLine, line[endIndex - i]);

		if (useBegin > useEnd) {
			j = 0;
			while (j <= i) {
				newLine.push_back(line[beginIndex + j]);
				j++;
			}
			useBegin = makeLine(beginIndex + i + 1, endIndex, line, newLine);
			while (j--) {
				newLine.pop_back();
			}

			return useBegin;
		} else if (useBegin < useEnd) {
			j = 0;
			while (j <= i) {
				newLine.push_back(line[endIndex - j]);
				j++;
			}
			useEnd = makeLine(beginIndex, endIndex - i - 1, line, newLine);
			while (j--) {
				newLine.pop_back();
			}

			return useEnd;
		}

		i++;
	}

	newLine.push_back(line[beginIndex]);
	useBegin = makeLine(beginIndex + 1, endIndex, line, newLine);
	newLine.pop_back();
	
	newLine.push_back(line[endIndex]);
	useEnd = makeLine(beginIndex, endIndex - 1, line, newLine);
	newLine.pop_back();

	return min(useBegin, useEnd);
}

int solve() {
	vector<int> line, newLine;
	int i;

	for (i = 1; i <= N; i++) line.push_back(i);

	return makeLine(0, N-1, line, newLine);
}

int main(int argc, char* argv[]) {
	ifstream dataFile;
	int T, M;
	int a, b;
	map<int, set<int>>::iterator it;
	set<int> friends;

	if (argc > 1) {
		dataFile.open(argv[1]);
		dataFile >> T;
		while (T--) {
			dataFile >> N >> M;

			pairs.clear();
			while (M--) {
				dataFile >> a >> b;

				it = pairs.find(a);
				if (it == pairs.end()) {
					friends.clear();
					friends.insert(b);
					pairs.insert(make_pair(a, friends));
				} else {
					it->second.insert(b);
				}

				it = pairs.find(b);
				if (it == pairs.end()) {
					friends.clear();
					friends.insert(a);
					pairs.insert(make_pair(b, friends));
				} else {
					it->second.insert(a);
				}
			}
			//cout << bruteforce() << "\n";
			cout << solve() << "\n";
		}
		dataFile.close();
	} else {
		cin >> T;
		while (T--) {
			cin >> N >> M;

			pairs.clear();
			while (M--) {
				cin >> a >> b;

				it = pairs.find(a);
				if (it == pairs.end()) {
					friends.clear();
					friends.insert(b);
					pairs.insert(make_pair(a, friends));
				} else {
					it->second.insert(b);
				}

				it = pairs.find(b);
				if (it == pairs.end()) {
					friends.clear();
					friends.insert(a);
					pairs.insert(make_pair(b, friends));
				} else {
					it->second.insert(a);
				}
			}
			cout << bruteforce() << "\n";
			cout << solve() << "\n";
		}
	}

	return 0;
}

/*
4
8 7
1 2
3 2
3 4
4 5
7 2
1 8
1 7

4 4
1 2
2 4
1 4
3 4

9 16
7 9
6 7
2 9
2 6
2 4
4 5
4 6
5 9
1 5
2 8
1 9
1 8
3 8
7 8
5 7
5 6

10 7
5 9
3 4
4 6
3 6
9 10
2 7
3 8
=====
8
5
41
16
*/