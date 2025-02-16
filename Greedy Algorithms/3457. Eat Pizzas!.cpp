/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int numDays = (pizzas.size() / 4);
        sort(pizzas.begin(), pizzas.end());

        int numOddDays = (numDays / 2) + (numDays % 2);
        int numEvenDays = (numDays / 2);
        int i = pizzas.size() - 1;

        long long totalWeightGain = 0;
        while(numOddDays){
            totalWeightGain += pizzas[i];
            i -= 1;
            numOddDays -= 1;
        }

        while(numEvenDays){
            totalWeightGain += pizzas[i - 1];
            i -= 2;
            numEvenDays -= 1;
        }
        return totalWeightGain;
    }
};

/*
Question Link: https://leetcode.com/problems/eat-pizzas/description/
Author: M.R.Naganathan
*/
