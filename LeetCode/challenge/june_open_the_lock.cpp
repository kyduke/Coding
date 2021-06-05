// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3767/

class Solution {
private:
    int arr[10000] = {0, };
    int visited[10000] = {0, };
    int strToNum(string str) {
        return (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0');
    }
    int makeNum(int n, int div, int diff) {
        int top, down, k;
        
        top = (n / (div * 10)) * (div * 10);
        down = n % div;
        k = (n / div) % 10;
        k = (k + diff + 10) % 10;
        
        return top + k * div + down;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        queue<int> q;
        int i, k, goal;
        
        for (i = 0; i < deadends.size(); i++) {
            arr[strToNum(deadends[i])] = -1;
        }
        goal = strToNum(target);
        arr[goal] = -1;
        
        q.push(0);
        while (!q.empty()) {
            i = q.front();
            q.pop();
            
            k = i / 10000;
            i %= 10000;
            
            if (i == goal) {
                arr[i] = k;
                break;
            }
            if (arr[i] == -1) {
                continue;
            }
            if (visited[i] == 1) {
                continue;
            }
            visited[i] = 1;
            
            k = (k + 1) * 10000;
            q.push(k + makeNum(i, 1, 1));
            q.push(k + makeNum(i, 1, -1));
            q.push(k + makeNum(i, 10, 1));
            q.push(k + makeNum(i, 10, -1));
            q.push(k + makeNum(i, 100, 1));
            q.push(k + makeNum(i, 100, -1));
            q.push(k + makeNum(i, 1000, 1));
            q.push(k + makeNum(i, 1000, -1));
        }
        
        return arr[goal];
    }
};

/*
["0201","0101","0102","1212","2002"]
"0202"
==========
6

["8888"]
"0009"
==========
1

["8887","8889","8878","8898","8788","8988","7888","9888"]
"8888"
==========
-1

["0000"]
"8888"
==========
-1
*/
