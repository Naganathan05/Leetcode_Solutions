/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxLen = 0, i = 0;
        map<int, int> window;
        for(int j = 0; j <= nums.size() - 1; j++){
            window[nums[j]] += 1;
            while((prev(window.end()) -> first) - ((window.begin()) -> first) > limit){
                window[nums[i]] -= 1;
                if(window[nums[i]] == 0) window.erase(nums[i]);
                i += 1;
            }
            maxLen = max(maxLen, (j - i + 1));
        }
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
Author: M.R.Naganathan
*/
