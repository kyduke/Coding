//
//  main.cpp
//  CareerCup_unknown_ReversePositive
//
//  Created by Youngduke Koh on 11/16/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// http://www.careercup.com/question?id=5756186739605504

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printArray(vector<int>& arr) {
    int i;
    
    for (i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void reversePositive(vector<int>& arr) {
    vector<int>::iterator it;
    stack<int> stck;
    int head;
    
    head = 0;
    it = arr.begin();
    while (it != arr.end()) {
        if (*it <= 0) {
            while (!stck.empty()) {
                arr[head] = stck.top();
                head++;
                stck.pop();
            }
            head++;
        } else {
            stck.push(*it);
        }
        it++;
    }
    while (!stck.empty()) {
        arr[head] = stck.top();
        head++;
        stck.pop();
    }
}

int main(int argc, const char * argv[]) {
    vector<int> arr;
    int data[] = {4, 3, 8, 9, -2, 6, 10, 13, -1, 2, 3, 0};
    
    arr.assign(data, data + 12);
    
    printArray(arr);
    reversePositive(arr);
    printArray(arr);
    
    return 0;
}
