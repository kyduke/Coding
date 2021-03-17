// https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3674/
// solution: https://dev.to/seanpgallivan/solution-best-time-to-buy-and-sell-stock-with-transaction-fee-5dlp


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int i, buying, selling;
        
        buying = 0;
        selling = -prices[0];
        for (i = 0; i < prices.size(); i++) {
            buying = max(buying, selling + prices[i] - fee);
            selling = max(selling, buying - prices[i]);
        }
        
        return buying;
    }
};

