// http://codeforces.com/contest/604/problem/A

#include <iostream>

using namespace std;

double getScore(int m, int w, int x) {
    double a, b;

    a = 0.3 * (double)x;
    b = (1.0 - (double)m / 250) * x - 50.0 * (double)w;

    if (a > b) return a;

    return b;
}

int main(int argc, char* argv[]) {
    int m[5], w[5], s, u;
    double sum;
    
    cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4];
    cin >> w[0] >> w[1] >> w[2] >> w[3] >> w[4];
    cin >> s >> u;

    sum = 0.0;
    sum += getScore(m[0], w[0], 500);
    sum += getScore(m[1], w[1], 1000);
    sum += getScore(m[2], w[2], 1500);
    sum += getScore(m[3], w[3], 2000);
    sum += getScore(m[4], w[4], 2500);
    sum += (double)s * 100.0;
    sum -= (double)u * 50.0;

    cout << (int)sum << "\n";

    return 0;
}

/*
20 40 60 80 100
0 1 2 3 4
1 0
=====
4900

119 119 119 119 119
0 0 0 0 0
10 0
=====
4930
*/
