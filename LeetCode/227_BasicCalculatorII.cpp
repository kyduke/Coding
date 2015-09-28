//
//  main.cpp
//  LeetCode_227_BasicCalculatorII
//
//  Created by Youngduke Koh on 9/28/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//

// https://leetcode.com/problems/basic-calculator-ii/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        char c;
        int i, n;
        vector<int> nums;
        vector<char> ops;
        vector<int>::iterator it;
        vector<char>::iterator opIt;
        
        n = 0;
        i = 0;
        while (i < s.size()) {
            c = s[i];
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                nums.push_back((n));
                ops.push_back(c);
                n = 0;
            } else if (c >= '0' && c <= '9') {
                n = n * 10 + (c - '0');
            }
            i++;
        }
        nums.push_back(n);
        
        while (nums.size() > 1) {
            if (ops.size() == 0) break;

            if (ops.size() > 1 && (ops[0] == '+' || ops[0] == '-') && (ops[1] == '*' || ops[1] == '/')) {
                if (ops[1] == '*') {
                    nums[1] *= nums[2];
                } else {
                    if (nums[2] == 0) return 0;
                    nums[1] /= nums[2];
                }
                it = nums.begin();
                it++;
                it++;
                nums.erase(it);
                opIt = ops.begin();
                opIt++;
                ops.erase(opIt);
                continue;
            }
            
            if (ops[0] == '+') {
                nums[0] += nums[1];
            } else if (ops[0] == '-') {
                nums[0] -= nums[1];
            } else if (ops[0] == '*') {
                nums[0] *= nums[1];
            } else {
                if (nums[1] == 0) return 0;
                nums[0] /= nums[1];
            }
            it = nums.begin();
            it++;
            nums.erase(it);
            opIt = ops.begin();
            ops.erase(opIt);
        }
        
        return nums[0];
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    string s;
    char buffer[256];
    
    cin.get(buffer, 256);
    
    s = string(buffer);
    
    cout << sol.calculate(s) << "\n";
    
    return 0;
}

/*
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/
