// http://codeforces.com/problemset/problem/547/B

#include <iostream>
#include <stack>

using namespace std;

const int MAX = 200002;

int answer[MAX], leftMinIndex[MAX], rightMinIndex[MAX], bears[MAX];
stack<int> s;
 
int main()
{
	int n, i, length;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> bears[i];
	}

	for (i = 0; i < n; i++) {
		while (!s.empty() && bears[s.top()] >= bears[i]) {
			s.pop();
		}
		if (!s.empty()) {
			leftMinIndex[i] = s.top();
		} else {
			leftMinIndex[i] = -1;
		}
		s.push(i);
	}
	leftMinIndex[n] = -1;

    while (!s.empty()) s.pop();

    for (i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && bears[s.top()] >= bears[i]) {
			s.pop();
		}
        if (!s.empty()) {
			rightMinIndex[i] = s.top();
		} else {
			rightMinIndex[i] = n;
		}
        s.push(i);
    }
	rightMinIndex[n] = n;

    for (i = 0; i < n; i++)
    {
        length = rightMinIndex[i] - leftMinIndex[i] - 1;
        answer[length] = max(answer[length], bears[i]);
    }
    for (i = n; i > 0; i--) {
		answer[i] = max(answer[i], answer[i + 1]);
	}

    for (i = 1; i <= n; i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";

    return 0;
}

/*
10
1 2 3 4 5 4 3 2 1 6
=====
6 4 4 3 3 2 2 1 1 1
*/
