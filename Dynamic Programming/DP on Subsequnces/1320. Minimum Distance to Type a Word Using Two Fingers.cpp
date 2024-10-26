/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    int Type(string &word, int i, char firstFinger, char secondFinger, vector<vector<int>> &dist, vector<vector<vector<int>>> &dp) {
        if (i == word.length()) return 0;
        
        int j = firstFinger == '!' ? 26 : firstFinger - 'A';
        int k = secondFinger == '!' ? 26 : secondFinger - 'A';
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int target = word[i] - 'A';
        
        int firstFingerMove = (firstFinger == '!' ? 0 : dist[j][target]) + Type(word, i + 1, word[i], secondFinger, dist, dp);
        int secondFingerMove = (secondFinger == '!' ? 0 : dist[k][target]) + Type(word, i + 1, firstFinger, word[i], dist, dp);
        
        return dp[i][j][k] = min(firstFingerMove, secondFingerMove);
    }

    int minimumDistance(string word) {
        vector<vector<int>> dist(27, vector<int>(27, 0));
        for (int i = 0; i < 26; i++) {
            int x1 = i / 6, y1 = i % 6;
            for (int j = 0; j < 26; j++) {
                int x2 = j / 6, y2 = j % 6;
                dist[i][j] = abs(x1 - x2) + abs(y1 - y2);
            }
        }

        vector<vector<vector<int>>> dp(word.length(), vector<vector<int>>(27, vector<int>(27, -1)));
        return Type(word, 0, '!', '!', dist, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
Author: M.R.Naganathan
*/
