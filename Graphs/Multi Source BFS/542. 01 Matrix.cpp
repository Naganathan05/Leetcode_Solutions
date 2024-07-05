/*-----------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-------------------------------*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, pair<int, int>>> fifo;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0){
                    fifo.push({0, {i, j}});
                    ans[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!fifo.empty()){
            int x = fifo.front().second.first;
            int y = fifo.front().second.second;
            int dist = fifo.front().first; 
            fifo.pop();

            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols){
                    if(ans[newX][newY] > dist + 1){
                        ans[newX][newY] = dist + 1;
                        fifo.push({dist + 1, {newX, newY}});
                    }
                }
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/01-matrix/
Author: M.R.Naganathan
*/
