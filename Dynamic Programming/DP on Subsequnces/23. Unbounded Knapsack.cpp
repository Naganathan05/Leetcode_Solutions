/*-----------------------------------------
Method 1: Memoization
  Time Complexity: O(n * w)
  Space Complexity: O(n * w) + O(max(n, w))
-------------------------------------------*/

int unbounded(vector<int> &profit, vector<int> &weight, int i, int w, vector<vector<int>> &dp){
    if(i == 0){
        int wi = w, tot_amt = 0;
        while(wi >= weight[0]){
            tot_amt += profit[0];
            wi -= weight[0];
        }
        return tot_amt;
    }

    if(w == 0) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    int onetake = 0, noTake = 0, mulTake = 0;
    noTake = unbounded(profit, weight, i - 1, w, dp);
    if(weight[i] <= w) onetake = profit[i] + unbounded(profit, weight, i - 1, w - weight[i], dp);
    if(weight[i] <= w) mulTake = profit[i] + unbounded(profit, weight, i, w - weight[i], dp);
    return dp[i][w] = max(onetake, max(noTake, mulTake));
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w + 1, -1));
    return unbounded(profit, weight, n - 1, w, dp);
}

/*--------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * w)
  Space Complexity: O(n * w)
----------------------------------------------*/

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w + 1, 0));
    for(int i = 1; i <= w; i++){
        int wi = i, tot_amt = 0;
        while(wi >= weight[0]){
            tot_amt += profit[0];
            wi -= weight[0];
        }
        dp[0][i] = tot_amt;
    }

    for(int i = 1; i <= n - 1; i++){
        for(int wi = 1; wi <= w; wi++){
            int oneTake = 0, noTake = 0, mulTake = 0;
            noTake = dp[i - 1][wi];
            if(weight[i] <= wi) oneTake = profit[i] + dp[i - 1][wi - weight[i]];
            if(weight[i] <= wi) mulTake = profit[i] + dp[i][wi - weight[i]];
            dp[i][wi] = max(oneTake, max(noTake, mulTake));
        }
    }
    return dp[n - 1][w];
}

/*----------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * w)
  Space Complexity: O(w)
------------------------------------------------*/

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> curr(w + 1, 0), prev(w + 1, 0);
    for(int i = 1; i <= w; i++){
        int wi = i, tot_amt = 0;
        while(wi >= weight[0]){
            tot_amt += profit[0];
            wi -= weight[0];
        }
        curr[i] = tot_amt;
    }

    for(int i = 1; i <= n - 1; i++){
        prev = curr;
        for(int wi = 1; wi <= w; wi++){
            int oneTake = 0, noTake = 0, mulTake = 0;
            noTake = prev[wi];
            if(weight[i] <= wi) oneTake = profit[i] + prev[wi - weight[i]];
            if(weight[i] <= wi) mulTake = profit[i] + curr[wi - weight[i]];
            curr[wi] = max(oneTake, max(noTake, mulTake));
        }
    }
    return curr[w];
}

/*
Question Link: https://www.naukri.com/code360/problems/unbounded-knapsack_1215029
Author: M.R.Naganathan
*/
