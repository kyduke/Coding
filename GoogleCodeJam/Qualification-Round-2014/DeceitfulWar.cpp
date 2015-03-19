//
//  main.cpp
//  GoogleCodeJam_QualificationRound2014_DeceitfulWar
//
//  Created by Youngduke Koh on 3/19/15.
//  Copyright (c) 2015 Youngduke Koh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int deceitfulWar(pair<double, int>* a, int n) {
    int i, count, sum;
    
    count = 0;
    sum = 0;
    for (i = n - 1; i >= 0; i--) {
        if (a[i].second == 1) {
            sum++;
        } else {
            if (sum > 0) {
                sum--;
                count++;
            }
        }
    }
    
    return count;
}

int war(pair<double, int>* a, int n) {
    int i, count, sum;
    
    count = 0;
    sum = 0;
    for (i = n - 1; i >= 0; i--) {
        sum += a[i].second;
        if (sum > count) count = sum;
    }
    
    return count;
}

int main(int argc, char* argv[]) {
    int T, i, N, j;
    double temp;
    pair<double, int> a[2000];
    
    ifstream in("in.txt");
    cin.rdbuf(in.rdbuf());
    
    cin >> T;
    i = 0;
    while (i < T) {
        i++;
        cin >> N;
        j = 0;
        while (j < N) {
            cin >> temp;
            a[j].first = temp;
            a[j].second = 1;
            j++;
        }
        j = 0;
        while (j < N) {
            cin >> temp;
            a[j + N].first = temp;
            a[j + N].second = -1;
            j++;
        }
        sort(a, a + N + N);
        cout << "Case #" << i << ": ";
        cout << deceitfulWar(a, N + N) << " ";
        cout << war(a, N + N) << "\n";
    }
    
    return 0;
}

/*
4
1
0.5
0.6
2
0.7 0.2
0.8 0.3
3
0.5 0.1 0.9
0.6 0.4 0.3
9
0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458
===== 
Case #1: 0 0
Case #2: 1 0
Case #3: 2 1
Case #4: 8 4
 */
