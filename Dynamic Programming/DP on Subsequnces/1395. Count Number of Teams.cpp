/*-------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
---------------------------------------*/

class Solution {
public:
    int f(int ind, int last, int sz, vector<int>& rating, bool flag, vector<vector<vector<int>>> &dp) {
        int n = rating.size();
        if (sz == 0) return 1;
        if (ind == n) return 0;
        if (dp[ind][last+1][sz] != -1)  return dp[ind][last+1][sz];

        int ways = f(ind + 1, last, sz, rating, flag, dp);
        if (flag==1 && (last == -1 || rating[ind] > rating[last])) ways += f(ind + 1, ind, sz - 1, rating, flag, dp);
        if(flag==0 && (last == -1 || rating[ind] < rating[last]))ways += f(ind+1, ind, sz-1, rating, flag, dp);
        return dp[ind][last+1][sz] = ways;
    }

    int numTeams(vector<int>& rating) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = rating.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n + 1, vector<int> (4, -1)));
        bool flag = 0;
        int inc = f(0, -1, 3, rating, flag, dp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= n; j++){
                for(int k = 0; k <= 3; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        flag = !flag;
        int dec = f(0, -1, 3, rating, flag, dp);
        return inc + dec;
    }
};

/*--------------------------------------
Solution's Code
    Time Complexity: O(n * n)
    Space Complexity: O(n)
-----------------------------------------*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        vector<vector<int>> increasingCache(n, vector<int>(4, -1));
        vector<vector<int>> decreasingCache(n, vector<int>(4, -1));

        // Calculate total teams by considering each soldier as a starting point
        for (int startIndex = 0; startIndex < n; startIndex++) {
            teams +=
                countIncreasingTeams(rating, startIndex, 1, increasingCache) +
                countDecreasingTeams(rating, startIndex, 1, decreasingCache);
        }

        return teams;
    }

private:
    int countIncreasingTeams(const vector<int>& rating, int currentIndex,
                             int teamSize,
                             vector<vector<int>>& increasingCache) {
        int n = rating.size();

        // Base case: reached end of array
        if (currentIndex == n) return 0;

        // Base case: found a valid team of size 3
        if (teamSize == 3) return 1;

        // Return cached result if available
        if (increasingCache[currentIndex][teamSize] != -1) {
            return increasingCache[currentIndex][teamSize];
        }

        int validTeams = 0;

        // Recursively count teams with increasing ratings
        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++) {
            if (rating[nextIndex] > rating[currentIndex]) {
                validTeams += countIncreasingTeams(
                    rating, nextIndex, teamSize + 1, increasingCache);
            }
        }

        // Cache and return the result
        return increasingCache[currentIndex][teamSize] = validTeams;
    }

    int countDecreasingTeams(const vector<int>& rating, int currentIndex,
                             int teamSize,
                             vector<vector<int>>& decreasingCache) {
        int n = rating.size();

        // Base case: reached end of array
        if (currentIndex == n) return 0;

        // Base case: found a valid team of size 3
        if (teamSize == 3) return 1;

        // Return cached result if available
        if (decreasingCache[currentIndex][teamSize] != -1) {
            return decreasingCache[currentIndex][teamSize];
        }

        int validTeams = 0;

        // Recursively count teams with decreasing ratings
        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++) {
            if (rating[nextIndex] < rating[currentIndex]) {
                validTeams += countDecreasingTeams(
                    rating, nextIndex, teamSize + 1, decreasingCache);
            }
        }

        // Cache and return the result
        return decreasingCache[currentIndex][teamSize] = validTeams;
    }
};

/*
Question Link: https://leetcode.com/problems/count-number-of-teams/description/
Author: M.R.Naganathan
*/
