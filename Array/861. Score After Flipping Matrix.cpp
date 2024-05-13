/*---------------------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(1)
------------------------------------------*/

class Solution {
public:
    void toggleRow(vector<vector<int>>& grid,int row){
        for(int j=0;j<grid[0].size();j++){
            if(grid[row][j]==0) grid[row][j]=1;
            else grid[row][j]=0;
        }
    }

    void toggleCol(vector<vector<int>>& grid,int col){
        for(int j=0;j<grid.size();j++){
            if(grid[j][col]==0) grid[j][col]=1;
            else grid[j][col]=0;
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1) continue;
            toggleRow(grid,i);
        }
        for(int j=1;j<grid[0].size();j++){
            int ones=0;
            for(int i=0;i<grid.size();i++){
                if (grid[i][j]==1) ones++;
            }
            if(ones * 2 < grid.size()) toggleCol(grid,j);
        }
        int sum=0;
        for(int i=0;i<grid.size();i++){
            int k=grid[0].size()-1;
            int s=0;
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<" ";
                s+=pow(2,k)*grid[i][j];
                k--;
            }
            cout<<endl;
            sum+=s;
        }

        return sum;
    }
};

/*
Question Link: https://leetcode.com/problems/score-after-flipping-matrix/
Author: M.R.Naganathan
*/
