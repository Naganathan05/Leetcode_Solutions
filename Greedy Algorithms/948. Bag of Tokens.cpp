/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int currScore = 0, maxScore = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;

        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                currScore += 1;
                i += 1;
            } 
            else if (currScore > 0) {
                power += tokens[j];
                currScore -= 1;
                j -= 1;
            }
            else break;
            maxScore = max(maxScore, currScore);
        }
        return maxScore;
    }
};

/*
Question Link: https://leetcode.com/problems/bag-of-tokens/
Author: M.R.Naganathan
*/
