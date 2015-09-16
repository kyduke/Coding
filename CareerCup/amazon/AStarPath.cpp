// http://www.careercup.com/question?id=5125942617833472

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int cityBlockDistance(pair<int, int> a, pair<int, int> b) {
	int x, y;

	x = a.first - b.first;
	if (x < 0) x = -x;
	y = a.second - b.second;
	if (y < 0) y = -y;

	return x + y;
}

vector<pair<int, int>> findPathAStar(vector<vector<int>> original, pair<int, int> start, pair<int, int> end) {
	vector<vector<int>> matrix;
	vector<pair<int, int>> path;
	multimap<int, pair<pair<int, int>, vector<pair<int, int>>>> candidate;
	multimap<int, pair<pair<int, int>, vector<pair<int, int>>>>::iterator it;
	pair<int, int> p;
	int x, y, w, h;

	matrix = original;

	matrix[start.second][start.first] = 0;
	path.push_back(start);
	candidate.insert(make_pair(cityBlockDistance(start, end), make_pair(start, path)));
	
	h = matrix.size() - 1;
	w = matrix[0].size() - 1;
	while (candidate.size()) {
		it = candidate.begin();
		p = it->second.first;
		x = p.first;
		y = p.second;

		if (x == end.first && y == end.second) {
			return it->second.second;
		}

		if (x > 0 && matrix[y][x - 1] == 1) {
			p = make_pair(x - 1, y);
			matrix[y][x - 1] = 0;
			path = it->second.second;
			path.push_back(p);
			candidate.insert(make_pair(cityBlockDistance(p, end), make_pair(p, path)));
		}
		if (x < w && matrix[y][x + 1] == 1) {
			p = make_pair(x + 1, y);
			matrix[y][x + 1] = 0;
			path = it->second.second;
			path.push_back(p);
			candidate.insert(make_pair(cityBlockDistance(p, end), make_pair(p, path)));
		}
		if (y > 0 && matrix[y - 1][x] == 1) {
			p = make_pair(x, y - 1);
			matrix[y - 1][x] = 0;
			path = it->second.second;
			path.push_back(p);
			candidate.insert(make_pair(cityBlockDistance(p, end), make_pair(p, path)));
		}
		if (y < h && matrix[y + 1][x] == 1) {
			p = make_pair(x, y + 1);
			matrix[y + 1][x] = 0;
			path = it->second.second;
			path.push_back(p);
			candidate.insert(make_pair(cityBlockDistance(p, end), make_pair(p, path)));
		}
		candidate.erase(it);
	}

	path.clear();
	return path;
}

int main(int argc, char* argv[]) {
	int data[10][10] = {
		{0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 1, 1, 1},
		{0, 0, 1, 1, 1, 0, 0, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{0, 1, 1, 1, 0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	vector<pair<int, int>> path;
	vector<vector<int>> matrix;
	vector<int> row;
	int i;

	for (i = 0; i < 10; i++) {
		row.clear();
		row.assign(data[i], data[i] + 10);
		matrix.push_back(row);
	}

	path = findPathAStar(matrix, make_pair(1, 1), make_pair(8, 8));
	for (i = 0; i < path.size(); i++) {
		cout << path[i].first << ", " << path[i].second << "\n";
	}

	return 0;
}
