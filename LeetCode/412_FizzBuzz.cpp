// https://leetcode.com/problems/fizz-buzz/

class Solution {
private:
    string numberToString(int n) {
        string str;
        
        str = "";
        while (n) {
            str += ((n % 10) + '0');
            n /= 10;
        }
        reverse(str.begin(), str.end());
        
        return str;
    }
public:
    vector<string> fizzBuzz(int n) {
        vector<string> arr;
        int i;
        
        if (n < 1) return arr;
        
        arr.assign(n, "");
        for (i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                arr[i - 1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                arr[i - 1] = "Fizz";
            } else if (i % 5 == 0) {
                arr[i - 1] = "Buzz";
            } else {
                arr[i - 1] = numberToString(i);
            }
        }
        
        return arr;
    }
};
