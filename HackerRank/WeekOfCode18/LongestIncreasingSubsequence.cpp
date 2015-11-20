// https://www.hackerrank.com/challenges/longest-increasing-subsequent/submissions/code/15297734
// http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence.cpp

#include <iostream>
#include <vector>

using namespace std;

int findLIS(vector<int>& arr) {
    vector<int> lis;
    int i, j, k, n;
 
	if (arr.empty()) return 0;
 
	lis.push_back(0);
 
	for (i = 1; i < arr.size(); i++) {
		if (arr[ lis.back() ] < arr[i]) {
			lis.push_back(i);
			continue;
		}

        j = 0;
        k = lis.size() - 1;
		while (j < k) {
			n = (j + k) / 2;
            if (arr[ lis[n] ] < arr[i]) {
                j = n + 1;
            } else {
                k = n;
            }
		}

		if (arr[i] < arr[ lis[j] ]) {
			lis[j] = i;
		}	
	}
 
	return lis.size();
}

int main() {
    vector<int> arr;
    int N, a;
    
    cin >> N;
    while (N--) {
        cin >> a;
        arr.push_back(a);
    }
    
    cout << findLIS(arr) << "\n";
    
    return 0;
}
