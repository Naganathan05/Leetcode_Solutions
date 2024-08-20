/*---------------------------
Method: Space Optimization
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> prev(2, 0), curr(2, 0);
        
        for(int i = prices.size() - 1; i >= 0; i--){
            prev = curr;
            for(int option = 0; option <= 1; option++){
                int currProfit;
                if(option == 0) currProfit = max(-prices[i] + prev[1], prev[0]);
                else currProfit = max(prices[i] - fee + prev[0], prev[1]);
                curr[option] = currProfit;
            }
        }
        return curr[0];
    }
};

/*
Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
Author: M.R.Naganathan
*/
