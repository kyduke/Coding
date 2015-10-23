// http://careercup.com/question?id=5080100049518592

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef unsigned long long UINT64;

const UINT64 MAX_DISTANCE = 18446744073709551615;

struct Point {
	int x;
	int y;
	Point(int coordX, int coordY) {
		x = coordX;
		y = coordY;
	}
	bool operator<(const Point& a) const {
		return x < a.x;
	}
};

struct ConsumerData {
	int index;
	int left;
	int right;
	ConsumerData(int i, int l, int r) {
		index = i;
		left = l;
		right = r;
	}
};

int findNearestProducer(vector<Point>& producers, int consumer, int startIndex, int endIndex) {
	int nearestIndex, i;
	UINT64 minDistance, currDistance;

	nearestIndex = 0;
	minDistance = MAX_DISTANCE;
	for (i = startIndex; i <= endIndex; i++) {
		currDistance = (producers[i].x - consumer) * (producers[i].x - consumer) + producers[i].y * producers[i].y;
		if (currDistance < minDistance) {
			minDistance = currDistance;
			nearestIndex = i;
		}
	}

	return nearestIndex;
}

vector<Point> findNearestProducers(vector<Point>& producers, vector<int>& consumers) {
	vector<Point> nearestProducers;
	vector<int> nearestIndex;
	queue<ConsumerData> q;
	int i, index;

	if (producers.size() == 0 || consumers.size() == 0) return nearestProducers;

	sort(producers.begin(), producers.end());
	sort(consumers.begin(), consumers.end());

	nearestProducers.assign(consumers.size(), Point(0, 0));
	nearestIndex.assign(consumers.size(), -1);

	i = 0;
	index = findNearestProducer(producers, consumers[i], 0, producers.size() - 1);
	nearestIndex[i] = index;
	nearestProducers[i] = producers[index];
	if (consumers.size() == 1) return nearestProducers;

	i = consumers.size() - 1;
	index = findNearestProducer(producers, consumers[i], nearestIndex[0], producers.size() - 1);
	nearestIndex[i] = index;
	nearestProducers[i] = producers[index];
	if (consumers.size() == 2) return nearestProducers;

	q.push(ConsumerData(i / 2, 0, i));
	while (!q.empty()) {
		ConsumerData c = q.front();
		q.pop();
		i = c.index;
		index = findNearestProducer(producers, consumers[i], nearestIndex[c.left], nearestIndex[c.right]);
		nearestIndex[i] = index;
		nearestProducers[i] = producers[index];

		if (c.left < i - 1) {
			q.push(ConsumerData((i + c.left) / 2, c.left, i));
		}

		if (c.right > i + 1) {
			q.push(ConsumerData((i + c.right) / 2, i, c.right));
		}
	}

	return nearestProducers;
}

int main(int argc, char* argv[]) {
	vector<Point> producers;
	vector<int> consumers;
	vector<Point> nearestProducers;
	int i;
	
	producers.push_back(Point(0, 3));
	producers.push_back(Point(1, 1));
	producers.push_back(Point(3, 2));
	producers.push_back(Point(8, 10));
	producers.push_back(Point(9, 100));

	consumers.push_back(1);
	consumers.push_back(5);
	consumers.push_back(7);

	nearestProducers = findNearestProducers(producers, consumers);

	for (i = 0; i < nearestProducers.size(); i++) {
		cout << "(" << nearestProducers[i].x << ", " << nearestProducers[i].y << ")";
		if (i < nearestProducers.size() - 1) cout << ", ";
	}
	cout << "\n";

	producers.clear();
	consumers.clear();
	nearestProducers.clear();

	producers.push_back(Point(0, 1));
	producers.push_back(Point(1, 100));
	producers.push_back(Point(2, 100));
	producers.push_back(Point(3, 100));
	producers.push_back(Point(4, 100));
	producers.push_back(Point(5, 100));
	producers.push_back(Point(6, 100));
	producers.push_back(Point(7, 100));
	producers.push_back(Point(8, 100));
	producers.push_back(Point(9, 1));

	consumers.push_back(0);
	consumers.push_back(1);
	consumers.push_back(2);
	consumers.push_back(3);
	consumers.push_back(4);
	consumers.push_back(5);
	consumers.push_back(6);
	consumers.push_back(7);
	consumers.push_back(8);
	consumers.push_back(9);

	nearestProducers = findNearestProducers(producers, consumers);

	for (i = 0; i < nearestProducers.size(); i++) {
		cout << "(" << nearestProducers[i].x << ", " << nearestProducers[i].y << ")";
		if (i < nearestProducers.size() - 1) cout << ", ";
	}
	cout << "\n";

	producers.clear();
	consumers.clear();
	nearestProducers.clear();

	return 0;
}
