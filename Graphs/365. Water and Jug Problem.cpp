/*-----------------------------
  Time Complexity: O(x * y)
  Space Complexity: O(x * y)
------------------------------*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        vector<vector<bool>> visited(x + 1, vector<bool> (y + 1, false));
        queue<pair<int, int>> fifo;

        fifo.push({0, 0});
        visited[0][0] = true;

        while(!fifo.empty()) {
            auto [firstJug, secondJug] = fifo.front();
            fifo.pop();

            if(firstJug + secondJug == target) return true;

            // Fill Jug 1
            if(firstJug < x && !visited[x][secondJug]) {
                fifo.push({x, secondJug});
                visited[x][secondJug] = true;
            }

            // Fill Jug 2
            if(secondJug < y && !visited[firstJug][y]) {
                fifo.push({firstJug, y});
                visited[firstJug][y] = true;
            }

            // Empty Jug 1
            if(!visited[0][secondJug]) {
                fifo.push({0, secondJug});
                visited[0][secondJug] = true;
            }

            // Empty Jug 2
            if(!visited[firstJug][0]) {
                fifo.push({firstJug, 0});
                visited[firstJug][0] = true;
            }

            // Pour Jug1 to Jug2
            int newSecondJug = min(y, (secondJug + firstJug));
            int newFirstJug = firstJug - (newSecondJug - secondJug);
            if(!visited[newFirstJug][newSecondJug]) {
                fifo.push({newFirstJug, newSecondJug});
                visited[newFirstJug][newSecondJug] = true;
            }

            // Pour Jug2 to Jug1
            newFirstJug = min(x, (firstJug + secondJug));
            newSecondJug = secondJug - (newFirstJug - firstJug);
            if(!visited[newFirstJug][newSecondJug]) {
                fifo.push({newFirstJug, newSecondJug});
                visited[newFirstJug][newSecondJug] = true;
            }
        }
        return false;
    }
};

/*
Question Link: https://leetcode.com/problems/water-and-jug-problem/
Author: M.R.Naganathan
*/
