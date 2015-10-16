// https://algospot.com/judge/problem/read/DARPA

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

const int SIZE = 200;

double positions[SIZE];
int N, M;

double solve() {
	set<double> gapSet;
	set<double>::iterator it;
	vector<double> gaps;
	double dist;
	int i, j, left, right, mid, count;

	for (i = 0; i < M; i++) {
		for (j = i + 1; j < M; j++) {
			gapSet.insert(positions[j] - positions[i]);
		}
	}

	for (it = gapSet.begin(); it != gapSet.end(); it++) {
		gaps.push_back(*it);
	}
	gapSet.clear();

	left = 0;
	right = gaps.size() - 1;
	
	dist = 0.0;
	while (left < right) {
		mid = (right - left) / 2 + left;
		if (mid == left) mid++;
		dist = gaps[mid];
		count = 1;
		j = 0;
		for (i = 1; i < M; i++) {
			if (positions[i] - positions[j] >= dist) {
				j = i;
				count++;
			}
		}
		if (count >= N) {
			left = mid;
		} else {
			if (right == mid) {
				right = left;
			} else {
				right = mid;
			}
		}
	}
	dist = gaps[left];
	gaps.clear();

	return dist;
}

int main(int argc, char* argv[]) {
	int C, i;

	cin >> C;
	while (C--) {
		cin >> N >> M;
		i = 0;
		while (i < M) {
			cin >> positions[i];
			i++;
		}
		
		printf("%.2f\n", solve());
	}
	return 0;
}

/*
3
2 4 
80 100 120 140 
4 4 
80 100 120 140
4 7 
0 70 90 120 200 210 220 
=====
60.00
20.00
50.00
*/
