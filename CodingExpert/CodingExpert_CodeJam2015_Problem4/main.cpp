//LGE CodeJam 2015 Problem4
//라지는 시간초과

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

map<int, set<int>> rooms;
int N, K;
int minDist, midRoom;

void findRoom(vector<int>& route, int target) {
	int last;
	map<int, set<int>>::iterator it;
	set<int>::iterator friendsIt;
	vector<int>::iterator routeIt;

	last = route[route.size() - 1];

	if (route.size() >= minDist) {
		return;
	}

	if (last == target) {
		minDist = route.size();
		midRoom = route[(minDist - 1) / 2];
		return;
	}

	it = rooms.find(last);
	if (it == rooms.end()) return;

	for (friendsIt = it->second.begin(); friendsIt != it->second.end(); friendsIt++) {
		routeIt = find(route.begin(), route.end(), *friendsIt);
		if (routeIt != route.end()) continue;

		route.push_back(*friendsIt);
		findRoom(route, target);
		route.pop_back();
	}
}

void solve(int a, int b) {
	vector<int> route;

	minDist = 500001;

	route.push_back(a);
	findRoom(route, b);
}

int main(int argc, char* argv[]) {
	ifstream dataFile;
	int T;
	int n;
	int a, b;
	map<int, set<int>>::iterator it;
	set<int> friends;

	if (argc > 1) {
		dataFile.open(argv[1]);
		dataFile >> T;
		while (T--) {
			dataFile >> N >> K;

			rooms.clear();
			n = N - 1;
			while (n--) {
				dataFile >> a >> b;

				it = rooms.find(a);
				if (it == rooms.end()) {
					friends.clear();
					friends.insert(b);
					rooms.insert(make_pair(a, friends));
				} else {
					it->second.insert(b);
				}

				it = rooms.find(b);
				if (it == rooms.end()) {
					friends.clear();
					friends.insert(a);
					rooms.insert(make_pair(b, friends));
				} else {
					it->second.insert(a);
				}
			}
			n = K;
			while (n--) {
				dataFile >> a >> b;
				solve(a, b);
				cout << midRoom << "\n";
			}
		}
		dataFile.close();
	} else {
		cin >> T;
		while (T--) {
			cin >> N >> K;

			rooms.clear();
			n = N - 1;
			while (n--) {
				cin >> a >> b;

				it = rooms.find(a);
				if (it == rooms.end()) {
					friends.clear();
					friends.insert(b);
					rooms.insert(make_pair(a, friends));
				} else {
					it->second.insert(b);
				}

				it = rooms.find(b);
				if (it == rooms.end()) {
					friends.clear();
					friends.insert(a);
					rooms.insert(make_pair(b, friends));
				} else {
					it->second.insert(a);
				}
			}
			n = K;
			while (n--) {
				cin >> a >> b;
				solve(a, b);
				cout << midRoom << "\n";
			}
		}
	}

	return 0;
}

/*
2
6 2
1 3
2 3
3 4
3 5
5 6
1 4
2 6
8 2
1 3
2 3
3 4
3 5
5 6
6 7
7 8
1 3
5 8
=====
3
3
1
6
*/