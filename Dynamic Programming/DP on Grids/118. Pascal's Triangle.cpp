/*----------------------------------------
Method: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
------------------------------------------*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        vector<int> prevRow;
        for(int i = 0; i <= numRows - 1; i++){
            vector<int> currRow(i + 1, 1);
            for(int j = 1; j < i; j++){
                currRow[j] = prevRow[j] + prevRow[j - 1];
            }
            dp.push_back(currRow);
            prevRow = currRow;
        }
        return dp;
    }
};

/*
Question Link: https://leetcode.com/problems/pascals-triangle/
Author: M.R.Naganathan
*/
