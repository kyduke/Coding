// https://codeforces.com/contest/1027/problem/A

#include <iostream>

using namespace std;

const int SIZE = 1001;
char buffer[SIZE];

int main(int argc, char** argv) {
	int t, n, i, j;
	bool flag;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%s", buffer);
		flag = true;
		i = 0;
		j = n - 1;
		while (i < j) {
			if (buffer[i] == buffer[j] || buffer[i] + 2 == buffer[j] || buffer[i] - 2 == buffer[j]) {
				i++;
				j--;
				continue;
			}
			flag = false;
			break;
		}
		
		if (flag == true) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	
	return 0;
}

/*
5
6
abccba
2
cf
4
adfa
8
abaazaba
2
ml
=====
YES
NO
YES
NO
NO
*/
