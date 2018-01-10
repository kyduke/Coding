// https://leetcode.com/problems/employee-free-time/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    vector<Interval> commonInterval(vector<Interval>& a, vector<Interval>& b) {
        vector<Interval> ans;
        Interval interval;
        int i, j, x, y;
        
        x = a.size();
        y = b.size();
        
        i = 0;
        j = 0;
        while (i < x && j < y) {
            if (a[i].end <= b[j].start) {
                i++;
            } else if (a[i].start >= b[j].end) {
                j++;
            } else {
                interval.start = max(a[i].start, b[j].start);
                interval.end = min(a[i].end, b[j].end);
                ans.push_back(interval);
                if (a[i].end > b[j].end) {
                    j++;
                } else if (a[i].end < b[j].end) {
                    i++;
                } else {
                    i++;
                    j++;
                }
            }
        }
        
        return ans;
    }
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> ans, temp;
        Interval interval;
        int i, j, len, a, z;
        
        a = 100000000;
        z = 0;
        len = schedule.size();
        for (i = 0; i < len; i++) {
            a = min(a, schedule[i][0].start);
            z = max(z, schedule[i][schedule[i].size() - 1].end);
        }
        
        interval.start = a;
        interval.end = z;
        ans.push_back(interval);
        
        for (i = 0; i < len; i++) {
            if (a < schedule[i][0].start) {
                interval.start = a;
                interval.end = schedule[i][0].start;
                temp.push_back(interval);
            }
            for (j = 1; j < schedule[i].size(); j++) {
                if (schedule[i][j - 1].end < schedule[i][j].start) {
                    interval.start = schedule[i][j - 1].end;
                    interval.end = schedule[i][j].start;
                    temp.push_back(interval);
                }
            }
            if (schedule[i][schedule[i].size() - 1].end < z) {
                interval.start = schedule[i][schedule[i].size() - 1].end;
                interval.end = z;
                temp.push_back(interval);
            }
            if (temp.size() == 0) {
                ans.clear();
                return ans;
            }
            ans = commonInterval(ans, temp);
            if (ans.size() == 0) {
                return ans;
            }
            temp.clear();
        }
        
        return ans;
    }
};

/*
[[[1,2],[5,6]],[[1,3]],[[4,10]]]
=====
[[3,4]]

[[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
=====
[[5,6],[7,9]]
*/
