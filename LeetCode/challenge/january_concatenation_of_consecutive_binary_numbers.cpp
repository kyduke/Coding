// https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3618/

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans;
        int i, k, r, s;
        
        ans = 0;
        k = 1;
        s = 0;
        while (k <= n) {
            r = k;
            r >>= s;
            while (r) {
                r >>= 1;
                s++;
            }
            ans = ((ans << s) + k) % 1000000007;
            k++;
        }
        
        return ans;
    }
};

// TLE Solution
class Solution {
public:
    int concatenatedBinary(int n) {
        vector<int> bigN, bigK;
        string str, temp;
        long long ans;
        int i, k, r;
        
        temp = "";
        k = n;
        while (k) {
            temp += (k & 1) ? '1' : '0';
            k >>= 1;
        }
        
        str = temp;
        k = n - 1;
        while (k) {
            for (i = 0; i < temp.size(); i++) {
                if (temp[i] == '0') {
                    temp[i] = '1';
                } else {
                    temp[i] = '0';
                    if (i == temp.size() - 1) {
                        temp = temp.substr(0, i);
                    }
                    break;
                }
            }
            str += temp;
            k--;
        }
        
        bigN.assign(2, 0);
        bigK.push_back(1);
        bigK.push_back(0);
        for (i = 0; i < str.size(); i++) {
            if (str[i] == '1') {
                r = 0;
                for (k = 0; k < bigK.size(); k++) {
                    bigN[k] += bigK[k] + r;
                    r = bigN[k] / 10;
                    bigN[k] %= 10;
                }
            }
            r = 0;
            for (k = 0; k < bigK.size(); k++) {
                bigK[k] *= 2;
                bigK[k] += r;
                r = bigK[k] / 10;
                bigK[k] %= 10;
            }
            if (bigK[bigK.size() - 1] > 0) {
                bigK.push_back(0);
                bigN.push_back(0);
            }
        }
        
        ans = 0;
        for (i = bigN.size() - 1; i >= 0; i--) {
            ans = (ans * 10 + bigN[i]) % 1000000007;
        }
        
        return ans;
    }
};
