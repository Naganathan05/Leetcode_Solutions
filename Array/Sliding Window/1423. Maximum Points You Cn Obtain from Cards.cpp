/*----------------------------
  Time Complexity: O(k)
  Space Complexity: O(1)
------------------------------*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;
        for(int i = 0; i <= k - 1; i++) maxSum += cardPoints[i];

        int i = k - 1, j = cardPoints.size() - 1, currSum = maxSum;
        while(i >= 0){
            currSum += (cardPoints[j] - cardPoints[i]);
            i -= 1;
            j -= 1;
            maxSum = max(currSum, maxSum);
        }
        return maxSum;

    }
};

/*
Question Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
Author: M.R.Naganathan
*/
