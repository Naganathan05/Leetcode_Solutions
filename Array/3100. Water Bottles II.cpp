/*----------------------------------------------
  Time Complexity: O(numExchange)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottlesDrunk = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange){
            emptyBottles -= numExchange;
            numExchange += 1;
            bottlesDrunk += 1;
            emptyBottles += 1;
        }
        return bottlesDrunk;
    }
};

/*
Question Link: https://leetcode.com/problems/water-bottles-ii/
Author: M.R.Naganathan
*/
