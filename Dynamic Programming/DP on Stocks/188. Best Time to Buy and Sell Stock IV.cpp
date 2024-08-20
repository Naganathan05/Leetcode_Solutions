/*----------------------------
Method: Space Optimization
  Time Complexity: O(n * k)
  Space Complexity: O(k)
------------------------------*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> prev(k + 1, vector<int> (2, 0)), curr(k + 1, vector<int> (2, 0));
        
        for(int i = prices.size() - 1; i >= 0; i--){
            prev = curr;
            for(int numTrans = 0; numTrans <= k - 1; numTrans++){
                for(int option = 0; option <= 1; option++){
                    int currProfit;
                    if(option == 0) currProfit = max(-prices[i] + prev[numTrans][1], prev[numTrans][0]);
                    else currProfit = max(prices[i] + prev[numTrans + 1][0], prev[numTrans][1]);
                    curr[numTrans][option] = currProfit;
                }
            }
        }
        return curr[0][0];
    }
};

/*
Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
Author: M.R.Naganathan
*/
