// http://www.careercup.com/question?id=4886983698546688

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findSameItems(vector<int>& a, vector<int>& b) {
	vector<int> result;
	vector<int>::iterator itA, itB;

	itA = a.begin();
	itB = b.begin();

	while (itA != a.end() && itB != b.end()) {
		if (*itA == *itB) {
			result.push_back(*itA);
			itA++;
			itB++;
		} else if (*itA < *itB) {
			itA++;
		} else if (*itB < *itA) {
			itB++;
		}
	}

	return result;
}

int main(int argc, char* argv) {
	vector<int> a, b, c;
	vector<int>::iterator it;
	int arrA[] = {2, 5, 5, 5};
	int arrB[] = {2, 2, 3, 5, 5, 7};

	a.assign(arrA, arrA + 4);
	b.assign(arrB, arrB + 6);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	c = findSameItems(a, b);

	for (it = c.begin(); it != c.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";

	return 0;
}
