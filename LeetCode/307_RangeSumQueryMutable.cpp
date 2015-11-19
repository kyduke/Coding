//
//  main.cpp
//  LeetCode_307_RangeSumQueryMutable
//
//  Created by Youngduke Koh on 11/19/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// https://leetcode.com/problems/range-sum-query-mutable/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> segTree;
    int offset;
    int nearPow2(int n) {
        int ret;
        
        ret = 1;
        while (ret < n) ret = ret << 1;
        return ret >> 1;
    }
public:
    NumArray(vector<int> &nums) {
        int i;
        
        offset = 0;
        
        if (nums.size() == 0) {
            segTree.push_back(0);
            return;
        } else if (nums.size() == 1) {
            segTree = nums;
            return;
        }
        
        offset = nearPow2((int)nums.size()) * 2 - 1;
        segTree.assign(offset, 0);
        segTree.insert(segTree.end(), nums.begin(), nums.end());
        
        i = (int)segTree.size() - 1;
        while (i > 0) {
            segTree[(i - 1) / 2] += segTree[i];
            i--;
        }
    }
    
    void update(int i, int val) {
        int diff;
        
        i += offset;
        diff = val - segTree[i];
        segTree[i] = val;
        
        while (i > 0) {
            i = (i - 1) / 2;
            segTree[i] += diff;
        }
    }
    
    int sumRange(int i, int j) {
        int sum;
        
        sum = 0;
        i += offset;
        j += offset;
        while (i <= j) {
            if (i == j) {
                sum += segTree[i];
                break;
            }
            
            if (i % 2 == 0) {
                sum += segTree[i];
                i++;
            }
            
            if (j % 2 == 1) {
                sum += segTree[j];
                j--;
            }
            
            i = (i - 1) / 2;
            j = (j - 1) / 2;
        }
        
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int data[] = {1, 2, 3, 4, 5};
    
    nums.assign(data, data + 5);
    
    NumArray na(nums);
    
    cout << na.sumRange(0, 4) << "\n";
    cout << na.sumRange(0, 0) << "\n";
    cout << na.sumRange(0, 1) << "\n";
    cout << na.sumRange(0, 2) << "\n";
    cout << na.sumRange(0, 3) << "\n";
    cout << na.sumRange(1, 3) << "\n";
    
    na.update(1, 10);
    
    cout << na.sumRange(0, 4) << "\n";
    cout << na.sumRange(0, 0) << "\n";
    cout << na.sumRange(0, 1) << "\n";
    cout << na.sumRange(0, 2) << "\n";
    cout << na.sumRange(0, 3) << "\n";
    cout << na.sumRange(1, 3) << "\n";
    
    return 0;
}
