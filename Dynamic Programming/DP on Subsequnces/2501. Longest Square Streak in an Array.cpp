/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    // int binarySearxh(vector<int> &nums, int i){
    //     int low = i, high = nums.size() - 1;
    //     int currSeqLen = 1;
    //     while(low <= high){
    //         int mid = low + (high - low) / 2;
    //         if(nums[mid] == pow(nums[i], 2)){
    //             currSeqLen += 1;
    //             high = nums.size() - 1;
    //             i = mid;
    //         }
    //         else if(nums[mid] > pow(nums[i], 2)) high = mid - 1;
    //         else low = mid + 1;
    //     }
    //     return currSeqLen;
    // }

    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mapping;
        vector<int> dp(nums.size(), 1);

        int longestSeq = -1;
        for(int i = 0; i <= nums.size() - 1; i++){
            int target = (int) sqrt(nums[i]);
            if(target * target == nums[i] && mapping.find(target) != mapping.end()){
                int ind = mapping[target];
                dp[i] = dp[ind] + 1;
                longestSeq = max(longestSeq, dp[i]);
            }
            mapping[nums[i]] = i;
        }
        return longestSeq;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-square-streak-in-an-array/
Author: M.R.Naganathan
*/
