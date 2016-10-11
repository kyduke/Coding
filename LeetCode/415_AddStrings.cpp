// https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum;
        vector<int> arr;
        int i, j;
        
        arr.assign(max(num1.size(), num2.size()) + 2, 0);
        
        for (i = num1.size() - 1, j = 0; i >= 0; i--, j++) {
            arr[j] = num1[i] - '0';
        }
        
        for (i = num2.size() - 1, j = 0; i >= 0; i--, j++) {
            arr[j] += num2[i] - '0';
        }
        
        j = 0;
        for (i = 0; i < arr.size() - 1; i++) {
            j += arr[i];
            arr[i] = j % 10;
            j /= 10;
        }
        
        sum = "";
        j = 0;
        for (i = arr.size() - 1; i >= 0; i--) {
            if (j == 0) {
                if (arr[i] > 0) {
                    j = 1;
                    sum += (arr[i] + '0');
                }
            } else {
                sum += (arr[i] + '0');
            }
        }
        
        if (j == 0) {
            sum = "0";
        }
        
        return sum;
    }
};
