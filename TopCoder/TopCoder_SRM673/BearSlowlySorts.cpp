// https://community.topcoder.com/stat?c=problem_statement&pm=14083&rd=16616

#include <iostream>
#include <vector>

using namespace std;

class BearSlowlySorts {
public:
	int minMoves(vector<int> w) {
		int i, maxValue, minValue, maxIndex,minIndex;
		bool sorted;

		sorted = true;
		maxValue = w[0];
		maxIndex = 0;
		minValue = w[0];
		minIndex = 0;
		for (i = 1; i < w.size(); i++) {
			if (w[i] < w[i - 1]) sorted = false;
			if (maxValue < w[i]) {
				maxValue = w[i];
				maxIndex = i;
			}
			if (minValue > w[i]) {
				minValue = w[i];
				minIndex = i;
			}
		}

		if (sorted == true) return 0;

		if (minIndex == 0 || maxIndex == w.size() - 1) return 1;

		if (minIndex == w.size() - 1 && maxIndex == 0) return 3;

		return 2;
	}
};

int main(int argc, char* argv[]) {
	BearSlowlySorts s;
	vector<int> nums;
	int data0[] = {2, 6, 8, 5};
	int data1[] = {4, 3, 1, 6, 2, 5};
	int data2[] = {93, 155, 178, 205, 213, 242, 299, 307, 455, 470, 514, 549, 581, 617, 677};
	int data3[] = {50, 20, 30, 40, 10};
	int data4[] = {234, 462, 715, 596, 906, 231, 278, 223, 767, 925, 9, 526, 369, 319, 241, 354, 317, 880, 5, 696};

	nums.clear();
	nums.assign(data0, data0 + 4);
	cout << s.minMoves(nums) << "\n";

	nums.clear();
	nums.assign(data1, data1 + 6);
	cout << s.minMoves(nums) << "\n";

	nums.clear();
	nums.assign(data2, data2 + 15);
	cout << s.minMoves(nums) << "\n";

	nums.clear();
	nums.assign(data3, data3 + 5);
	cout << s.minMoves(nums) << "\n";

	nums.clear();
	nums.assign(data4, data4 + 20);
	cout << s.minMoves(nums) << "\n";

	return 0;
}

/*
{2, 6, 8, 5}
=====
1
    	
{4, 3, 1, 6, 2, 5}
=====
2
    	
{93, 155, 178, 205, 213, 242, 299, 307, 455, 470, 514, 549, 581, 617, 677}
=====
0
    	
{50, 20, 30, 40, 10}
=====
3
    	
{234, 462, 715, 596, 906, 231, 278, 223, 767, 925, 9, 526, 369, 319, 241, 354, 317, 880, 5, 696}
=====
2
*/
