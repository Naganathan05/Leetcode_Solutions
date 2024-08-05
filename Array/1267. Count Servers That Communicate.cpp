/*---------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(n + m)
------------------------------*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<bool> row(n, false);
        vector<bool> col(m, false);

        for(int i = 0; i <= n - 1; i++){
            int numServers = 0;
            bool connect = false;
            for(int j = 0; j <= m - 1; j++){
                if(grid[i][j] == 1) numServers += 1;
                if(numServers == 2){
                    connect = true;
                    break;
                }
            }
            row[i] = connect;
        }

        for(int j = 0; j <= m - 1; j++){
            int numServers = 0;
            bool connect = false;
            for(int i = 0; i <= n - 1; i++){
                if(grid[i][j] == 1) numServers += 1;
                if(numServers == 2){
                    connect = true;
                    break;
                }
            }
            col[j] = connect;
        }

        int numServers = 0;
        for(int i = 0; i <= n - 1; i++){
            for(int j = 0; j <= m - 1; j++){
                if(grid[i][j] == 1 && (col[j] || row[i])) numServers += 1;
            }
        }
        return numServers;
    }
};

/*
Question Link: https://leetcode.com/problems/count-servers-that-communicate/
Author: M.R.Naganathan
*/
