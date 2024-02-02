/*----------------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0, st = 0, en = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(st < en){
            if(nums[st] + nums[en] > k){
                en -= 1;
            }
            else if(nums[st] + nums[en] < k){
                st += 1;
            }
            else{
                st += 1;
                en -= 1;
                ans += 1;
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/
Author: M.R.Naganathan
*/
