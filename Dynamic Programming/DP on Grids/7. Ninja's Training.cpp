/*---------------------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
-----------------------------------------------------*/

#include <bits/stdc++.h> 
int recursiveFunction(vector<vector<int>> &points, int ind, int prevact, vector<vector<int>> &dp){
    if(ind == 0){
        int maxpoint = INT_MIN;
        for(int i = 0; i <= 2; i++){
            if(maxpoint < points[ind][i] && i != prevact){
                maxpoint = points[ind][i];
            }
            dp[ind][i] = points[ind][i];
        }
        return maxpoint;
    }
    
    if(dp[ind][prevact] != -1) return dp[ind][prevact];

    int maxpoint = INT_MIN;
    for(int i = 0; i <= 2; i++){
        if(i != prevact){
            int point = points[ind][i] + recursiveFunction(points, ind - 1, i, dp);
            maxpoint = max(maxpoint, point);
        }
    }
    return dp[ind][prevact] = maxpoint;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return recursiveFunction(points, n - 1, 3, dp);
}

/*
Question Link: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM
Author: M.R.Naganathan
*/
