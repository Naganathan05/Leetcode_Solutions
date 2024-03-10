/*-----------------------------------------------
Method 1: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(m + n)
--------------------------------------------------*/

string recursiveFunction(string text1, string text2, int i, int j, vector<vector<string>> &dp){
    if (i < 0 || j < 0) return "";

    if(dp[i][j] != "") return dp[i][j];

    if(text1[i] == text2[j]) return dp[i][j] = recursiveFunction(text1, text2, i - 1, j - 1, dp) + text1[i];

    string str1 = recursiveFunction(text1, text2, i - 1, j, dp);
    string str2 = recursiveFunction(text1, text2, i, j - 1, dp);
    if(str1.length() >= str2.length()) dp[i][j] = str1;
    else dp[i][j] = str2;
    return dp[i][j];
}
string findLCS(int n, int m,string &s1, string &s2){
	  vector<vector<string>> dp(n, vector<string> (m, ""));
    return recursiveFunction(s1, s2, n - 1, m - 1, dp);
}

/*------------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
--------------------------------------------------------*/

string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<string>> dp(n, vector<string> (m, ""));
    for(int i = 0; i <= n - 1; i++){
        for(int j = 0; j <= m - 1; j++){
            if(s1[i] == s2[j]){
                if(i - 1 >= 0 && j - 1 >= 0) dp[i][j] = dp[i - 1][j - 1] + s1[i];
                else dp[i][j] = s1[i];
            }
            else{
                string str1 = "", str2 = "";
                if(i - 1 >= 0) str1 = dp[i - 1][j];
                if(j - 1 >= 0) str2 = dp[i][j - 1];
                if(str1.length() >= str2.length()) dp[i][j] = str1;
                else dp[i][j] = str2;
            }
        }
    }
    return dp[n - 1][m - 1];
}

/*---------------------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(m * n)
  Space Complexity: O(m)
-----------------------------------------------------------*/

string findLCS(int n, int m,string &s1, string &s2){
	vector<string> prev(m + 1, ""), curr(m + 1, "");
    for(int i = 0; i <= n - 1; i++){
        prev = curr;
        for(int j = 0; j <= m - 1; j++){
            if(s1[i] == s2[j]){
                if(i - 1 >= 0 && j - 1 >= 0) curr[j] = prev[j - 1] + s1[i];
                else curr[j] = s1[i];
            }
            else{
                string str1 = "", str2 = "";
                if(i - 1 >= 0) str1 = prev[j];
                if(j - 1 >= 0) str2 = curr[j - 1];
                if(str1.length() >= str2.length()) curr[j] = str1;
                else curr[j] = str2;
            }
        }
    }
    return curr[m - 1];
}

/*
Question Link: https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=PROBLEM
Author: M.R.Naganathan
*/
