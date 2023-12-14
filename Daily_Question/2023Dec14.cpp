 // --------------------------------
 // Time Complexity: O(m * n)
 // Space Complexity: O(m + n)
 // --------------------------------

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onesRow;
        vector<int> onesCol;
        int row_cnt = 0;

        for(int i = 0; i <= grid.size() - 1; i++){
            cnt = 0;
            for(int j = 0; j <= grid[0].size() - 1; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
            onesRow.push_back(cnt);
        }

        for(int j = 0; j <= grid[0].size() - 1; j++){
            cnt = 0;
            for(int i = 0; i <= grid.size() - 1; i++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
            onesCol.push_back(cnt);
        }

        for(int i = 0; i <= grid.size() - 1; i++){
            for(int j = 0; j <= grid[0].size() - 1; j++){
                grid[i][j] = onesRow[i] + onesCol[j] - (grid.size() - onesRow[i]) - (grid[0].size() - onesCol[j]);
            }
        }

        return grid;
    }
};

// Question Link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/?envType=daily-question&envId=2023-12-14

// Author: M.R.Naganathan
