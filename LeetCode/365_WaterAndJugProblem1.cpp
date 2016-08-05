// https://leetcode.com/problems/water-and-jug-problem/
// Timeout 104579, 104593, 12444

class Solution {
private:
    map<int, set<int>> cache;
    queue<pair<int, int>> q;
    
    void insertQueue(int a, int b) {
        map<int, set<int>>::iterator it;
        set<int> s;
        
        it = cache.find(a);
        if (it != cache.end()) {
            if (it->second.find(b) != it->second.end()) return;
            it->second.insert(b);
        } else {
            s.insert(b);
            cache.insert(make_pair(a, s));
        }
        
        q.push(make_pair(a, b));
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        int a, b, c, d, e;
        
        a = 0;
        b = 0;
        insertQueue(a, b);
        while (!q.empty()) {
            a = q.front().first;
            b = q.front().second;
            q.pop();
            
            if (a == z || b == z || a + b == z) return true;
            
            c = a;
            d = 0;
            insertQueue(c, d);
            
            c = a;
            d = y;
            insertQueue(c, d);
            
            c = 0;
            d = b;
            insertQueue(c, d);
            
            c = 0;
            d = y;
            insertQueue(c, d);
            
            c = x;
            d = b;
            insertQueue(c, d);
            
            c = x;
            d = 0;
            insertQueue(c, d);
            
            c = x;
            d = y;
            insertQueue(c, d);
            
            e = y - b;
            if (a < e) {
                c = 0;
                e = a;
            } else {
                c = a - e;
            }
            d = b + e;
            insertQueue(c, d);
            
            e = x - a;
            if (b < e) {
                d = 0;
                e = b;
            } else {
                d = b - e;
            }
            c = a + e;
            insertQueue(c, d);
        }
        
        return false;
    }
};
