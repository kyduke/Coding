#include <iostream>

using namespace std;

const int SIZE = 1000002;

char str[SIZE];

int main(int argc, char* argv[]) {
	int i, j, k, len, ans;

	scanf("%s", &str);

	ans = 0;
	k = 0;
	len = strlen(str);
	while (k < len) {
		j = k;
		for (i = 0; i < j; i++) {
			if (str[i] == str[k]) {
				k++;
				if (k == len) break;
			}
		}
		ans++;
		if (j == k) k++;
	}

	printf("%d\n", ans);

	return 0;
}
