// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution {
private:
    struct Node {
        int a;
        int s;
        int i;
        int j;
    };
    struct Compare {
        bool operator() (const Node& a, const Node& b) {
            if(a.s == b.s) {
                return a.a > b.a;
            }
            return a.s > b.s;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node, vector<Node>, Compare> q;
        vector<pair<int, int>> answer;
        Node node;
        int i, j, a, b;
        
        if (nums2.size() == 0) return answer;
        
        for (a = 0; a < nums1.size(); a++) {
            node.i = a;
            node.j = 0;
            node.a = nums1[a];
            node.s = node.a + nums2[0];
            q.push(node);
        }
        
        while(!q.empty() && k) {
            node = q.top();
            q.pop();
            i = node.i;
            j = node.j;
            if (j >= nums2.size()) {
                continue;
            }
            answer.push_back(make_pair(node.a, nums2[j]));
            k--;
            j++;
            if (j >= nums2.size()) {
                continue;
            }
            node.j = j;
            node.s = node.a + nums2[j];
            q.push(node);
        }
        
        return answer;
    }
};
