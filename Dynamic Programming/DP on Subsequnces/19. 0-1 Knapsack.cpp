/*-----------------------------------------------------
Method: Memoization
  Time Complexity: O(n * w)
  Space Complexity: O(n * w) + O(n)
-------------------------------------------------------*/

int profit(vector<int> values, vector<int> weights, int i, int w, vector<vector<int>> &dp){
	if(w == 0) return 0;
	if(i == 0){
		if(weights[0] <=  w) return values[0];
		return 0;
	}
	if(dp[i][w] != -1) return dp[i][w];

	int Pick = -1e9, noPick;
	noPick = profit(values, weights, i - 1, w, dp);
	if(w >= weights[i]) Pick = values[i] + profit(values, weights, i - 1, w - weights[i], dp);
	return dp[i][w] = max(Pick, noPick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int> (w + 1, -1));
	return profit(values, weights, n - 1, w, dp);
}

/*------------------------------------------------------
Method: Tabulation
  Time Complexity: O(n * w)
  Space Complexity: O(n * w)
--------------------------------------------------------*/

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int> (w + 1, 0));
	for(int i = 0; i <= n - 1; i++) dp[i][0] = 0;
	for(int i = weights[0]; i <= w; i++) dp[0][i] = values[0];

	for(int i = 1; i <= n - 1; i++){
		for(int j = 1; j <= w; j++){
			int Pick = -1e9, noPick;
			noPick = dp[i - 1][j];
			if(j >= weights[i]) Pick = values[i] + dp[i - 1][j - weights[i]];
			dp[i][j] = max(Pick, noPick);
		}
	}
	return dp[n - 1][w];
}

/*---------------------------------------------------------
Method: Space Optimization
  Time Complexity: O(n * w)
  Space Complexity: O(w)
-----------------------------------------------------------*/

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<int> prev(w + 1, 0), curr(w + 1, 0);

	for(int i = weights[0]; i <= w; i++) curr[i] = values[0];

	for(int i = 1; i <= n - 1; i++){
		prev = curr;
		for(int j = 1; j <= w; j++){
			int Pick = -1e9, noPick;
			noPick = prev[j];
			if(j >= weights[i]) Pick = values[i] + prev[j - weights[i]];
			curr[j] = max(Pick, noPick);
		}
	}
	return curr[w];
}

/*
Question Link: https://www.codingninjas.com/studio/problems/0-1-knapsack_920542
Author: M.R.Naganathan
*/
