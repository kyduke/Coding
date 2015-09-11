// https://leetcode.com/problems/h-index/
// https://en.wikipedia.org/wiki/H-index

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        multiset<int> s;
        multiset<int>::reverse_iterator it;
        int i, result;
        
        for (i = 0; i < citations.size(); i++) s.insert(citations[i]);
        
		result = 0;
		i = 1;
        for (it = s.rbegin(); it != s.rend(); it++) {
            result = max(result, min(*it, i));
			i++;
        }
        
        return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> citations;
	int arr[] = {3, 0, 6, 1, 5};

	citations.assign(arr, arr + 5);

	cout << s.hIndex(citations) << "\n";

	return 0;
}
