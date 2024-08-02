/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int numElements = nums.size();
        int totOnes = 0, maxOnes = 0;

        for (int num : nums) totOnes += (num == 1);
        for (int i = 0; i < totOnes; i++) maxOnes += (nums[i] == 1);

        int currOnes = maxOnes;
        int n = numElements;

        for (int j = 0; j < n; j++) {
            currOnes -= (nums[j] == 1);
            currOnes += (nums[(j + totOnes) % n] == 1);
            maxOnes = max(maxOnes, currOnes);
        }
        return totOnes - maxOnes;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
Author: M.R.Naganathan
*/
