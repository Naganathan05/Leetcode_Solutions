/*--------------------------------------
Method: Dijkstra's Algorithm
  Time Complexity: O(m * n log(m * n))
  Space Complexity: O(m * n)
-----------------------------------------*/

class Solution {
public:
    int minCost(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> minHeap;
        
        minHeap.push({0, {0, 0}});
        
        vector<int> deltaX = {0, 0, 1, -1};
        vector<int> deltaY = {1, -1, 0, 0};
        vector<vector<int>> minDist(rows, vector<int>(cols, INT_MAX));
        
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            
            int currX = curr.second.first;
            int currY = curr.second.second;
            int cost = curr.first;
            
            if (currX == rows - 1 && currY == cols - 1) {
                return cost;
            }
            
            int direction = matrix[currX][currY];
            for (int dir = 1; dir <= 4; ++dir) {
                int newX = currX + deltaX[dir - 1];
                int newY = currY + deltaY[dir - 1];
                
                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                    int newCost = cost + (direction != dir);
                    
                    if (newCost < minDist[newX][newY]) {
                        minDist[newX][newY] = newCost;
                        minHeap.push({newCost, {newX, newY}});
                    }
                }
            }
        }
        
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
Author: M.R.Naganathan
*/
