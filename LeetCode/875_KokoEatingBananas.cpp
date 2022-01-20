// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
private:
    int howManyHours(vector<int>& piles, int k) {
        int h;
        
        h = 0;
        for (int pile : piles) {
            h += pile / k;
            if (pile % k > 0) {
                h++;
            }
        }
        
        return h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left, mid, right, hour;
        
        left = 1;
        right = 1000000000;
        
        while (left < right) {
            mid = (left + right) / 2;
            hour = howManyHours(piles, mid);
            if (hour <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
