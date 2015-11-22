//
//  main.cpp
//  CareerCup_amazon_maxDecimalFrom2DArray
//
//  Created by Youngduke Koh on 11/22/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// http://careercup.com/question?id=5735069190717440

#include <iostream>
#include <vector>

using namespace std;

unsigned int getMaxDecialIndex(vector<vector<int>> matrix) {
    unsigned int maxIndex, i, j;
    
    if (matrix.size() == 0) return 0;
    
    maxIndex = 0;
    for (i = 1; i < matrix.size(); i++) {
        for (j = 0; j < matrix[i].size(); j++) {
            if (matrix[maxIndex][j] == matrix[i][j]) continue;
            if (matrix[i][j] == 1) {
                maxIndex = i;
            }
            break;
        }
    }
    
    return maxIndex + 1;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix;
    vector<int> arr;
    
    arr.clear();
    arr.push_back(0); arr.push_back(1); arr.push_back(0);
    matrix.push_back(arr);
    
    arr.clear();
    arr.push_back(1); arr.push_back(1); arr.push_back(0);
    matrix.push_back(arr);
    
    arr.clear();
    arr.push_back(1); arr.push_back(0); arr.push_back(1);
    matrix.push_back(arr);
    
    cout << getMaxDecialIndex(matrix) << "\n";
    
    return 0;
}
