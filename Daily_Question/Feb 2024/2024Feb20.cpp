/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),i;
        int esum = (n*(n + 1))/2, sum = 0;

        for(i = 0; i <= n - 1; i++){
            sum += nums[i];
        }

        return (esum - sum);
    }
};

/*
Question Link: https://leetcode.com/problems/missing-number/?envType=daily-question&envId=2024-02-20
Author: M.R.Naganathan
*/
