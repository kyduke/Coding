// https://www.hackerrank.com/contests/hourrank-16/challenges/pile-of-candies

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> arr;
    int n, c, i, j, happiness, count;
    
    cin >> n;
    
    arr.assign(n, 0);
    
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    happiness = 0;
    count = 0;
    for (i = 0; i < n; i++) {
        c = arr[i] + arr[i];
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            c = min(c, arr[j]);
        }
        if (happiness < c) {
            happiness = c;
            count = 1;
        } else if (happiness == c) {
            count++;
        }
    }

    cout << happiness << " " << count << "\n";
    
    return 0;
}

/*
3
6 3 7
=====
6 1

2
3 3
=====
3 2
*/
