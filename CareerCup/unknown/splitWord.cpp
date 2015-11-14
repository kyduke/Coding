//
//  main.cpp
//  CareerCup_unknown_SplitWord
//
//  Created by Youngduke Koh on 11/14/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// http://careercup.com/question?id=5100595952222208

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printStringArray(vector<string> arr) {
    int i;
    
    cout << "[";
    for (i = 0; i < arr.size(); i++) {
        cout << "\"" << arr[i] << "\"";
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

string integerToString(int n) {
    string str;
    string table[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
    if (n == 0) return "0";
    
    str = "";
    while (n) {
        str = table[n % 10] + str;
        n /= 10;
    }
    
    return str;
}

vector<string> splitWord(string str, int limit) {
    vector<string> arr;
    vector<int> marks;
    vector<int> spaces;
    string size;
    int i, start, markIdx, spaceIdx;
    
    for (i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            spaces.push_back(i);
            if (i == 0) continue;
            switch (str[i - 1]) {
                case ',': case '.': case '?': case '!':
                    marks.push_back(i);
            }
        }
    }
    spaces.push_back(i);
    marks.push_back(i);
    
    start = 0;
    markIdx = 0;
    spaceIdx = 0;
    while (markIdx < marks.size()) {
        if (marks[ markIdx ] - start <= limit) {
            markIdx++;
            continue;
        }
        
        if (markIdx > 0 && marks[ markIdx - 1 ] > start && marks[ markIdx - 1 ] - start <= limit) {
            arr.push_back(str.substr(start, marks[ markIdx - 1 ] - start));
            start = marks[ markIdx - 1 ] + 1;
        } else {
            while (spaceIdx < spaces.size() && spaces[ spaceIdx ] <= start + limit) spaceIdx++;
            if (spaceIdx > 0 && spaces[ spaceIdx ] > start + limit) spaceIdx--;
            if (spaces[ spaceIdx ] > start && spaces[ spaceIdx ] <= start + limit) {
                arr.push_back(str.substr(start, spaces[ spaceIdx ] - start));
                start = spaces[ spaceIdx ] + 1;
            } else {
                arr.push_back(str.substr(start, limit));
                start += limit;
            }
        }
    }
    arr.push_back(str.substr(start, marks[ markIdx - 1 ] - start));
    
    size = "/" + integerToString((int)arr.size()) + ")";
    for (i = 0; i < arr.size(); i++) {
        arr[i] += "(" + integerToString(i + 1) + size;
    }
    
    return arr;
}

int main(int argc, const char * argv[]) {
    vector<string> arr;
    
    arr = splitWord("Hi Sivasrinivas, your Uber is arriving now!", 25);
    printStringArray(arr);
    
    
    arr = splitWord("01234567890123456789", 15);
    printStringArray(arr);
    
    arr = splitWord("", 5);
    printStringArray(arr);
    
    return 0;
}
