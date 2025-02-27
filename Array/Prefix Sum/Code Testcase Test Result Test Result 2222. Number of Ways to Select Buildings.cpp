/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    /*
    Index 0 -> Number of seq's of length 1 ending with a 0
    Index 1 -> Number of seq's of length 2 ending with a 0
    Index 2 -> Number of seq's of length 1 ending with a 1
    Index 3 -> Number of seq's of length 2 ending with a 1
    */
    long long numberOfWays(string s) {
        vector<long long> endingCounts(4, 0);
        long long totalWays = 0;
        for(char c : s){
            if(c == '0'){
                totalWays += (endingCounts[3]);
                endingCounts[0] += 1;
                endingCounts[1] += (endingCounts[2]);
            }
            else {
                totalWays += (endingCounts[1]);
                endingCounts[2] += 1;
                endingCounts[3] += (endingCounts[0]);
            }
        }
        return totalWays;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-ways-to-select-buildings/
Author: M.R.Naganathan
*/
