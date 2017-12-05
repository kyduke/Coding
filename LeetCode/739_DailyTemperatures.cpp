// https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        map<int, vector<int>> history;
        map<int, vector<int>>::iterator it;
        vector<int> arr;
        vector<int> ans;
        int i, j;
        
        ans.assign(temperatures.size(), 0);
        
        for (i = 0; i < temperatures.size(); i++) {
            while (true) {
                it = history.begin();
                if (it == history.end() || it->first >= temperatures[i]) break;
                for (j = 0; j < it->second.size(); j++) {
                    ans[ it->second[j] ] = i - it->second[j];
                }
                history.erase(it);
            }
            it = history.find(temperatures[i]);
            if (it == history.end()) {
                arr.clear();
                arr.push_back(i);
                history.insert(make_pair(temperatures[i], arr));
            } else {
                it->second.push_back(i);
            }
        }
        
        return ans;
    }
};

/*
[73, 74, 75, 71, 69, 72, 76, 73]
=====
[1, 1, 4, 2, 1, 1, 0, 0]
*/
