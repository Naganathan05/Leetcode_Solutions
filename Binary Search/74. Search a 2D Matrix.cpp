/*--------------------------------
  Time Complexity: O(logn + logm)
  Space Complexity: O(1)
------------------------------------*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rowLow = 0, rowHigh = matrix.size() - 1;

        while(rowLow <= rowHigh){
            int rowMid = rowLow + (rowHigh - rowLow) / 2;
            if(matrix[rowMid][0] == target) return true;

            if(matrix[rowMid][0] > target) rowHigh = rowMid - 1;
            else rowLow = rowMid + 1;
        }

        if (rowLow >= matrix.size()) rowLow = matrix.size() - 1;
        if (rowLow > 0 && matrix[rowLow][0] > target) rowLow -= 1;

        int low = 0, high = matrix[0].size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(matrix[rowLow][mid] == target) return true;

            if(matrix[rowLow][mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};

/*
Question Link: https://leetcode.com/problems/search-a-2d-matrix/
Author: M.R.Naganathan
*/
