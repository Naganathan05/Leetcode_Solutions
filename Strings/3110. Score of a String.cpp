/*----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------*/

class Solution {
public:
    int scoreOfString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int score = 0;
        for(int i = 0; i < s.length() - 1; i++) score += abs((int)(s[i]) - (int)(s[i + 1]));
        return score;
    }
};

/*
Question Link: https://leetcode.com/problems/score-of-a-string/
Author: M.R.Naganathan
*/
