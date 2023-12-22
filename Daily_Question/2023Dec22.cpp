/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    int maxScore(string s) {
        int tot_one = 0;
        for(int i = 0; i <= s.length() - 1; i++){
            if(s[i] == '1'){
                tot_one++;
            }
        }

        int curr_zero = 0, curr_one = 0, max_score = INT_MIN;

        for(int i = 0; i <= s.length() - 2; i++){
            if(s[i] == '0'){
                curr_zero++;
            }
            else{
                curr_one++;
            }

            if(max_score < (curr_zero + (tot_one - curr_one))){
                max_score = curr_zero + (tot_one - curr_one);
            }
        }

        return max_score;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/?envType=daily-question&envId=2023-12-22
Author: M.R.Naganathan
*/
