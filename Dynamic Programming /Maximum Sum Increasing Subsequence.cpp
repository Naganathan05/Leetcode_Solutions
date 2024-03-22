/*-----------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
-------------------------------------------*/

int Sum(vector<int> &rack, int i, int prev, vector<vector<int>> &dp){
	if(i == rack.size()) return 0;

	if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

	if(prev == -1 || rack[i] > rack[prev]) dp[i][prev + 1] = max(rack[i] + Sum(rack, i + 1, i, dp), Sum(rack, i + 1, prev, dp));
	else dp[i][prev + 1] = Sum(rack, i + 1, prev, dp);
	return dp[i][prev + 1];
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n, vector<int> (n + 1, -1));
	return Sum(rack, 0, -1, dp);
}

/*
Question Link: https://www.codingninjas.com/studio/problems/1112624
Author: M.R.Naganathan
*/
