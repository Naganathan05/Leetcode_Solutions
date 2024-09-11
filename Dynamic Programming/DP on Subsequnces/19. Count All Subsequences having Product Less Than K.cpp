/*----------------------------------------------
Method: Memoization
  Time Complexity: O(n * product)
  Space Complexity: O(n * product) + O(product)
--------------------------------------------------*/

#include <bits/stdc++.h> 
using namespace std;

int count(vector<int> &a, int i, int currp, int p, vector<vector<int>> &dp) {
    if(currp > p) return 0;
    if(i == a.size()) return 1;

    if(dp[i][currp] != -1) return dp[i][currp];

    int take = 0;
    if(currp * a[i] <= p) take = count(a, i + 1, currp * a[i], p, dp);
    int noTake = count(a, i + 1, currp, p, dp);
    dp[i][currp] = take + noTake;
    return dp[i][currp];
}

int countSubsequences(vector<int> &a, int n, int p) {
    vector<vector<int>> dp(n, vector<int>(p + 1, -1));
    return count(a, 0, 1, p, dp) - 1;
}

/*
Question Link: https://www.naukri.com/code360/problems/count-the-number-of-subsequences-having-product-not-more-than-p_1214647
Author: M.R.Naganathan
*/
