/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
------------------------------*/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size(), lbl = 1;
        vector<pair<int, int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[lbl++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }

        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> fifo;
        fifo.push({0, 1});
        visited[1] = true;
        while (!fifo.empty()) {
            int currSteps = fifo.front().first;
            int curr = fifo.front().second;
            fifo.pop();

            if(curr == n * n) return currSteps;

            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if(!visited[destination]){
                    visited[destination] = true;
                    fifo.push({currSteps + 1, destination});
                }
            }
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/snakes-and-ladders/
Author: M.R.Naganathan
*/
