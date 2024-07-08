/*------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
--------------------------------------*/

class Solution {
public:
    int Partition(vector<int>& arr, int i, int k, vector<int>& dp) {
        if (i >= arr.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int maxElement = 0, maxSum = 0;
        for (int j = i; j < arr.size(); ++j) {
            maxElement = max(maxElement, arr[j]);
            int currSum = 0;
            if((j - i + 1) <= k) currSum = (maxElement * (j - i + 1)) + Partition(arr, j + 1, k, dp);
            maxSum = max(maxSum, currSum);
        }
        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return Partition(arr, 0, k, dp);
    }
};

/*--------------------------------------
Method: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
-----------------------------------------*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> dp(arr.size() + 1, 0);
        for(int i = arr.size() - 1; i >= 0; i--){
            int maxElement = 0, maxSum = 0;
            for (int j = i; j < arr.size(); j++) {
                maxElement = max(maxElement, arr[j]);
                int currSum = 0;
                if((j - i + 1) <= k) currSum = (maxElement * (j - i + 1)) + dp[j + 1];
                maxSum = max(maxSum, currSum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};

/*
Question Link: https://leetcode.com/problems/partition-array-for-maximum-sum/description/
Author: M.R.Naganathan
*/
