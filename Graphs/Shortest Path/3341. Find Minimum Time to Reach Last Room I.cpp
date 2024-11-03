/*----------------------------------------
  Time Complexity: O(n * m * log(n * m))
  Space Complexity: O(n * m)
-------------------------------------------*/

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;

        while(!minHeap.empty()){
            auto [currentTime, coordinates] = minHeap.top();
            auto [currX, currY] = coordinates;
            minHeap.pop();

            if(currX == n - 1 && currY == m - 1) return currentTime;

            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for(auto &dir : directions){
                int newX = currX + dir.first;
                int newY = currY + dir.second;
                
                if(newX < 0 || newY < 0 || newX >= n || newY >= m) continue;
                
                int waitTime = max(currentTime, moveTime[newX][newY]);
                int newTime = waitTime + 1;

                if(newTime < dist[newX][newY]){
                    dist[newX][newY] = newTime;
                    minHeap.push({newTime, {newX, newY}});
                }
            }
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
Author: M.R.Naganathan
*/
