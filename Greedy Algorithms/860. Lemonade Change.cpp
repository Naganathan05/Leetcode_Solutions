/*-------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------------------------*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCoins = 0, tenCoins = 0;
        for(int i : bills){
            if(i == 5) fiveCoins += 1;
            else if(i == 10){
                if(fiveCoins > 0) fiveCoins -= 1;
                else return false;
                tenCoins += 1;
            }
            else if(i == 20){
                if(tenCoins > 0 && fiveCoins > 0){
                    tenCoins -= 1;
                    fiveCoins -= 1;
                }
                else if(fiveCoins >= 3) fiveCoins -= 3;
                else return false;
            }
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/lemonade-change/
Author: M.R.Naganathan
*/
