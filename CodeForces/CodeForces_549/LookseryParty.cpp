//http://codeforces.com/problemset/problem/549/B

#include <iostream>
#include <vector>

using namespace std;

int n;
int contacts[100][100];
int targets[100];

void solve() {
    int i, c;
    int employees[100] = {0, };
    vector<int> present;

    c = -1;
    for (i = 0; i < n; i++) {
        if (targets[i] == 0) {
            c = i;
            break;
        }
    }

    if (c == -1) {
        cout << "0\n\n";
        return;
    }

    while (c >= 0) {
        employees[c] = 1;
        present.push_back(c + 1);
        for (i = 0; i < n; i++) {
            targets[i] -= contacts[c][i];
        }
        c = -1;
        for (i = 0; i < n; i++) {
            if (employees[i] == 0 && targets[i] == 0) {
                c = i;
                break;
            }
        }
    }

    cout << present.size() << "\n";
    for (i = 0; i < present.size(); i++) {
        cout << present[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    int i, j;
    char buffer[101];

    cin >> n;

    i = 0;
    while (i < n) {
        cin >> buffer;
        for (j = 0; j < n; j++) {
            contacts[i][j] = (int)(buffer[j] - '0');
        }
        i++;
    }

    i = 0;
    while (i < n) {
        cin >> targets[i];
        i++;
    }

    solve();

    return 0;
}

/*
3
101
010
001
0 1 2
=====
1
1

1
1
1
=====
0


4
1111
0101
1110
0001
1 0 1 0
=====
4
1 2 3 4
*/
