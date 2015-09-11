// https://leetcode.com/problems/first-bad-version/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        map<int, bool> m;
        map<int, bool>::iterator it;
        int left, mid, right;
        bool b;
        
        left = 0;
        right = n - 1;
        while (left < right) {
            mid = left + (right - left) / 2;
            
            it = m.find(mid + 1);
            if (it != m.end()) {
                b = it->second;
            } else {
                b = isBadVersion(mid + 1);
                m.insert(make_pair(mid + 1, b));
            }
            
            if (b == true) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        it = m.find(left + 1);
        if (it != m.end()) {
            b = it->second;
        } else {
            b = isBadVersion(left + 1);
        }
        
        return b == true ? left + 1 : left + 2;
    }
};
