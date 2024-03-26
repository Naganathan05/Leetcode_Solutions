/*----------------------------------------
Method 1: Memoization 
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
------------------------------------------*/

#include <bits/stdc++.h> 

int matrix(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int min_ele = 1e9;
    for(int k = i; k <= j - 1; k++){
        int steps = (arr[i - 1] * arr[k] * arr[j]) + matrix(arr, i, k, dp) + matrix(arr, k + 1, j, dp);
        min_ele = min(min_ele, steps);
    }
    return dp[i][j] = min_ele;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N + 1, vector<int> (N + 1, -1));
    return matrix(arr, 1, N - 1, dp);
}

/*--------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
-----------------------------------------------*/

#include <bits/stdc++.h> 
int matrixMultiplication(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }
    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 1; j < N; j++) {
            int mini = 1e9;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}

/*
Question Link: https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344
Author: M.R.Naganathan
*/
