/*-----------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
--------------------------------------*/

class Solution {
public:
    int Team(vector<pair<int, int>> &data, int i, int prev, vector<vector<int>> &dp){
        if(i == data.size()) return 0;

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int Pick = 0, noPick = 0;
        if(prev == -1 || data[prev].first == data[i].first || data[prev].second <= data[i].second) Pick = data[i].second + Team(data, i + 1, i, dp);
        noPick = Team(data, i + 1, prev, dp);
        return dp[i][prev + 1] = max(Pick, noPick);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int numPlayers = scores.size();
        vector<pair<int, int>> data(numPlayers);
        for (int i = 0; i < numPlayers; ++i) data[i] = {ages[i], scores[i]};
        sort(data.begin(), data.end());

        vector<vector<int>> dp(numPlayers, vector<int> (numPlayers, -1));
        int maxScore = Team(data, 0, -1, dp);
        return maxScore;
    }
};

/*-------------------------------------
Method: Tabulation 
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
----------------------------------------*/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int numPlayers = scores.size();
        vector<pair<int, int>> data(numPlayers);
        for (int i = 0; i < numPlayers; ++i) data[i] = {ages[i], scores[i]};
        sort(data.begin(), data.end());

        vector<vector<int>> dp(numPlayers + 1, vector<int> (numPlayers + 1, 0));
        
        for(int i = numPlayers - 1; i >= 0; i--){
            for(int prev = numPlayers - 1; prev >= -1; prev--){
                int Pick = 0, noPick = 0;
                if(prev == -1 || data[prev].first == data[i].first || data[prev].second <= data[i].second) Pick = data[i].second + dp[i + 1][i + 1];
                noPick = dp[i + 1][prev + 1];
                dp[i][prev + 1] = max(Pick, noPick);
            }
        }
        return dp[0][0];
    }
};

/*---------------------------------
Method: Space Optimization 
  Time Complexity: O(n * n)
  Space Complexity: O(2n)
------------------------------------*/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int numPlayers = scores.size();
        vector<pair<int, int>> data(numPlayers);
        for (int i = 0; i < numPlayers; ++i) data[i] = {ages[i], scores[i]};
        sort(data.begin(), data.end());

        vector<int> curr(numPlayers + 1, 0), prev(numPlayers + 1, 0);
        
        for(int i = numPlayers - 1; i >= 0; i--){
            prev = curr;
            for(int prevInd = numPlayers - 1; prevInd >= -1; prevInd--){
                int Pick = 0, noPick = 0;
                if(prevInd == -1 || data[prevInd].first == data[i].first || data[prevInd].second <= data[i].second) Pick = data[i].second + prev[i + 1];
                noPick = prev[prevInd + 1];
                curr[prevInd + 1] = max(Pick, noPick);
            }
        }
        return curr[0];
    }
};

/*
Question Link: https://leetcode.com/problems/best-team-with-no-conflicts/description/
Author: M.R.Naganathan
*/
