/*-----------------------------------
Method: Memoization
  Time Complexity: O(n * m)
  Space Complexity: O(m * n) + O(m)
--------------------------------------*/

int Collect(vector<vector<int>> &mine, int i, int j, vector<vector<int>> &dp, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m) return -1e9;
    if(j == m - 1) return mine[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int right = mine[i][j] + Collect(mine, i, j + 1, dp, n, m);
    int rightUp = mine[i][j] + Collect(mine, i - 1, j + 1, dp, n, m);
    int rightDown = mine[i][j] + Collect(mine, i + 1, j + 1, dp, n, m);
    return dp[i][j] = max({right, rightUp, rightDown});
}

int maxGoldCollected(vector<vector<int>> mine, int n, int m) {
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int maxGold = 0;
    for(int i = 0; i <= n - 1; i++) maxGold = max(Collect(mine, i, 0, dp, n, m), maxGold);
    return maxGold;
}

/*-------------------------------
Method: Tabulation  
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
----------------------------------*/

int Collect(vector<vector<int>> &mine, int i, int j, vector<vector<int>> &dp, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m) return -1e9;
    if(j == m - 1) return mine[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int right = mine[i][j] + Collect(mine, i, j + 1, dp, n, m);
    int rightUp = mine[i][j] + Collect(mine, i - 1, j + 1, dp, n, m);
    int rightDown = mine[i][j] + Collect(mine, i + 1, j + 1, dp, n, m);
    return dp[i][j] = max({right, rightUp, rightDown});
}

int maxGoldCollected(vector<vector<int>> mine, int n, int m) {
    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int i = 0; i < n; i++) dp[i][m - 1] = mine[i][m - 1];
    for(int j = m - 2; j >= 0; j--){
        for(int i = 0; i < n; i++){
            int right = dp[i][j + 1];
            int rightUp = (i > 0) ? dp[i - 1][j + 1] : -1e9;
            int rightDown = (i < n - 1) ? dp[i + 1][j + 1] : -1e9;
            dp[i][j] = mine[i][j] + max({right, rightUp, rightDown});
        }
    }

    int maxGold = 0;
    for(int i = 0; i < n; i++) maxGold = max(dp[i][0], maxGold);
    return maxGold;
}

/*
Question Link: https://www.naukri.com/code360/problems/gold-mine-problem_799363
Author: M.R.Naganathan
*/
