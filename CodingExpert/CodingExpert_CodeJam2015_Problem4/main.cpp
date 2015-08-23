//LGE CodeJam 2015 Problem4
//라지는 시간초과

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Room {
	bool visit;
	set<int> friends;
};

Room rooms[500001];
int N, K;
int minDist, midRoom;

void findRoom(vector<int>& route, int target) {
	int last;
	set<int>::iterator it;

	last = route[route.size() - 1];

	if (route.size() >= minDist) {
		return;
	}

	if (last == target) {
		minDist = route.size();
		midRoom = route[(minDist - 1) / 2];
		return;
	}

	for (it = rooms[last].friends.begin(); it != rooms[last].friends.end(); it++) {
		if (rooms[*it].visit == true) continue;

		rooms[*it].visit = true;
		route.push_back(*it);
		findRoom(route, target);
		route.pop_back();
		rooms[*it].visit = false;
	}
}

void solve(int a, int b) {
	vector<int> route;

	minDist = 500001;

	rooms[a].visit = true;

	route.push_back(a);
	findRoom(route, b);
}

int main(int argc, char* argv[]) {
	ifstream dataFile;
	int T;
	int n;
	int a, b;

	if (argc > 1) {
		dataFile.open(argv[1]);
		dataFile >> T;
		while (T--) {
			dataFile >> N >> K;

			for (n = 0; n <= N; n++) {
				rooms[n].visit = false;
				rooms[n].friends.clear();
			}

			n = N - 1;
			while (n--) {
				dataFile >> a >> b;
				rooms[a].friends.insert(b);
				rooms[b].friends.insert(a);
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

			for (n = 0; n <= N; n++) {
				rooms[n].visit = false;
				rooms[n].friends.clear();
			}

			n = N - 1;
			while (n--) {
				cin >> a >> b;
				rooms[a].friends.insert(b);
				rooms[b].friends.insert(a);
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
