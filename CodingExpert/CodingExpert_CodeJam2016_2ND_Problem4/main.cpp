//
//  main.cpp
//  LGCodeJam_2016_2_D
//
//  Created by Young Duke Koh on 9/1/16.
//  Copyright © 2016 Young Duke Koh. All rights reserved.
//
// LGE Code Jam 2016 2nd Problem 4, Two Convexes
// Convex Hull, Graham's Scan

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 200;
const double PI = atan2(0.0, -1.0);

double angle[SIZE][SIZE];
double dista[SIZE][SIZE];

vector<pair<double, double>> points;
int n;

double calcAngle(pair<double, double>& a, pair<double, double>& b) {
    double rad;
    
    rad = atan2(b.second - a.second, b.first - a.first);
    if (rad < 0) rad += PI + PI;
    
    return rad;
}

double calcDistance(pair<double, double>& a, pair<double, double>& b) {
    double dist;
    
    dist = sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
    
    return dist;
}

double convexHullLength(vector<int>& arr) {
    double dist, minX, minY, minRad, prevRad;
    int i, a, first, curr, next;
    
    if (arr.size() == 1) return 0.0;
    
    a = arr[0];
    first = a;
    minX = points[a].first;
    minY = points[a].second;
    for (i = 1; i < arr.size(); i++) {
        a = arr[i];
        if (minY > points[a].second) {
            first = a;
            minX = points[a].first;
            minY = points[a].second;
        } else if (minY == points[a].second && minX > points[a].first) {
            first = a;
            minX = points[a].first;
            minY = points[a].second;
        }
    }
    
    curr = first;
    
    minRad = -1.0;
    next = curr;
    for (i = 0; i < arr.size(); i++) {
        a = arr[i];
        if (a == curr) continue;
        if (minRad < 0 || minRad > angle[curr][a]) {
            minRad = angle[curr][a];
            next = a;
        }
    }
    dist = dista[curr][next];
    prevRad = minRad;
    
    while (first != next) {
        minRad = -1.0;
        curr = next;
        for (i = 0; i < arr.size(); i++) {
            a = arr[i];
            if (a == curr) continue;
            if (prevRad < angle[curr][a] && (minRad < 0.0 || minRad > angle[curr][a])) {
                minRad = angle[curr][a];
                next = a;
            }
        }
        dist += dista[curr][next];
        if (next == first) break;
        prevRad = minRad;
    }
    
    return dist;
}

double solve() {
    vector<int> groupA;
    vector<int> groupB;
    double rad, dist, from, to, length, temp;
    unsigned long long a, b;
    int i, j, k;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            rad = calcAngle(points[i], points[j]);
            angle[i][j] = rad;
            if (rad < PI) {
                rad += PI;
            } else if (rad > PI) {
                rad -= PI;
            } else {
                rad = 0.0;
            }
            angle[j][i] = rad;
            dist = calcDistance(points[i], points[j]);
            dista[i][j] = dist;
            dista[j][i] = dist;
        }
    }
    
    length = -1.0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            groupA.clear();
            groupB.clear();
            from = angle[i][j];
            to = angle[j][i];
            for (k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                rad = angle[i][k];
                if (rad >= from && rad <= to) {
                    groupA.push_back(k);
                } else {
                    groupB.push_back(k);
                }
            }
            temp = 0.0;
            groupA.push_back(i);
            groupA.push_back(j);
            if (groupA.size() > 0 && groupB.size() > 0) {
                temp += convexHullLength(groupA);
                temp += convexHullLength(groupB);
                if (length < 0 || length > temp) length = temp;
            }
            groupA.pop_back();
            groupA.pop_back();
            
            temp = 0.0;
            groupB.push_back(i);
            groupB.push_back(j);
            if (groupA.size() > 0 && groupB.size() > 0) {
                temp += convexHullLength(groupA);
                temp += convexHullLength(groupB);
                if (length < 0 || length > temp) length = temp;
            }
        }
    }
    
    a = (int)length;
    length = length - (double)a;
    length = length * 100000.0;
    length = round(length);
    b = (int)length;
    length = (double)a + (double)(b / 100000.0);
    
    return length;
}

int main(int argc, const char * argv[]) {
    int t, i, x, y;
    
    cin >> t;
    while (t--) {
        cin >> n;
        points.clear();
        for (i = 0; i < n; i++) {
            cin >> x >> y;
            points.push_back(make_pair((double)x, (double)y));
        }
        
        printf("%.5f\n", solve());
    }
    
    return 0;
}

/*
3
6
0 0
1 0
0 1
5 2
6 2
5 3
4
0 0
1 0
1 1
0 1
8
0 0
1 0
1 1
0 1
100 2
101 2
101 3
100 3
=====
6.82843
3.41421
8.00000
*/
