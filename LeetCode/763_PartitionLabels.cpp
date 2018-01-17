// https://leetcode.com/problems/partition-labels/description/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
		int alpha[26][2];
		int order[26];
		int i, j, k;

		for (i = 0; i < 26; i++) {
			alpha[i][0] = 1000;
			alpha[i][1] = -1;
			order[i] = -1;
		}

		j = 0;
		for (i = 0; i < S.size(); i++) {
			k = S[i] - 'a';
			if (alpha[k][1] == -1) {
				order[j] = k;
				j++;
			}
			alpha[k][0] = min(alpha[k][0], i);
			alpha[k][1] = max(alpha[k][1], i);
		}

		for (i = 0; i < 26; i++) {
			if (order[i] == -1) continue;
			for (j = i + 1; j < 26; j++) {
				if (order[j] == -1) continue;
				if (alpha[ order[i] ][0] < alpha[ order[j] ][1] && alpha[ order[i] ][1] > alpha[ order[j] ][0]) {
					alpha[ order[i] ][0] = min(alpha[ order[i] ][0], alpha[ order[j] ][0]);
					alpha[ order[i] ][1] = max(alpha[ order[i] ][1], alpha[ order[j] ][1]);
					order[j] = -1;
				}
			}
			ans.push_back(alpha[ order[i] ][1] - alpha[ order[i] ][0] + 1);
		}

		return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> result;
	int i;

	result = s.partitionLabels("ababcbacadefegdehijhklij");
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	result = s.partitionLabels("caedbdedda");
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	result = s.partitionLabels("a");
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
ababcbacadefegdehijhklij
=====
9 7 8

caedbdedda
=====
1 9
*/
