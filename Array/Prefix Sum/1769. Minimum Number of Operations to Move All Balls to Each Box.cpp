/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int numBoxes = boxes.size();
        vector<int> totalMoves(numBoxes, 0);

        vector<int> prefixSum(numBoxes, 0), suffixSum(numBoxes, 0);

        int ballsOnLeft = 0;
        for (int i = 0; i < numBoxes; i++) {
            if (i > 0) prefixSum[i] = prefixSum[i - 1] + ballsOnLeft;
            ballsOnLeft += (boxes[i] == '1');
        }

        int ballsOnRight = 0;
        for (int i = numBoxes - 1; i >= 0; i--) {
            if (i < numBoxes - 1) suffixSum[i] = suffixSum[i + 1] + ballsOnRight;
            ballsOnRight += (boxes[i] == '1');
        }

        for (int i = 0; i < numBoxes; i++) {
            totalMoves[i] = prefixSum[i] + suffixSum[i];
        }

        return totalMoves;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
Author: M.R.Naganathan
*/
