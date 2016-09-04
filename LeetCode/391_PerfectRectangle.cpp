//
//  main.cpp
//  LeetCode_391_PerfectRectangle
//
//  Created by Youngduke Koh on 9/4/16.
//  Copyright © 2016 Youngduke Koh. All rights reserved.
//
// https://leetcode.com/problems/perfect-rectangle/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long long UINT64;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<int, map<int, int>> grid;
        map<int, int> line;
        map<int, map<int, int>>::iterator it;
        map<int, int>::iterator jt;
        UINT64 area, xDist, yDist;
        int xMin, xMax, yMin, yMax, i, x1, x2, y1, y2, cornerCount;
        
        xMin = 2147483647;
        yMin = 2147483647;
        xMax = -2147483647;
        yMax = -2147483647;
        
        area = 0;
        
        for (i = 0; i < rectangles.size(); i++) {
            x1 = rectangles[i][0];
            y1 = rectangles[i][1];
            x2 = rectangles[i][2];
            y2 = rectangles[i][3];
            
            xMin = min(xMin, x1);
            xMax = max(xMax, x2);
            yMin = min(yMin, y1);
            yMax = max(yMax, y2);
            
            xDist = x2 - x1;
            yDist = y2 - y1;
            area += xDist * yDist;
            
            it = grid.find(x1);
            if (it == grid.end()) {
                line.clear();
                line.insert(make_pair(y1, 1));
                line.insert(make_pair(y2, 2));
                grid.insert(make_pair(x1, line));
            } else {
                jt = it->second.find(y1);
                if (jt == it->second.end()) {
                    it->second.insert(make_pair(y1, 1));
                } else {
                    if (jt->second & 1) return false;
                    jt->second |= 1;
                }
                jt = it->second.find(y2);
                if (jt == it->second.end()) {
                    it->second.insert(make_pair(y2, 2));
                } else {
                    if (jt->second & 2) return false;
                    jt->second |= 2;
                }
            }
            
            it = grid.find(x2);
            if (it == grid.end()) {
                line.clear();
                line.insert(make_pair(y1, 4));
                line.insert(make_pair(y2, 8));
                grid.insert(make_pair(x2, line));
            } else {
                jt = it->second.find(y1);
                if (jt == it->second.end()) {
                    it->second.insert(make_pair(y1, 4));
                } else {
                    if (jt->second & 4) return false;
                    jt->second |= 4;
                }
                jt = it->second.find(y2);
                if (jt == it->second.end()) {
                    it->second.insert(make_pair(y2, 8));
                } else {
                    if (jt->second & 8) return false;
                    jt->second |= 8;
                }
            }
        }
        
        xDist = xMax - xMin;
        yDist = yMax - yMin;
        if (area != xDist * yDist) return false;
        
        cornerCount = 0;
        for (it = grid.begin(); it != grid.end(); it++) {
            for (jt = it->second.begin(); jt != it->second.end(); jt++) {
                if (jt->second == 1 || jt->second == 2 || jt->second == 4 || jt->second == 8) {
                    cornerCount++;
                }
            }
        }
        
        if (cornerCount != 4) return false;
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> rectangles;
    vector<int> rectangle;
    
    rectangles.clear();
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(1); rectangle.push_back(3); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(3); rectangle.push_back(1); rectangle.push_back(4); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(3); rectangle.push_back(2); rectangle.push_back(4); rectangle.push_back(4); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(3); rectangle.push_back(2); rectangle.push_back(4); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(2); rectangle.push_back(3); rectangle.push_back(3); rectangle.push_back(4); rectangles.push_back(rectangle);
    cout << s.isRectangleCover(rectangles) << "\n";
    
    rectangles.clear();
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(1); rectangle.push_back(2); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(3); rectangle.push_back(2); rectangle.push_back(4); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(3); rectangle.push_back(1); rectangle.push_back(4); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(3); rectangle.push_back(2); rectangle.push_back(4); rectangle.push_back(4); rectangles.push_back(rectangle);
    cout << s.isRectangleCover(rectangles) << "\n";
    
    rectangles.clear();
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(1); rectangle.push_back(3); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(3); rectangle.push_back(1); rectangle.push_back(4); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(3); rectangle.push_back(2); rectangle.push_back(4); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(3); rectangle.push_back(2); rectangle.push_back(4); rectangle.push_back(4); rectangles.push_back(rectangle);
    cout << s.isRectangleCover(rectangles) << "\n";
    
    rectangles.clear();
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(1); rectangle.push_back(3); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(3); rectangle.push_back(1); rectangle.push_back(4); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(3); rectangle.push_back(2); rectangle.push_back(4); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(2); rectangle.push_back(2); rectangle.push_back(4); rectangle.push_back(4); rectangles.push_back(rectangle);
    cout << s.isRectangleCover(rectangles) << "\n";
    
    rectangles.clear();
    rectangle.clear(); rectangle.push_back(0); rectangle.push_back(0); rectangle.push_back(4); rectangle.push_back(1); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(7); rectangle.push_back(0); rectangle.push_back(8); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(6); rectangle.push_back(2); rectangle.push_back(8); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(5); rectangle.push_back(1); rectangle.push_back(6); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(4); rectangle.push_back(0); rectangle.push_back(5); rectangle.push_back(1); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(6); rectangle.push_back(0); rectangle.push_back(7); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(4); rectangle.push_back(2); rectangle.push_back(5); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(2); rectangle.push_back(1); rectangle.push_back(4); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(0); rectangle.push_back(1); rectangle.push_back(2); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(0); rectangle.push_back(2); rectangle.push_back(2); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(4); rectangle.push_back(1); rectangle.push_back(5); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(5); rectangle.push_back(0); rectangle.push_back(6); rectangle.push_back(1); rectangles.push_back(rectangle);
    cout << s.isRectangleCover(rectangles) << "\n";
    
    rectangles.clear();
    rectangle.clear(); rectangle.push_back(0); rectangle.push_back(0); rectangle.push_back(2); rectangle.push_back(1); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(0); rectangle.push_back(1); rectangle.push_back(1); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(0); rectangle.push_back(2); rectangle.push_back(3); rectangles.push_back(rectangle);
    cout << s.isRectangleCover(rectangles) << "\n";
    
    rectangles.clear();
    rectangle.clear(); rectangle.push_back(0); rectangle.push_back(0); rectangle.push_back(2); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(1); rectangle.push_back(2); rectangle.push_back(3); rectangles.push_back(rectangle);
    cout << s.isRectangleCover(rectangles) << "\n";
    
    rectangles.clear();
    rectangle.clear(); rectangle.push_back(0); rectangle.push_back(0); rectangle.push_back(2); rectangle.push_back(2); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(0); rectangle.push_back(2); rectangle.push_back(1); rectangle.push_back(3); rectangles.push_back(rectangle);
    rectangle.clear(); rectangle.push_back(1); rectangle.push_back(2); rectangle.push_back(2); rectangle.push_back(3); rectangles.push_back(rectangle);
    cout << s.isRectangleCover(rectangles) << "\n";
    
    return 0;
}

/*
[1,1,3,3],
[3,1,4,2],
[3,2,4,4],
[1,3,2,4],
[2,3,3,4]
=====
true

[1,1,2,3],
[1,3,2,4],
[3,1,4,2],
[3,2,4,4]
=====
false

[1,1,3,3],
[3,1,4,2],
[1,3,2,4],
[3,2,4,4]
=====
false

[1,1,3,3],
[3,1,4,2],
[1,3,2,4],
[2,2,4,4]
=====
false
 
[0,0,4,1],[7,0,8,2],[6,2,8,3],[5,1,6,3],[4,0,5,1],[6,0,7,2],[4,2,5,3],[2,1,4,3],[0,1,2,2],[0,2,2,3],[4,1,5,2],[5,0,6,1]
=====
true
*/
