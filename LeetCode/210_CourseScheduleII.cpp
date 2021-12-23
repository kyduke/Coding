// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> arr;
        map<int, vector<int>> m;
        map<int, vector<int>>::iterator it;
        set<int> s;
        stack<int> stk;
        int i, j, k;
        bool flag;
        
        for (i = 0; i < prerequisites.size(); i++) {
            it = m.find(prerequisites[i][0]);
            if (it == m.end()) {
                arr.clear();
                arr.push_back(prerequisites[i][1]);
                m.insert(make_pair(prerequisites[i][0], arr));
            } else {
                it->second.push_back(prerequisites[i][1]);
            }
        }
        
        for (i = 0; i < numCourses; i++) {
            stk.push(i);
        
            while (!stk.empty()) {
                k = stk.top();
                if (s.find(k) != s.end()) {
                    stk.pop();
                    continue;
                }
                it = m.find(k);
                if (it == m.end()) {
                    stk.pop();
                    ans.push_back(k);
                    s.insert(k);
                    continue;
                }
                flag = false;
                for (j = 0; j < it->second.size(); j++) {
                    if (s.find(it->second[j]) == s.end()) {
                        flag = true;
                        stk.push(it->second[j]);
                    }
                }
                if (flag == false) {
                    stk.pop();
                    ans.push_back(k);
                    s.insert(k);
                }
                if (stk.size() > numCourses * 2) {
                    ans.clear();
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
