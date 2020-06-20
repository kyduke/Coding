#include <iostream>

using namespace std;

const int SIZE = 1000001;
char str[SIZE] = {0, };
char temp[SIZE] = {0, };

void solve(int n, int k) {
    long long i, j, d;
    
    for (i = 1; i <= k; i <<= 1) {
        if (i & k) {
            for (j = 0; j < n; j++) {
                temp[j] = str[j];
            }
            for (j = 0; j < n; j++) {
                d = (i + j) % n;
                if (temp[j] == 'A') {
                    if (temp[d] == 'A') {
                        str[j] = 'A';
                    } else if (temp[d] == 'B') {
                        str[j] = 'B';
                    } else if (temp[d] == 'C') {
                        str[j] = 'C';
                    } else if (temp[d] == 'D') {
                        str[j] = 'D';
                    }
                } else if (temp[j] == 'B') {
                    if (temp[d] == 'A') {
                        str[j] = 'B';
                    } else if (temp[d] == 'B') {
                        str[j] = 'A';
                    } else if (temp[d] == 'C') {
                        str[j] = 'D';
                    } else if (temp[d] == 'D') {
                        str[j] = 'C';
                    }
                } else if (temp[j] == 'C') {
                    if (temp[d] == 'A') {
                        str[j] = 'C';
                    } else if (temp[d] == 'B') {
                        str[j] = 'D';
                    } else if (temp[d] == 'C') {
                        str[j] = 'A';
                    } else if (temp[d] == 'D') {
                        str[j] = 'B';
                    }
                } else if (temp[j] == 'D') {
                    if (temp[d] == 'A') {
                        str[j] = 'D';
                    } else if (temp[d] == 'B') {
                        str[j] = 'C';
                    } else if (temp[d] == 'C') {
                        str[j] = 'B';
                    } else if (temp[d] == 'D') {
                        str[j] = 'A';
                    }
                }
            }
        }
    }
    
    str[n] = 0;
    
    printf("%s\n", s);
}

int main(int argc, char** argv) {
    int n, k;
    
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    
    solve(n, k);

    return 0;
}
