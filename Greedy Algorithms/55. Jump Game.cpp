/*----------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/jump-game/
Author: M.R.Naganathan
*/
