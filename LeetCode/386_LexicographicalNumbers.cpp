//
//  main.cpp
//  LeetCode_386_LexicographicalNumbers
//
//  Created by Youngduke Koh on 9/4/16.
//  Copyright © 2016 Youngduke Koh. All rights reserved.
//
// https://leetcode.com/problems/lexicographical-numbers/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        stack<int> stck;
        int a;
        
        stck.push(0);
        
        while (!stck.empty()) {
            a = stck.top();
            stck.pop();
            
            a++;
            
            if (a <= n) {
                ans.push_back(a);
                if (a % 10 != 9) {
                    stck.push(a);
                }
            }
            
            a *= 10;
            while (a <= n) {
                ans.push_back(a);
                stck.push(a);
                a *= 10;
            }
        }
        
        return ans;
    }
};

void printArray(vector<int> arr) {
    int i;
    
    for (i = 0; i < arr.size(); i++) {
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    printArray(s.lexicalOrder(10));
    printArray(s.lexicalOrder(19));
    printArray(s.lexicalOrder(20));
    printArray(s.lexicalOrder(50));
    printArray(s.lexicalOrder(120));
    
    return 0;
}

/*
10
=====
1, 10, 2, 3, 4, 5, 6, 7, 8, 9

20
=====
1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 20, 3, 4, 5, 6, 7, 8, 9
*/
