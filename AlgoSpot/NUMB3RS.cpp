//https://algospot.com/judge/problem/submit/NUMB3RS

#include <iostream>

using namespace std;

int N, D, P;
int connected[51][51];
int deg[51];
double probabilities[51][2];

void solve() {
	int i, j, k, d, day, today, yesterday;

	day = 0;
	today = 0;
	yesterday = 1;

	while (day < D) {
		today = day % 2;
		yesterday = (day + 1) % 2;

		//clean up today's probabilities
		for (i = 0; i < N; i++) {
			probabilities[i][today] = 0.0;
		}

		//update probabilities
		for (i = 0; i < N; i++) {
			if (probabilities[i][yesterday] == 0) continue;
			d = deg[i];
			for (j = 0; j < d; j++) {
				k = connected[i][j]; //연결된 마을 번호가 저장되어 있음
				probabilities[k][today] += probabilities[i][yesterday] / d;
			}
		}

		day++;
	}
}

int main(int argc, char *argv[]) {
	int C, T, i, j, k;
	int targets[51];
	
	cin >> C;
	while (C--) {
		cin >> N >> D >> P;
		i = 0;
		while (i < N) {
			j = 0;
			k = 0;
			deg[i] = 0;
			while (j < N) {
				cin >> T;
				if (T) {
					connected[i][k] = j; //0 1 0을 저장하지 않고, 2, 3과 같이 연결된 마을의 번호를 저장하여 반복 줄임
					deg[i]++;
					k++;
				}
				j++;
			}
			probabilities[i][0] = 0.0;
			probabilities[i][1] = 0.0;
			i++;
		}

		probabilities[P][1] = 1.0;

		cin >> T;
		i = 0;
		while (i < T) {
			cin >> j;
			targets[i] = j;
			i++;
		}

		solve();

		//print results
		k = (D + 1) % 2;
		for (i = 0; i < T; i++) {
			j = targets[i];
			printf("%.8f ", probabilities[j][k]);
		}
		cout << "\n";
	}

	return 0;
}

/*
2
5 2 0
0 1 1 1 0
1 0 0 0 1
1 0 0 0 0
1 0 0 0 0
0 1 0 0 0
3
0 2 4
8 2 3
0 1 1 1 0 0 0 0
1 0 0 1 0 0 0 0
1 0 0 1 0 0 0 0
1 1 1 0 1 1 0 0
0 0 0 1 0 0 1 1
0 0 0 1 0 0 0 1
0 0 0 0 1 0 0 0
0 0 0 0 1 1 0 0
4
3 1 2 6
=====
0.83333333 0.00000000 0.16666667
0.43333333 0.06666667 0.06666667 0.06666667
*/
