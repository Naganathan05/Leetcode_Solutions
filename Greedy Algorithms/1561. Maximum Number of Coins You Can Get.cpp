/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int myself = piles.size() - 2, bob = 0;
        int maxCoins = 0;
        while(bob < myself){
            maxCoins += piles[myself];
            myself -= 2;
            bob += 1;
        }
        return maxCoins;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
Author: M.R.Naganathan
*/
