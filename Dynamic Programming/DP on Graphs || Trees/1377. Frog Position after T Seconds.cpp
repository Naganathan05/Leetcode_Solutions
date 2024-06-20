/*-------------------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------------------------*/

class Solution {
public:
    double frog(vector<vector<int>> &adjList, int parentVertex, int currVertex, int t, int target, vector<vector<double>> &dp){
        if (currVertex == target) {
            if (t == 0 || adjList[currVertex].size() == (parentVertex == -1 ? 0 : 1)) return 1.0;
            else return 0.0;
        }
        if(t == 0) return 0.0;
        if(dp[currVertex][t] != -1) return dp[currVertex][t];

        int maxJump = 0;
        double totalProb = 0.0;
        for(int neighbour : adjList[currVertex]){
            if(neighbour != parentVertex) maxJump += 1;
        }
        for(int neighbour : adjList[currVertex]){
            if(neighbour != parentVertex) totalProb += (1.0 / maxJump) * frog(adjList, currVertex, neighbour, t - 1, target, dp);
        }
        return dp[currVertex][t] = totalProb;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n == 1) return 1.0;
        vector<vector<int>> adjList(n + 1);
        vector<vector<double>> dp(n + 1, vector<double>(t + 1,  -1.0));
        for(int i = 0; i <= edges.size() - 1; i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        return frog(adjList, -1, 1, t, target, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/frog-position-after-t-seconds/
Author: M.R.Naganathan
*/
