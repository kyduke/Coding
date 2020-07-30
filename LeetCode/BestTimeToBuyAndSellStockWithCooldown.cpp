// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3405/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy, sellOneDayBefore, sellTwoDaysBefore, i, temp;
        
        bestBuy = 0;
        for (i = 0; i < prices.size(); i++) {
            bestBuy = min(bestBuy, -prices[i]);
        }
        
        sellTwoDaysBefore = 0;
        for (i = 0; i < prices.size(); i++) {
            temp = sellOneDayBefore;
            sellOneDayBefore = bestBuy + prices[i];
            bestBuy = max(bestBuy, sellTwoDaysBefore - prices[i]);
            sellTwoDaysBefore = max(sellTwoDaysBefore, temp);
        }
        
        return max(sellOneDayBefore, sellTwoDaysBefore);
    }
};

/*
[1,2,3,0,2]
=====
3
*/
