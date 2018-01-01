// https://www.hackerrank.com/contests/w8/challenges/gneck

#include<iostream>

using namespace std;

typedef unsigned long long UINT64;

const int MOD = 1000000007;

struct Matrix3X3 {
	UINT64 v[3][3];
};

void identityMatrix(Matrix3X3& m) {
    int i, j;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            m.v[i][j] = 0;
        }
    }
    m.v[0][0] = 1;
    m.v[1][1] = 1;
    m.v[2][2] = 1;
}

Matrix3X3 multiplyMatrix(Matrix3X3 a, Matrix3X3 b) {
	Matrix3X3 ans;
    int i, j, k;
    
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			ans.v[i][j] = 0;
			for (k = 0; k < 3; k++)
				ans.v[i][j] = (ans.v[i][j] + a.v[i][k] * b.v[k][j]) % MOD;
		}
	}
    
	return ans;
}

Matrix3X3 powerMatrix(Matrix3X3 m, UINT64 n) {
	Matrix3X3 ans, c;
    
  identityMatrix(ans);
  c = m;
	while (n) {
		if (n % 2 == 1) {
      ans = multiplyMatrix(ans, c);
    }
		c = multiplyMatrix(c, c);
		n /= 2;
	}
    
	return ans;
}

int main(int argc, char* argv[]) {
    Matrix3X3 x, m, b;
    int t;
    UINT64 ans, n;
    
    b.v[0][0] = 1;
    b.v[0][1] = 0;
    b.v[0][2] = 0;
    b.v[1][0] = 1;
    b.v[1][1] = 0;
    b.v[1][2] = 0;
    b.v[2][0] = 1;
    b.v[2][1] = 0;
    b.v[2][2] = 0;
    
    scanf("%d", &t);
    while (t--) {
      scanf("%llu", &n);
        
		  m.v[0][0] = 1;
		  m.v[0][1] = 1;
		  m.v[0][2] = 0;
		  m.v[1][0] = 0;
		  m.v[1][1] = 0;
		  m.v[1][2] = 1;
		  m.v[2][0] = 1;
		  m.v[2][1] = 0;
		  m.v[2][2] = 0;
        
      x = multiplyMatrix(powerMatrix(m, n - 2), b);
        
      ans = 0;
      ans = (ans + x.v[0][0]) % MOD;
      ans = (ans + x.v[1][0]) % MOD;
      ans = (ans + x.v[2][0]) % MOD;
       
      printf("%llu\n", ans);
    }
        
	return 0;
}

/*
2
2
3
=====
3
4
*/
