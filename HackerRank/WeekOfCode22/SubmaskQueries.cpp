// https://www.hackerrank.com/contests/w22/challenges/submask-queries-

#include <iostream>
#include <string>

using namespace std;

const unsigned int SIZE = 100001;

int cmd[SIZE];
unsigned int arr[SIZE] = {0, };
unsigned int bits[SIZE] = {0, };
string str;
int n, k;
unsigned x;

unsigned int stringToInteger() {
	int i, a;

	a = 0;
	if (str[0] == '1') a = 1;
	for (i = 1; i < n; i++) {
		if (str[i] == '1') a += (1 << i);
	}

	return a;
}

unsigned int solve(unsigned int a) {
	unsigned int answer;
	int i;

	answer = 0;

	for (i = k - 1; i >= 0; i--) {
		if (cmd[i] == 3) continue;
		if ((bits[i] & a) == a) {
			answer ^= arr[i];
			if (cmd[i] == 1) break;
		}
	}

	return answer;
}

int main() {
    int m, c;
    
    cin >> n >> m;
    
	k = 0;
    while (k < m) {
        cin >> c;
		cmd[k] = c;
        if (c == 1) {
            cin >> x >> str;
			arr[k] = x;
			bits[k] = stringToInteger();
        } else if (c == 2) {
            cin >> x >> str;
			arr[k] = x;
			bits[k] = stringToInteger();
        } else {
            cin >> str;
			cout << solve(stringToInteger()) << "\n";
        }
		k++;
    }
    
    return 0;
}
