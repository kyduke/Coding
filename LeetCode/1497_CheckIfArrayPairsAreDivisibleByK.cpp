// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnt[100000] = {0, };
        int i;
        
        if (arr.size() % 2 == 1) return false;
        
        for (i = 0; i < arr.size(); i++) {
            cnt[((arr[i] % k) + k) % k]++;
        }
        
        if (cnt[0] % 2 == 1) return false;
        if (k % 2 == 0 && cnt[k / 2] % 2 == 1) return false;
        for (i = 1; i < (k - 1) / 2; i++) {
            if (cnt[i] != cnt[k - i]) return false;
        }
        
        return true;
    }
};

/*
[1,2,3,4,5,10,6,7,8,9] 5
=====
true

[1,2,3,4,5,6] 7
=====
true

[1,2,3,4,5,6] 10
=====
false

[-10,10] 2
=====
true

[-1,1,-2,2,-3,3,-4,4] 3
=====
true
*/
