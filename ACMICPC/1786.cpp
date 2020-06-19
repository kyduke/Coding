// https://www.acmicpc.net/problem/1786

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 1000001;

int fail[SIZE] = {0, };
char buffer[SIZE] = {0, };
vector<int> ans;

void preKMP(string& pattern) {
    int i, m, k;
    
    m = pattern.size();

    fail[0] = -1;
    for (i = 1; i < m; i++) {
        k = fail[i - 1];
        while (k >= 0) {
            if (pattern[k] == pattern[i - 1]) {
                break;
            } else {
                k = fail[k];
            }
        }
        fail[i] = k + 1;
    }
}

void KMP(string pattern, string target) {
    int m, n, i, k;
    
    m = pattern.length();
    n = target.length();
    i = 0;
    k = 0;
    while (i < n) {
        if (k == -1) {
            i++;
            k = 0;
        } else if (target[i] == pattern[k]) {
            i++;
            k++;
            if (k == m) {
            	ans.push_back(i - m + 1);
            	k--;
            	k = fail[k];
            }
        } else {
            k = fail[k];
        }
    }
}

int main() {
	string target, pattern;
	int i;
	
	cin.getline(buffer, sizeof(buffer));
	target = buffer;
	
	cin.getline(buffer, sizeof(buffer));
	pattern = buffer;
	
	preKMP(pattern);
	KMP(pattern, target);
	
	cout << ans.size() << "\n";
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
