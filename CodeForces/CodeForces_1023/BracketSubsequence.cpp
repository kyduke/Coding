// http://codeforces.com/contest/1023/problem/C

#include <iostream>
#include <queue>

using namespace std;

const int SIZE = 200002;

char str[SIZE];
int closeIndex[SIZE] = {0, };

int main(int argc, char** argv) {
	queue<int> q;
	int n, k, i;
	
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	
	for (i = 0; i < n; i++) {
		if (str[i] == '(') {
			q.push(i);
		} else {
			closeIndex[q.front()] = i;
			q.pop();
		}
	}
	
	i = 0;
	while (k < n) {
		while (str[i] != '(') {
			i++;
		}
		str[i] = '*';
		str[ closeIndex[i] ] = '*';
		k += 2;
	}
	
	for (i = 0; i < n; i++) {
		if (str[i] != '*') {
			printf("%c", str[i]);
		}
	}
	
	return 0;
}

/*
6 4
()(())
=====
()()

8 8
(()(()))
=====
(()(()))
*/
