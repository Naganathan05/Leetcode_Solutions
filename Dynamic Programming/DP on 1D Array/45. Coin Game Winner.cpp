/*-----------------------------------
  Time Complexity: O(n)  
  Space Complexity: O(n)
-------------------------------------*/

int play(int n, int a, int b, vector<int> &dp){
	if(n == 1 || n == a || n == b) return true;
	if(dp[n] != -1) return dp[n];

	if(n >= 1 && !play(n - 1, a, b, dp)) return dp[n] = 1;
	if(n >= a && !play(n - a, a, b, dp)) return dp[n] = 1;
	if(n >= b && !play(n - b, a, b, dp)) return dp[n] = 1;
	return dp[n] = 0;
}

int coinGameWinner(int n, int a, int b)
{
	vector<int> dp(n + 1, -1);
	return play(n, a, b, dp);
}

/*
Question Link: https://www.naukri.com/code360/problems/coin-game-winner-where-every-player-has-three-choices_1229492
Author: M.R.Naganathan
*/
