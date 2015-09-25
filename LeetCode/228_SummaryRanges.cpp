// https://leetcode.com/problems/summary-ranges/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	string integerToString(long long n) {
		string str;
		string table[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		int sign;
		
		if (n == 0) return "0";
	
		sign = 1;
		if (n < 0) {
			sign = -1;
			n = -n;
		}
	
		str = "";
		while (n) {
			str = table[n % 10] + str;
			n /= 10;
		}
	
		if (sign == -1) {
			str = "-" + str;
		}
	
		return str;
	}
public:
	vector<string> summaryRanges(vector<int>& nums) {
	        vector<string> ranges;
		string str;
		int i;
		long long from, to;
	
		if (nums.size() == 0) return ranges;
	
		from = nums[0];
		to = from;
		for (i = 0; i < nums.size(); i++) {
			if (from >= to) {
				from = nums[i];
				to = from + 1;
				str.append(integerToString(from));
			} else {
				if (to == nums[i]) {
					to++;
				} else {
					if (from + 1 < to) {
						str.append("->");
						str.append(integerToString(to - 1));
					}
					ranges.push_back(str);
					str.clear();
					to = from;
					i--;
				}
			}
		}
	
		if (from < to) {
			if (from + 1 < to) {
				str.append("->");
				str.append(integerToString(to - 1));
			}
			ranges.push_back(str);
		}
	
		return ranges;
	}
};

int main(int argc, char* argv[]) {
	static const int arr[] = {0, 1, 2, 4, 5, 7};
	vector<int> nums (arr, arr + 6);
	vector<string> ranges;
	Solution s;
	int i;

	ranges = s.summaryRanges(nums);

	for (i = 0; i < ranges.size(); i++) {
		cout << ranges[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
[0,1,2,4,5,7]
=====
["0->2","4->5","7"]
*/
