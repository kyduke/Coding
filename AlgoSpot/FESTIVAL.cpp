// https://algospot.com/judge/problem/read/FESTIVAL

#include <iostream>

using namespace std;

int cost[1000];
int sub[1000];

int main(int argc, char* argv[]) {
	int C, N, L;
	int i;
	int minCost, minMember;
	int tempCost;

	cin >> C;
	while (C--) {
		cin >> N >> L;
		i = 0;
		while (i < N) {
			cin >> cost[i];
			i++;
		}

		if (L == 1) {
			minCost = cost[0];
			i = 1;
			while (i < N) {
				minCost = min(minCost, cost[i]);
				i++;
			}
			minMember = L;
			printf("%.11f\n", (double)minCost / minMember);
		} else {
			sub[0] = 0;
			for (i = 0; i < L; i++) {
				sub[0] += cost[i];
			}
			minCost = sub[0];
			for (i = 1; i < N - L + 1; i++) {
				sub[i] = sub[i - 1] - cost[i - 1] + cost[i + L - 1];
				minCost = min(minCost, sub[i]);
			}
			minMember = L;

			while (L < N) {
				L++;
				sub[0] += cost[L - 1];
				tempCost = sub[0];
				for (i = 1; i < N - L + 1; i++) {
					sub[i] = sub[i - 1] - cost[i - 1] + cost[i + L - 1];
					tempCost = min(tempCost, sub[i]);
				}
				if (tempCost * minMember < minCost * L) {
					minCost = tempCost;
					minMember = L;
				}
			}
			printf("%.11f\n", (double)minCost / minMember);
		}
	}

	return 0;
}

/*
2
6 3
1 2 3 1 2 3 
6 2 
1 2 3 1 2 3
=====
1.75000000000
1.50000000000
*/
