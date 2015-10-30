//
//  main.cpp
//  CareerCup_google_PrimeExpressible
//
//  Created by Youngduke Koh on 10/31/15.
//  Copyright © 2015 Youngduke Koh. All rights reserved.
//
// http://www.careercup.com/question?id=4816567298686976

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long UINT64;

UINT64 getNthNumber(vector<int>& primes, int n) {
    set<UINT64> nums;
    set<UINT64>::reverse_iterator rit;
    UINT64 num;
    unsigned int i;
    
    nums.insert(1);
    for (i = 0; i < primes.size(); i++) {
        num = 0;
        while (true) {
            num += primes[i];
            nums.insert(num);
            if (nums.size() >= n && *nums.rbegin() == num) {
                while (nums.size() > n) {
                    rit = nums.rbegin();
                    nums.erase(next(rit).base());
                }
                break;
            }
        }
    }
    
    return *nums.rbegin();
}

int main(int argc, const char * argv[]) {
    int data[] = {2, 3, 5, 7, 11, 23, 97};
    vector<int> primes(data, data + 7);

    cout << getNthNumber(primes, 3) << "\n";
    cout << getNthNumber(primes, 1000000) << "\n";
    
    primes.clear();
    primes.push_back(99991);
    
    cout << getNthNumber(primes, 1000000) << "\n";
    
    return 0;
}
