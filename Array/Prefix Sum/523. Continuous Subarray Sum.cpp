/*------------------------
  Time Complexity: O(n)
  Space Comlpexity: O(n)
--------------------------*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = -1;
        int currSum = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            currSum += nums[i];
            if(prefix.find((currSum % k)) != prefix.end()){
                if(i - prefix[currSum % k] >= 2) return true;
            }
            else prefix[currSum % k] = i;
        }
        return false;
    }
};

/*
Question Link: https://leetcode.com/problems/continuous-subarray-sum/
Author: M.R.Naganathan
*/
