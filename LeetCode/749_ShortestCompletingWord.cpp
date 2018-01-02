// https://leetcode.com/problems/shortest-completing-word

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string ans;
        map<char, int> a, b;
        map<char, int>::iterator it, jt;
        int i, j;
        char c;
        
        for (i = 0; i < licensePlate.size(); i++) {
            c = licensePlate[i];
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
            if (c >= 'a' && c <= 'z') {
                it = a.find(c);
                if (it != a.end()) {
                    it->second++;
                } else {
                    a.insert(make_pair(c, 1));
                }
            }
        }
        
        for (i = 0; i < words.size(); i++) {
            if (ans.size() > 0 && words[i].size() >= ans.size()) continue;
            b.clear();
            for (j = 0; j < words[i].size(); j++) {
                c = words[i][j];
                if (c >= 'A' && c <= 'Z') {
                    c = c - 'A' + 'a';
                }
                if (c >= 'a' && c <= 'z') {
                    it = b.find(c);
                    if (it != b.end()) {
                        it->second++;
                    } else {
                        b.insert(make_pair(c, 1));
                    }
                }
            }
            j = 0;
            for (it = a.begin(); it != a.end(); it++) {
                jt = b.find(it->first);
                if (jt == b.end() || jt->second < it->second) break;
                j++;
            }
            
            if (a.size() == j) {
                ans = words[i];
            }
        }
        
        return ans;
    }
};

/*
1s3 PSt
step steps stripe stepple
=====
steps

1s3 456
looks pest stew show
=====
pest
*/
