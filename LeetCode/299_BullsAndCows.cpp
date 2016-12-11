// https://leetcode.com/problems/bulls-and-cows/

class Solution {
private:
    string number2string(int n) {
        string str;
        
        if (n == 0) return "0";
        
        str = "";
        while (n) {
            str = char((n % 10) + '0') + str;
            n /= 10;
        }
        
        return str;
    }
public:
    string getHint(string secret, string guess) {
        int i, j, bulls, cows;
        string str;
        
        bulls = 0;
        cows = 0;
        str = "";
        
        for (i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                secret[i] = 'x';
                guess[i] = 'y';
                bulls++;
            }
        }
        
        for (i = 0; i < secret.size(); i++) {
            for (j = 0; j < guess.size(); j++) {
                if (guess[j] == secret[i]) {
                    secret[i] = 'x';
                    guess[j] = 'y';
                    cows++;
                    break;
                }
            }
        }
        
        str += number2string(bulls);
        str += 'A';
        str += number2string(cows);
        str += 'B';
        
        return str;
    }
};
