// https://algospot.com/judge/problem/read/MEETING

#include <iostream>
#include <algorithm>

using namespace std;

int man[10000];
int woman[10000];

int main(int argc, char* argv[]) {
	int T, N, i, t;
	int result;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		i = 0;
		while (i < N) {
			scanf("%d", &man[i++]);
		}
		i = 0;
		while (i < N) {
			scanf("%d", &woman[i++]);
		}

		sort(man, man + N);
		sort(woman, woman + N);

		result = 0;
		for (i = 0; i < N; i++) {
			t = man[i] - woman[i];
			if (t < 0) t *= -1;
			result += t;
		}

		printf("%d\n", result);
	}

	return 0;
}

/*
2
4
1 2 3 4
8 6 7 5
3
-1 0 1
-1 -1 -1
=====
16
3
*/
