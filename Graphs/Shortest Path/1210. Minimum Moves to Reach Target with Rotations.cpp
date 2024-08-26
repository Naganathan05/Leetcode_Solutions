/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
------------------------------*/

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<pair<pair<int, int>, pair<int, int>>> visited;
        queue<vector<int>> fifo;
        fifo.push({0, 0, 0, 0, 1});
        visited.insert({{0, 0}, {0, 1}});
        int currSteps = 0;

        while (!fifo.empty()) {
            int size = fifo.size();
            for (int sz = 0; sz < size; sz++) {
                auto state = fifo.front();
                fifo.pop();

                int currDir = state[0];
                int tailX = state[1];
                int tailY = state[2];
                int headX = state[3];
                int headY = state[4];

                if (tailX == n - 1 && tailY == m - 2 && headX == n - 1 && headY == m - 1) return currSteps;

                if (currDir == 0) {
                    if (headY + 1 < m && grid[tailX][headY + 1] == 0 && grid[headX][headY + 1] == 0 &&
                        visited.find({{tailX, tailY + 1}, {headX, headY + 1}}) == visited.end()) {
                        visited.insert({{tailX, tailY + 1}, {headX, headY + 1}});
                        fifo.push({0, tailX, tailY + 1, headX, headY + 1});
                    }

                    if (headX + 1 < n && grid[headX + 1][tailY] == 0 && grid[headX + 1][headY] == 0 &&
                        visited.find({{tailX + 1, tailY}, {headX + 1, headY}}) == visited.end()) {
                        visited.insert({{tailX + 1, tailY}, {headX + 1, headY}});
                        fifo.push({0, tailX + 1, tailY, headX + 1, headY});
                    }

                    if (headX + 1 < n && grid[headX + 1][headY] == 0 && grid[headX + 1][tailY] == 0 &&
                        visited.find({{tailX, tailY}, {tailX + 1, tailY}}) == visited.end()) {
                        visited.insert({{tailX, tailY}, {tailX + 1, tailY}});
                        fifo.push({1, tailX, tailY, tailX + 1, tailY});
                    }
                }
                else {
                    if (headX + 1 < n && grid[headX + 1][tailY] == 0 && grid[headX + 1][headY] == 0 &&
                        visited.find({{tailX + 1, tailY}, {headX + 1, headY}}) == visited.end()) {
                        visited.insert({{tailX + 1, tailY}, {headX + 1, headY}});
                        fifo.push({1, tailX + 1, tailY, headX + 1, headY});
                    }

                    if (headY + 1 < m && grid[tailX][headY + 1] == 0 && grid[headX][headY + 1] == 0 &&
                        visited.find({{tailX, tailY + 1}, {headX, headY + 1}}) == visited.end()) {
                        visited.insert({{tailX, tailY + 1}, {headX, headY + 1}});
                        fifo.push({1, tailX, tailY + 1, headX, headY + 1});
                    }

                    if (headY + 1 < m && grid[headX][headY + 1] == 0 && grid[tailX][headY + 1] == 0 &&
                        visited.find({{tailX, tailY}, {tailX, tailY + 1}}) == visited.end()) {
                        visited.insert({{tailX, tailY}, {tailX, tailY + 1}});
                        fifo.push({0, tailX, tailY, tailX, tailY + 1});
                    }
                }
            }
            currSteps += 1;
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
Author: M.R.Naganathan
*/
