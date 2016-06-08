//
//  main.cpp
//  CareerCup_amazon_AddAndMin
//
//  Created by ydkoh on 6/8/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// https://careercup.com/question?id=5734393046892544

#include <iostream>
#include <set>

using namespace std;

class AddAndGetMin {
private:
    multiset<int> data;
public:
    void add(int n) { data.insert(n); }
    int getMin() {
        multiset<int>::iterator it = data.begin();
        int n = 0;
        
        if (it != data.end()) {
            n = *it;
            data.erase(it);
        }
        
        return n;
    }
};

int main(int argc, const char * argv[]) {
    AddAndGetMin agm;
    
    agm.add(3);
    agm.add(12);
    agm.add(5);
    agm.add(6);
    agm.add(1);
    
    cout << agm.getMin() << "\n";
    cout << agm.getMin() << "\n";
    cout << agm.getMin() << "\n";
    cout << agm.getMin() << "\n";
    cout << agm.getMin() << "\n";
    cout << agm.getMin() << "\n";
    
    return 0;
}
