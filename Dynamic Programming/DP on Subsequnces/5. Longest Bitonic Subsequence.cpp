/*--------------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-----------------------------------*/

class Solution {
public:
    int LongestBitonicSequence(int n, const vector<int> &nums) {
        vector<int> increasingSub(n, 1);
        vector<int> decreasingSub(n, 1);
        
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] > nums[prev]) {
                    increasingSub[i] = max(increasingSub[i], increasingSub[prev] + 1);
                }
            }
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int prev = n - 1; prev > i; prev--) {
                if(nums[i] > nums[prev]) {
                    decreasingSub[i] = max(decreasingSub[i], decreasingSub[prev] + 1);
                }
            }
        }

        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            if(decreasingSub[i] != 1 && increasingSub[i] != 1) maxLen = max(maxLen, increasingSub[i] + decreasingSub[i] - 1);
        }
        return maxLen;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
Author: M.R.Naganathan
*/
