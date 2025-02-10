/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    long long minimumSteps(string s) {
        int numBlackBalls = 0;
        long long numSteps = 0;
        for(char ball : s){
            numBlackBalls += (ball == '1');
            if(ball == '0') numSteps += (numBlackBalls);
        }
        return numSteps;
    }
};

/*
Question Link: https://leetcode.com/problems/separate-black-and-white-balls/
Author: M.R.Naganathan
*/
