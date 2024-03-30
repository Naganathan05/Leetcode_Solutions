/*---------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (atmost(nums, goal) - atmost(nums, goal - 1));
    }

    int atmost(vector<int> &nums, int goal){
        int i = 0, cnt = 0, sum = 0;
        for(int j = 0; j <= nums.size() - 1; j++){
            sum += nums[j];
            while(i < nums.size() && sum > goal && i <= j){
                sum -= nums[i];
                i += 1;
            }
            cnt += (j - i + 1);
        }
        return cnt;
    }
};

/*
Question Link: https://leetcode.com/problems/binary-subarrays-with-sum/
Author: M.R.Naganathan
*/
