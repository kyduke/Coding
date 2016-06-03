// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> m1, m2;
        map<int, int>::iterator it;
        int i, k;
        
        for (i = 0; i < nums1.size(); i++) {
            m1[ nums1[i] ]++;
        }
        
        for (i = 0; i < nums2.size(); i++) {
            it = m1.find(nums2[i]);
            if (it != m1.end()) {
                k = it->second;
                it = m2.find(nums2[i]);
                if (it == m2.end()) {
                    m2[ nums2[i] ]++;
                } else if (it->second < k) {
                    m2[ nums2[i] ]++;
                }
            }
        }
        
        for (it = m2.begin(); it != m2.end(); it++) {
            for (i = 0; i < it->second; i++) {
                result.push_back(it->first);
            }
        }
        
        return result;
    }
};
