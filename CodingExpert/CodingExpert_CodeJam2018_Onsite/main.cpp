/*
[행렬 곱셈]
n개의 행렬 M1, M2, . . . , Mn 이 주어진다. 행렬 Mi (i = 1, 2, . . . , n)은 R[i]개의 행, C[i]개의 열을 가지고 있다 (R[i] × C[i]).
정수 i(1 ≤ i ≤ n)에 대해서, 아래와 같이 정의되는 값 Vi를 계산하려고 한다.
먼저, i개의 행렬 M1, M2, . . . , Mi을 모두 곱할 수 있는 순서가 있는지 알아본다. 참고로 행렬 곱셈 연산에서
R × C 행렬과 R' × C' 행렬을 곱하려면 C = R'이 성립하여야 하고 결과로 나오는 행렬은 R × C'이다. 만약 i개의 행렬을 (순서를 자유롭게 재배치 하더라도) 곱하는 것이 불가능하다면 Vi = 0 으로 정의된다. 만약 가능하다면, 가능한 모든 방법 중 최종 결과가 되는 행렬의 크기가 가장 커지는 방법을 찾아 그 때 결과로 나온 행렬의 크기 (행의 수 x 열의 수)가 Vi 값이 된다. V1, V2, . . . , Vn를 구해보자.

Input
첫째 줄에는 자연수 n이 주어진다 (1 ≤ n ≤ 1, 000). 다음 n줄에는 각 줄에 정수 두 개가 주어지는데, 각 행렬의 행의 수 R[i]와 열의 수 C[i]이다. 각 행렬의 행의 수와 열의 수는 1 이상 1,000 이하이다.

Output
총 n줄을 출력해야 하고, 각 줄에는 V1 부터 Vn까지 Vi 값을 출력한다.

Subtask 1 (5 points)
• 1 ≤ n ≤ 10
• 1 ≤ R, C ≤ 1, 000

Subtask 2 (10 points)
• 1 ≤ n ≤ 1, 000
• 1 ≤ R, C ≤ 1, 000

<Examples 1>
standard input
3
8 2
2 8
2 2

standard output
16
64
64
i = 1 일 때에는 8x2 행렬 (M1) 하나만 이용하여 원소의 수가 총 16개인 행렬을 만들 수 있다.
i = 2 일 때에는 M1 × M2 를 하여 8x8 행렬을 만들 수 있고, 원소의 수는 총 64개이다. 혹은 M2 × M1 을하여 2x2 행렬을 만들 수 있지만, 원소의 수가 최대가 되는 방법은 상기한 방법이다.
i = 3 일 때에는 M1 × M3 × M2를 통해 8x8 행렬을 만들 수 있다.

<Examples 2>
standard input
3
4 9
9 1
9 9

standard output
36
4
4

<Examples 3>
standard input
3
4 10
10 1
10 6

standard output
40
4
0
i = 3일 때 어떤 순서로 3개의 행렬을 배치하여 곱하더라도 행렬 곱셈 연산을 완료할 수 없으므로 답이 0
이다.

<Examples 4>
standard input
3
10 3
3 10
5 5

standard output
30
100
0

standard input
4
1 1
1 1
1 1
1 1

standard ouput
1
1
1
1
*/

#include <iostream>

using namespace std;

const int SIZE = 1001;

int rows[SIZE] = {0, };
int cols[SIZE] = {0, };
int squares[SIZE] = {0, };

int solve(int noneSquareCount) {
	int i, r, c, x;
	
	if (noneSquareCount == 0) {
		x = 0;
		for (i = 1; i < SIZE; i++) {
			if (squares[i] != 0) {
				if (x != 0) return 0;
				x = i;
			}
		}
		
		return x * x;
	}
	
	r = 0;
	c = 0;
	x = 0;
	for (i = 1; i < SIZE; i++) {
		if (rows[i] > cols[i]) {
			if (rows[i] - cols[i] > 1 || r != 0) return 0;
			r = i;
		} else if (rows[i] < cols[i]) {
			if (cols[i] - rows[i] > 1 || c != 0) return 0;
			c = i;
		} else if (noneSquareCount > 0 && rows[i] == 0 && cols[i] == 0 && squares[i] != 0) {
			return 0;
		} else if (rows[i] != 0 || cols[i] != 0 || squares[i] != 0) {
			x = i;
		}
	}
	
	if (r != 0 && c != 0) return r * c;
	
	return x * x;
}

int main(int argc, char** argv) {
	int n, r, c, noneSquareCount;
	
	scanf("%d", &n);
	noneSquareCount = 0;
	while (n--) {
		scanf("%d %d", &r, &c);
		if (r == c) {
			squares[r]++;
		} else {
			rows[r]++;
			cols[c]++;
			noneSquareCount++;
		}
		printf("%d\n", solve(noneSquareCount));
	}
	return 0;
}
