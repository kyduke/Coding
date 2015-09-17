// http://www.careercup.com/question?id=5133958972964864

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_INTEGER = 2147483646;

void compareDistance(int& a, int& b, int& c, int& minDistance, int A, int B, int C) {
	int t;

	t = abs(A - B) + abs(B - C) + abs(C - A);
	if (t < minDistance) {
		minDistance = t;
		a = A;
		b = B;
		c = C;
	}
}

void findMinDistanceInThreeArray(vector<int>& A, vector<int>& B, vector<int>& C) {
	int minDistance, t;
	int a, b, c;
	int i, j, k;
	bool foundSmallB, foundEqualB, foundBigB;
	bool foundSmallC, foundEqualC, foundBigC;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	a = b = c = 0;
	minDistance = MAX_INTEGER;
	j = 0;
	k = 0;
	for (i = 0; i < A.size(); i++) {
		if (j < 0) j = 0;
		if (j < B.size()) {
			foundSmallB = false;
			foundEqualB = false;
			foundBigB = false;

			while (j < B.size() - 1 && B[j] < A[i]) j++;

			if (B[j] == A[i]) {
				foundEqualB = true;
			} else {
				if (B[j] > A[i] && j - 1 >= 0) j--;
				if (B[j] < A[i]) {
					foundSmallB = true;
					if (j + 1 < B.size() && B[j + 1] > A[i]) foundBigB = true;
				} else {
					foundBigB = true;
					j--;
				}
			}
		}

		if (k < 0) k = 0;
		if (k < C.size()) {
			foundSmallC = false;
			foundEqualC = false;
			foundBigC = false;

			while (k < C.size() - 1 && C[k] < A[i]) k++;

			if (C[k] == A[i]) {
				foundEqualC = true;
			} else {
				if (C[k] > A[i] && k - 1 >= 0) k--;
				if (C[k] < A[i]) {
					foundSmallC = true;
					if (k + 1 < C.size() && C[k + 1] > A[i]) foundBigC = true;
				} else {
					foundBigC = true;
					k--;
				}
			}
		}

		if (foundEqualB && foundEqualC) {
			minDistance = 0;
			a = A[i];
			b = B[j];
			c = C[k];
			break;
		} else if (foundEqualB) {
			if (foundSmallC) compareDistance(a, b, c, minDistance, A[i], B[j], C[k]);
			if (foundBigC) compareDistance(a, b, c, minDistance, A[i], B[j], C[k + 1]);
		} else if (foundEqualC) {
			if (foundSmallB) compareDistance(a, b, c, minDistance, A[i], B[j], C[k]);
			if (foundBigB) compareDistance(a, b, c, minDistance, A[i], B[j + 1], C[k]);
		} else {
			if (foundSmallB) {
				if (foundSmallC) compareDistance(a, b, c, minDistance, A[i], B[j], C[k]);
				if (foundBigC) compareDistance(a, b, c, minDistance, A[i], B[j], C[k + 1]);
			}
			if (foundBigB) {
				if (foundSmallC) compareDistance(a, b, c, minDistance, A[i], B[j + 1], C[k]);
				if (foundBigC) compareDistance(a, b, c, minDistance, A[i], B[j + 1], C[k + 1]);
			}
		}
	}

	cout << a << ", " << b << ", " << c << "\n";
}

int main(int argc, char* argv[]) {
	vector<int> A, B, C;

	A.clear();
	A.push_back(1);
	A.push_back(5);
	A.push_back(100);

	B.clear();
	B.push_back(1);
	B.push_back(45);
	B.push_back(75);

	C.clear();
	C.push_back(1);
	C.push_back(100);
	C.push_back(200);

	findMinDistanceInThreeArray(A, B, C);

	A.clear();
	A.push_back(1);
	A.push_back(200);
	A.push_back(100);

	B.clear();
	B.push_back(1);
	B.push_back(110);
	B.push_back(75);

	C.clear();
	C.push_back(300);
	C.push_back(120);
	C.push_back(200);

	findMinDistanceInThreeArray(A, B, C);

	A.clear();
	A.push_back(10);
	A.push_back(15);
	A.push_back(20);

	B.clear();
	B.push_back(5);
	B.push_back(10);
	B.push_back(25);

	C.clear();
	C.push_back(3);
	C.push_back(5);
	C.push_back(15);

	findMinDistanceInThreeArray(A, B, C);

	return 0;
}
