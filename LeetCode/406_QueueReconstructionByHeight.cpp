// https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        map<int, set<int>> m;
        map<int, set<int>>::iterator it;
        set<int> s;
        set<int>::iterator sit;
        vector<pair<int, int>> ans;
        pair<int, int> p;
        int i, j, k;
        
        if (people.size() == 0) return ans;
        
        for (i = 0; i < people.size(); i++) {
            it = m.find(people[i].first);
            if (it == m.end()) {
                s.clear();
                s.insert(people[i].second);
                m[people[i].first] = s;
            } else {
                it->second.insert(people[i].second);
            }
        }
        
        p = make_pair(-1, 0);
        ans.assign(people.size(), p);
        
        j = 0;
        for (it = m.begin(); it != m.end(); it++) {
            k = 0;
            for (i = j; i < ans.size(); i++) {
                if (ans[i].first == -1) {
                    j = i;
                    break;
                }
            }
            for (sit = it->second.begin(); sit != it->second.end(); sit++) {
                for (; i < people.size(); i++) {
                    if (ans[i].first != -1) continue;
                    if (*sit == k) {
                        ans[i].first = it->first;
                        ans[i].second = *sit;
                        k++;
                        i++;
                        break;
                    }
                    k++;
                } 
            }
        }
        
        return ans;
    }
};
