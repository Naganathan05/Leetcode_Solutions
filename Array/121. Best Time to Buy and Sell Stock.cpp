/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = INT_MIN, min_ele = INT_MAX;
        for(int i = 0; i <= prices.size() - 1; i++){
            max_prof = max(max_prof, (prices[i] - min_ele));
            min_ele = min(min_ele, prices[i]);
        }
        if(max_prof < 0) max_prof = 0;
        return max_prof;
    }
};

/*
Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Author: M.R.Naganathan
*/
