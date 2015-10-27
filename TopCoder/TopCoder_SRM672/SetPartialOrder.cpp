// http://community.topcoder.com/stat?c=problem_statement&pm=14075&rd=16552

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SetPartialOrder {
public:
	string compareSets(vector<int>& a, vector<int>& b) {
		int i, j, matchCount;
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		i = 0;
		j = 0;
		matchCount = 0;
		while (i < a.size() && j < b.size()) {
			if (a[i] > b[j]) {
				j++;
			} else if (a[i] < b[j]) {
				i++;
			} else {
				matchCount++;
				i++;
				j++;
			}
		}

		if (a.size() == matchCount && b.size() == matchCount) {
			return "EQUAL";
		} else if (a.size() == matchCount && b.size() > matchCount) {
			return "LESS";
		} else if (b.size() == matchCount && a.size() > matchCount) {
			return "GREATER";
		}

		return "INCOMPARABLE";
	}
};

int main(int argc, char* argv[]) {
	SetPartialOrder order;
	vector<int> arrA, arrB;

	arrA.clear();
	arrA.push_back(1);
	arrA.push_back(2);
	arrA.push_back(3);
	arrA.push_back(5);
	arrA.push_back(8);

	arrB.clear();
	arrB.push_back(8);
	arrB.push_back(5);
	arrB.push_back(1);
	arrB.push_back(3);
	arrB.push_back(2);

	cout << order.compareSets(arrA, arrB) << "\n";

	arrA.clear();
	arrA.push_back(2);
	arrA.push_back(3);
	arrA.push_back(5);
	arrA.push_back(7);

	arrB.clear();
	arrB.push_back(1);
	arrB.push_back(2);
	arrB.push_back(3);
	arrB.push_back(4);
	arrB.push_back(5);
	arrB.push_back(6);
	arrB.push_back(7);
	arrB.push_back(8);
	arrB.push_back(9);
	arrB.push_back(10);

	cout << order.compareSets(arrA, arrB) << "\n";

	arrA.clear();
	arrA.push_back(2);
	arrA.push_back(4);
	arrA.push_back(6);
	arrA.push_back(8);
	arrA.push_back(10);
	arrA.push_back(12);
	arrA.push_back(14);
	arrA.push_back(16);

	arrB.clear();
	arrB.push_back(2);
	arrB.push_back(4);
	arrB.push_back(8);
	arrB.push_back(16);

	cout << order.compareSets(arrA, arrB) << "\n";

	arrA.clear();
	arrA.push_back(42);
	arrA.push_back(23);
	arrA.push_back(31);

	arrB.clear();
	arrB.push_back(15);
	arrB.push_back(23);
	arrB.push_back(31);

	cout << order.compareSets(arrA, arrB) << "\n";

	return 0;
}

/*
{1, 2, 3, 5, 8}
{8, 5, 1, 3, 2}
=====
EQUAL

{2, 3, 5, 7}
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
=====
LESS

{2, 4, 6, 8, 10, 12, 14, 16}
{2, 4, 8, 16}
=====
GREATER

{42, 23, 17}
{15, 23, 31}
=====
INCOMPARABLE
*/
