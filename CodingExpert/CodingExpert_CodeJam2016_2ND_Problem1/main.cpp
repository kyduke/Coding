//
//  main.cpp
//  LGCodeJam_2016_2_A
//
//  Created by Young Duke Koh on 9/2/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
// LGE Code Jam 2016 2nd Problem 1, Sub Circle Length

#include <iostream>
#include <cmath>

using namespace std;

const double PI = atan2(0.0, -1.0);

int solve(int x, int y, int n) {
    int ans;
    double length, angle, angle1, angle2;
    
    length = (double)n;
    
    angle1 = atan((double)x / (double)y) * 2.0;
    angle2 = atan((double)(n - x) / (double)y) * 2.0;
    angle = PI + PI - angle1 - angle2;
    
    length += angle * (double)y;
    
    ans = length;
    if (ans < length) {
        ans++;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int t, x, y, n;
    
    cin >> t;
    while (t--) {
        cin >> x >> y >> n;
        
        cout << solve(x, y, n) << "\n";
    }
    
    return 0;
}

/*
6
96 16 112
84 11 150
59 53 70
91 81 123
47 4 131
49 10 86
=====
143
157
293
435
133
96
*/
