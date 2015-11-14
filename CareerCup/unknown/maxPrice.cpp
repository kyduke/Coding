//
//  main.cpp
//  CareerCup_unknown_MaxPrice
//
//  Created by Youngduke Koh on 11/14/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// http://www.careercup.com/question?id=5693475519463424

#include <iostream>
#include <vector>

using namespace std;

int maxPrice(vector<int> s, vector<int> p) {
    int length, ret, i, price, count;
    
    length = (int)min(s.size(), p.size());
    
    ret = 0;
    for (i = 0; i < length; i++) {
        count = min(s[i], p[i]);
        if (count <= 0) continue;
        price = (p[i] + p[i] - count + 1) * count / 2;
        ret = max(ret, price);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    vector<int> stalls;
    vector<int> prices;
    
    stalls.push_back(2);
    stalls.push_back(4);
    
    prices.push_back(1);
    prices.push_back(5);
    
    cout << maxPrice(stalls, prices) << "\n";
    
    return 0;
}
