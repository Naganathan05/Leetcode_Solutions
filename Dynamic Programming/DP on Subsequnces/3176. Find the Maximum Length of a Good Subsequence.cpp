/*--------------------------------------
Method: Memoization
  Time Complexity: O(n * n * k)
  Space Complexity: O(n * n * k) + O(n)
-----------------------------------------*/

class Solution {
public:
    int dp[503][503][26];
    int maxLength(vector<int> &nums, int i, int prev, int cnt){
        if(i == nums.size() || cnt < 0) return 0;

        int maxLen = -1;
        if(dp[i][prev + 1][cnt] != -1) return dp[i][prev + 1][cnt];

        if(prev == -1){
            maxLen = max(maxLen, maxLength(nums, i + 1, -1, cnt));
            maxLen = max(maxLen, 1 + maxLength(nums, i + 1, i, cnt));
        }
        else{
            if(nums[i] == nums[prev]) maxLen = max(maxLen, 1 + maxLength(nums, i + 1, prev, cnt));
            else{
                maxLen = max(maxLen, maxLength(nums, i + 1, prev, cnt));
                if(cnt > 0) maxLen = max(maxLen, 1 + maxLength(nums, i + 1, i, cnt - 1));
            }
        }
        return dp[i][prev + 1][cnt] = maxLen;
    }

    int maximumLength(vector<int>& nums, int k) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        memset(dp, -1, sizeof(dp));
        int maxLen = maxLength(nums, 0, -1, k);
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/
Author: M.R.Naganathan
*/
