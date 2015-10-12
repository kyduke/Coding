// http://codeforces.com/contest/585/problem/A

#include <iostream>
#include <vector>

using namespace std;

typedef long long INT64;

const int SIZE = 4000;

INT64 data[SIZE][3];
int n;

void chainReaction(int k) {
	int i;

	if (data[k][1] == 0) return;

	for (i = k + 1; i < n; i++) {
		if (data[i][2] < 0) continue;
		data[i][2] -= data[k][1];
		if (data[i][2] < 0 && data[i][1] != 0) chainReaction(i);
	}
	data[k][1] = 0;
}

void solve() {
    vector<int> success;
    int i, j;
    INT64 cry;

    for (i = 0; i < n; i++) {
        if (data[i][2] >= 0) {
            success.push_back(i + 1);
        }
        if (data[i][2] >= 0) {
            cry = data[i][0];
            for (j = i + 1; j < n; j++) {
                if (data[j][2] < 0) continue;
                data[j][2] -= cry;
                cry--;
                if (cry <= 0) break;
            }
			for (j = i + 1; j < n; j++) {
                if (data[j][2] < 0) chainReaction(j);
            }
        } 
    }

    cout << success.size() << "\n";
    for (i = 0; i < success.size(); i++) {
        cout << success[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    int i;

    cin >> n;

    i = 0;
    while (i < n) {
        cin >> data[i][0];
        cin >> data[i][1];
        cin >> data[i][2];
        i++;
    }

    solve();

    return 0;
}

/*
*//*
5
4 2 2
4 1 2
5 2 4
3 3 5
5 1 2
=====
2
1 3 
5
4 5 1
5 3 9
4 1 2
2 1 8
4 1 9
=====
4
1 2 4 5 
*/
