/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxSum = nums[0];
        deque<pair<int,int>> dp;
        dp.push_back({0, nums[0]});

        for(int i = 1; i < n; i++)
        {
            if(i - dp.front().first > k) dp.pop_front();
            
            int current = nums[i];
            if(dp.front().second > 0) current += dp.front().second;
            maxSum = max(current, maxSum);

            while(!dp.empty() && dp.back().second < current) dp.pop_back();
            dp.push_back({i, current});
        }

        return maxSum;
    }
};

/*
Question Link: https://leetcode.com/problems/constrained-subsequence-sum/
Author: M.R.Naganathan
*/
