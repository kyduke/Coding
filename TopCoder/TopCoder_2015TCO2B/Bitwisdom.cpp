// http://community.topcoder.com/stat?c=problem_statement&pm=13778&rd=16500

#include <iostream>
#include <vector>

using namespace std;

class Bitwisdom {
private:
	int flipCount(vector<int>& bits) {
		int i, c, n;

		c = 0;
		n = bits[0];
		for (i = 0; i < bits.size(); i++) {
			if (n != bits[i]) {
				c++;
				n = bits[i];
			}
		}

		if (c == 0 && n == 1) {
			c = 1;
		}

		return c;
	};
	double calc(int start, double chance, vector<int>& p, vector<int>& bits) {
		double result;

		if (chance == 0.0) {
			return 0.0L;
		}

		if (start == p.size()) {
			return chance * (double)flipCount(bits);
		}

		result = calc(start + 1, chance * ((100.0L - (double)p[start]) / 100.0L), p, bits);
		bits[start] = 1;
		result += calc(start + 1, chance * ((double)p[start] / 100.0L), p, bits);
		bits[start] = 0;

		return result;
	};
public:
	double expectedActions(vector<int> p) {
		vector<int> bits;
		double result;
		int i;

		for (i = 0; i < p.size(); i++) {
			bits.push_back(0);
		}

		result = calc(0, 1.0L, p, bits);

		return result;
	};
};

int main(int argc, char* argv[]) {
	Bitwisdom b;
	vector<int> nums;

	cout.precision(10);

	nums.clear();
	nums.push_back(100);
	nums.push_back(100);
	nums.push_back(100);
	cout << fixed << b.expectedActions(nums) << "\n";

	nums.clear();
	nums.push_back(50);
	nums.push_back(50);
	cout << fixed << b.expectedActions(nums) << "\n";

	nums.clear();
	nums.push_back(0);
	nums.push_back(40);
	nums.push_back(50);
	nums.push_back(60);
	cout << fixed << b.expectedActions(nums) << "\n";

	nums.clear();
	nums.push_back(37);
	nums.push_back(63);
	nums.push_back(23);
	nums.push_back(94);
	nums.push_back(12);
	cout << fixed << b.expectedActions(nums) << "\n";

	return 0;
}

/*
{100, 100, 100}
=====
1.0
    	
{50, 50}
=====
0.75
    	
{0, 40, 50, 60}
=====
1.4
    	
{37, 63, 23, 94, 12}
=====
2.6820475464
*/
