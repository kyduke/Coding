//
//  main.cpp
//  HackerRank_algorithm_AlmostSorted
//
//  Created by ydkoh on 6/3/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// https://www.hackerrank.com/challenges/almost-sorted

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int n, a, i, k;
    int t[7] = {0, };
    int c[7] = {0, };
    bool flag;
    
    k = 0;
    
    cin >> n;
    arr.assign(n, 0);
    i = 0;
    cin >> arr[i++];
    while (i < n) {
        cin >> arr[i++];
        if (k > 6) continue;
        if (arr[i - 2] > arr[i - 1]) {
            if (t[k] == -1) {
                c[k]++;
            } else {
                k++;
                t[k] = -1;
                c[k]++;
            }
        } else {
            if (t[k] == 1) {
                c[k]++;
            } else {
                k++;
                t[k] = 1;
                c[k]++;
            }
        }
    }
    
    flag = false;
    if (t[1] == 1) {
        if (t[2] == -1) {
            a = c[1];
            n = c[1] + c[2];
            if (t[3] == 0) {
                if (arr[n] > arr[a - 1]) {
                    flag = true;
                    cout << "yes\n";
                    if (c[2] == 1) {
                        cout << "swap ";
                    } else {
                        cout << "reverse ";
                    }
                    cout << a + 1 << " " << n + 1 << "\n";
                }
            } else {
                if (t[4] == 0) {
                    if (arr[a] < arr[n + 1] && arr[n] > arr[a - 1]) {
                        flag = true;
                        cout << "yes\n";
                        if (c[2] == 1) {
                            cout << "swap ";
                        } else {
                            cout << "reverse ";
                        }
                        cout << a + 1 << " " << n + 1 << "\n";
                    }
                } else if (c[2] == 1 && c[4] == 1) {
                    n = c[1] + c[2] + c[3] + c[4];
                    if (t[5] == 0) {
                        if (arr[a] > arr[n - 1] && arr[n] > arr[a - 1] && arr[n] < arr[a + 1]) {
                            flag = true;
                            cout << "yes\n";
                            cout << "swap " << a + 1 << " " << n + 1 << "\n";
                        }
                    } else if (t[6] == 0) {
                        if (arr[a] > arr[n - 1] && arr[a] < arr[n + 1] && arr[n] > arr[a - 1] && arr[n] < arr[a + 1]) {
                            flag = true;
                            cout << "yes\n";
                            cout << "swap " << a + 1 << " " << n + 1 << "\n";
                        }
                    }
                }
            }
        }
    } else {
        if (t[1] == -1) {
            a = 0;
            n = c[1];
            if (t[2] == 0) {
                flag = true;
                cout << "yes\n";
                if (c[1] == 1) {
                    cout << "swap ";
                } else {
                    cout << "reverse ";
                }
                cout << a + 1 << " " << n + 1 << "\n";
            } else {
                if (t[3] == 0) {
                    if (arr[a] < arr[n + 1]) {
                        flag = true;
                        cout << "yes\n";
                        if (c[2] == 1) {
                            cout << "swap ";
                        } else {
                            cout << "reverse ";
                        }
                        cout << a + 1 << " " << n + 1 << "\n";
                    }
                } else if (c[1] == 1 && c[3] == 1) {
                    n = c[1] + c[2];
                    if (t[4] == 0) {
                        if (arr[a] > arr[n - 1] && arr[n] < arr[a + 1]) {
                            flag = true;
                            cout << "yes\n";
                            cout << "swap " << a + 1 << " " << n + 1 << "\n";
                        }
                    } else {
                        if (arr[a] > arr[n - 1] && arr[a] < arr[n + 1] && arr[n] < arr[a + 1]) {
                            flag = true;
                            cout << "yes\n";
                            cout << "swap " << a + 1 << " " << n + 1 << "\n";
                        }
                    }
                }
            }
        }
    }
    
    if (flag == false) {
        cout << "no\n";
    }
    
    return 0;
}

/*
2
4 2
=====
yes
swap 1 2

3
3 1 2
=====
no

6
1 5 4 3 2 6
=====
yes
reverse 2 5
*/
