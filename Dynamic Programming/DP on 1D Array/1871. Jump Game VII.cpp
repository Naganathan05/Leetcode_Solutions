/*-------------------------------------------
Method: Memoization => MLE :(
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
---------------------------------------------*/

class Solution {
public:
    bool Reach(string s, int i, int minJump, int maxJump, vector<int> &dp){
        if(s[i] != '0') return false;
        if(i == s.length() - 1) return true;
        if(dp[i] != -1) return dp[i];

        bool result = false;
        for(int jump = minJump; jump <= maxJump; jump++){
            if(i + jump < s.length()) result |= (Reach(s, i + jump, minJump, maxJump, dp));
        }
        return dp[i] = result; 
    }

    bool canReach(string s, int minJump, int maxJump) {
        vector<int> dp(s.length(), -1);
        return Reach(s, 0, minJump, maxJump, dp);
    }
};

/*-----------------------------------------------
Method: Tabulation => TLE :(
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------------------------------*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(s.length(), false);
        if(s[s.length() - 1] == '0') dp[s.length() - 1] = true;
        
        for(int i = s.length() - 2; i >= 0; i--){
            bool result = false;
            for(int jump = minJump; jump <= maxJump; jump++){
                if(i + jump < s.length() && s[i + jump] == '0') result |= dp[i + jump];
            }
            dp[i] = result; 
        }
        return dp[0];
    }
};

/*
Question Link: https://leetcode.com/problems/jump-game-vii/
Author: M.R.Naganathan
*/
