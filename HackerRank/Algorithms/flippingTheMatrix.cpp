// https://www.hackerrank.com/challenges/flipping-the-matrix

#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 129;

int matrix[SIZE][SIZE] = {0, };

int main() {
    int q, n, i, j, a, b, x;
    
    cin >> q;
    while (q--) {
        memset(matrix, 0, sizeof(int) * SIZE * SIZE);
        
        cin >> n;
        for (i = 0; i < 2 * n; i++) {
            a = i;
            if (i >= n) {
                a = n + n - i - 1;
            }
            for (j = 0; j < 2 * n; j++) {
                b = j;
                if (j >= n) {
                    b = n + n - j - 1;
                }
                cin >> x;
                matrix[a][b] = max(matrix[a][b], x);
            }
        }
        
        x = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                x += matrix[i][j];
            }
        }
        
        cout << x << "\n";
    }
    return 0;
}
