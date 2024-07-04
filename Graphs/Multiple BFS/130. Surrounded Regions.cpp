/*-----------------------------------
Method: BFS at Every Border Cell
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
--------------------------------------*/

class Solution {
public:
    void BFS(vector<vector<char>> &board, int start_i, int start_j, vector<vector<bool>> &visited){
        queue<pair<int, int>> fifo;
        fifo.push({start_i, start_j});
        visited[start_i][start_j] = true;
        while(!fifo.empty()){
            int x = fifo.front().first;
            int y = fifo.front().second;
            fifo.pop();

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && !visited[newX][newY] && board[newX][newY] == 'O'){
                    visited[newX][newY] = true;
                    fifo.push({newX, newY});
                }
            }
        }
        return;
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));

        for(int i = 0; i <= board.size() - 1; i++){
            for(int j = 0; j <= board[i].size() - 1; j++){
                if((i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1) && board[i][j] == 'O') BFS(board, i, j, visited);
            }
        }

        for(int i = 0; i <= visited.size() - 1; i++){
            for(int j = 0; j <= visited[i].size() - 1; j++){
                if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
        return;
    }
};

/*
Question Link: https://leetcode.com/problems/surrounded-regions/
Author: M.R.Naganathan
*/
