/*--------------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
----------------------------------------------------*/

class Solution{
    public:
    long long amount(int arr[], int n, int i, int j, vector<vector<long long>> &dp){
        if(i > j || i >= n || i < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long long front = arr[i] + min(amount(arr, n, i + 1, j - 1, dp), amount(arr, n, i + 2, j, dp));
        long long back = arr[j] + min(amount(arr, n, i + 1, j - 1, dp), amount(arr, n, i, j - 2, dp));
        return dp[i][j] = max(front, back);
    }
    
    long long maximumAmount(int n, int arr[]){
        vector<vector<long long>> dp(n, vector<long long> (n, -1));
        return amount(arr, n, 0, n - 1, dp);
    }
};

/*------------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
--------------------------------------------------------*/

class Solution{
    public:
    long long maximumAmount(int n, int arr[]){
        vector<vector<long long>> dp(n + 2, vector<long long> (n + 2, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j <= n - 1; j++){
                long long first = 0, second = 0;
                if(j - 1 >= 0) first = dp[i + 1][j - 1];
                if(j - 2 >= 0) second = dp[i][j - 2];
                long long front = arr[i] + min(first, dp[i + 2][j]);
                long long back = arr[j] + min(first, second);
                dp[i][j] = max(front, back);
            }
        }
        return dp[0][n - 1];
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
Author: M.R.Naganathan
*/
