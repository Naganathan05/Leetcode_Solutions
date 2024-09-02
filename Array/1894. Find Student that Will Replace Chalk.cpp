/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------*/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long totSum = 0;
        for(int i : chalk) totSum += i;
        k = (k % totSum);

        for(int i = 0; i <= chalk.size() - 1; i++){
            if(k - chalk[i] < 0) return i;
            k -= chalk[i]; 
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
Author: M.R.Naganathan
*/
