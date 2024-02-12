/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int min_len = INT_MAX, sum = nums[0];
        while(j <= nums.size() - 1){
            if(sum >= target){
                min_len = min(min_len, j - i + 1);
                sum -= nums[i];
                i += 1;
            }
            else{
                j += 1;
                if(j != nums.size()){
                    sum += nums[j];
                }
            }
        }
        return min_len % INT_MAX;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-size-subarray-sum/
Author: M.R.Naganathan
*/
