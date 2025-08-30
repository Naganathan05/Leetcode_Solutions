/*----------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> dist(m, vector<int> (n, -1));

        queue<pair<int, int>> fifo;
        for(int i = 0; i <= m - 1; i++){
            for(int j = 0; j <= n - 1; j++){
                if(isWater[i][j] == 1){
                    dist[i][j] = 0;
                    fifo.push({i, j});
                }
            }
        }

        int currDist = 0;
        while(!fifo.empty()){
            int size = fifo.size();
            for(int sz = 0; sz < size; sz++){ 
                auto [currX, currY] = fifo.front();
                fifo.pop();

                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for(auto &dir : directions){
                    int newX = currX + dir.first;
                    int newY = currY + dir.second;

                    if(newX < 0 || newY < 0 || newX >= m || newY >= n || dist[newX][newY] != -1) continue;
                    dist[newX][newY] = currDist + 1;
                    fifo.push({newX, newY});
                }
            }
            currDist += 1;
        }
        return dist;
    }
};

/*
Question Link: https://leetcode.com/problems/map-of-highest-peak/description/
Author: M.R.Naganathan
*/
