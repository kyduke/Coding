// http://careercup.com/question?id=5756151524229120

#include <iostream>
#include <vector>

using namespace std;

struct Object {
	char value;
	Object(char v) {
		value = v;
	}
};

void solve(vector<Object>& A, vector<int> B) {
	int from, to, i;
	Object temp(' ');

	if (A.size() != B.size()) return;

	for (from = 0; from < A.size(); from++) {
		to = B[from];
		if (from == to) continue;
		temp = A[from];
		A[from] = A[to];
		A[to] = temp;
		i = from + 1;
		while (i < A.size()) {
			if (B[i] == from) {
				B[i] = to;
				break;
			}
			i++;
		}
	}
}

int main(int argc, char* argv[]) {
	vector<Object> arrA;
	vector<int> arrB;
	int i;

	arrA.push_back(Object('C'));
	arrA.push_back(Object('D'));
	arrA.push_back(Object('E'));
	arrA.push_back(Object('F'));
	arrA.push_back(Object('G'));

	arrB.push_back(3);
	arrB.push_back(0);
	arrB.push_back(4);
	arrB.push_back(1);
	arrB.push_back(2);

	for (i = 0; i < arrA.size(); i++) {
		cout << arrA[i].value;
	}
	cout << "\n";

	solve(arrA, arrB);

	for (i = 0; i < arrA.size(); i++) {
		cout << arrA[i].value;
	}
	cout << "\n";

	return 0;
}
