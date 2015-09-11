// https://leetcode.com/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int>::reverse_iterator it;
        int i, result;
        
        if (citations.size() == 0) return 0;
        if (citations[0] > citations.size()) return citations.size();
        
		result = 0;
		i = 1;
        for (it = citations.rbegin(); it != citations.rend(); it++) {
            result = max(result, min(*it, i));
			i++;
        }
        
        return result;
    }
};
