// https://leetcode.com/problems/integer-to-english-words/

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
	string smallNumberToWords(int num) {
		string numbers[19] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		string tens[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
		string result;
		int n;

		if (num == 0 || num >= 1000) return "";

		result = "";

		n = num / 100;
		num %= 100;
		if (n > 0) result += numbers[n - 1] + " Hundred";
		if (n > 0 && num > 0) result += " ";

		if (num == 0) return result;

		if (num < 20) {
			result += numbers[num - 1];
		} else {
			n = num / 10;
			num %= 10;
			if (n > 0) result += tens[n - 2];
			if (n > 0 && num > 0) result += " ";

			if (num > 0) result += numbers[num - 1];
		}

		return result;
	}
public:
    string numberToWords(int num) {
        string result;
		int n;

		if (num == 0) return "Zero";

		result = "";

		n = num / 1000000000;
		num %= 1000000000;
		if (n > 0) result += smallNumberToWords(n) + " Billion";
		if (n > 0 && num > 0) result += " ";

		n = num / 1000000;
		num %= 1000000;
		if (n > 0) result += smallNumberToWords(n) + " Million";
		if (n > 0 && num > 0) result += " ";

		n = num / 1000;
		num %= 1000;
		if (n > 0) result += smallNumberToWords(n) + " Thousand";
		if (n > 0 && num > 0) result += " ";

		n = num / 100;
		num %= 100;
		if (n > 0) result += smallNumberToWords(n) + " Hundred";
		if (n > 0 && num > 0) result += " ";

		if (num > 0) result += smallNumberToWords(num);

		return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;

	//cout << s.numberToWords(0) << "\n";
	cout << s.numberToWords(100000) << "\n";
	//cout << s.numberToWords(123) << "\n";
	//cout << s.numberToWords(12345) << "\n";
	//cout << s.numberToWords(1234567) << "\n";

	return 0;
}
