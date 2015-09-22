// http://www.careercup.com/question?id=5093738684612608

#include <iostream>
#include <map>

using namespace std;

int findBusyHour(int log[][3], int n) {
	multimap<int, int> nodes;
	multimap<int, int>::iterator it;
	int i, maxHour, maxMemory, hour, memory, released;

	i = 0;
	while (i < n) {
		nodes.insert(make_pair(log[i][0], log[i][2]));
		nodes.insert(make_pair(log[i][1], -log[i][2]));
		i++;
	}

	maxHour = -1;
	maxMemory = 0;
	hour = -1;
	memory = 0;
	released = 0;

	it = nodes.begin();
	while (it != nodes.end()) {
		if (hour != it->first) {
			hour = it->first;
			memory += released;
			released = 0;
		}
		if (it->second > 0) {
			memory += it->second;
			if (memory > maxMemory) {
				maxHour = hour;
				maxMemory = memory;
			}
		} else {
			released += it->second;
		}
		it++;
	}

	return maxHour;
}

int main(int argc, char* argv[]) {
	int log[][3] = {
		{100207, 100208, 2},
		{100305, 100307, 5},
		{100207, 100209, 4},
		{111515, 121212, 1}
	};

	cout << findBusyHour(log, 4) << "\n";

	return 0;
}

/*
100207 100208 2
100305 100307 5
100207 100209 4
111515 121212 1
=====
100207
*/
