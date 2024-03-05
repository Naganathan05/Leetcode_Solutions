/*---------------------------------------------------------------------
Method 1: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n*sum) => Note: sum: Sum of elements of the array
-----------------------------------------------------------------------*/

bool recursiveFunction(vector<int> &arr, int i, int k, int prevSum, vector<vector<int>> &dp){
    if(i == -1) return false;

    if(dp[i][prevSum] != -1) return dp[i][prevSum];

    int pick = prevSum + arr[i];
    if(pick == k) return true;
    return dp[i][prevSum] = ((recursiveFunction(arr, i - 1, k, pick, dp)) || (recursiveFunction(arr, i - 1, k, prevSum, dp)));
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i <= arr.size() - 1; i++){
        sum += arr[i];
    }
    vector<vector<int>> dp(arr.size(), vector<int>(sum, -1));
    return recursiveFunction(arr, arr.size() - 1, k, 0, dp);
}

/*-----------------------------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n*sum)
--------------------------------------------------------------------------*/



/*
Question Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&leftPanelTabValue=PROBLEM&customSource=studio_nav
Author: M.R.Naganathan
*/
