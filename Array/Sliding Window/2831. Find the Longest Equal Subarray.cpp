/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int maxFreq = 0, i = 0;
        for(int j = 0; j <= nums.size() - 1; j++){
            freq[nums[j]] += 1;
            maxFreq = max(maxFreq, freq[nums[j]]);
            while(i < nums.size() && ((j - i + 1) - maxFreq) > k){
                freq[nums[i]] -= 1;
                i += 1;
            }
        }
        return maxFreq;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-longest-equal-subarray/
Author: M.R.Naganathan
*/
