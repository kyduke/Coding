// http://codeforces.com/contest/603/problem/A

#include <iostream>

using namespace std;

const int SIZE = 100001;

char str[SIZE];

int main(int argc, char* argv[]) {
    int n, i, s, f, e;

    cin >> n;
    cin >> str;

    s = 1;
    for (i = 1; i < n; i++) {
        if (str[i - 1] != str[i]) {
            s++;
        }
    }

    f = -1;
    e = -1;
    for (i = 1; i < n; i++) {
        if (str[i] == str[i - 1]) {
            f = i;
            break;
        }
    }

    for (i = n - 2; i >= 0; i--) {
        if (str[i] == str[i + 1]) {
            e = i;
            break;
        }
    }

    if (f != -1) {
        if (f > e) {
            s++;
        } else {
            s += 2;
        }
    }

    cout << s << "\n";

    return 0;
}
