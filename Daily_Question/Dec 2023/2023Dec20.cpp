/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first_min = INT_MAX, second_min = INT_MAX - 1;

        for(int i = 0; i <= prices.size() - 1; i++){
            if(prices[i] < first_min){
                second_min = first_min;
                first_min = prices[i];
            }
            else if(prices[i] < second_min){
                second_min = prices[i];
            }
        }

        int rem_money = money - (first_min + second_min);
        if(rem_money >= 0){
            return rem_money;
        }
        return money;
    }
};

/*
Question Link: https://leetcode.com/problems/buy-two-chocolates/?envType=daily-question&envId=2023-12-20
Author: M.R.Naganathan
*/
