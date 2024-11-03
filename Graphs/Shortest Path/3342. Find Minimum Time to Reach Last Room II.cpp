/*----------------------------------------
  Time Complexity: O(n * m * log(n * m))
  Space Complexity: O(n * m)
------------------------------------------*/

class Solution {
public:
    struct movementInfo {
        int currentTime;
        int currentMove;
        int currX;
        int currY;

        bool operator>(const movementInfo& other) const {
            return currentTime > other.currentTime;
        }
    };

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        priority_queue<movementInfo, vector<movementInfo>, greater<movementInfo>> minHeap;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        minHeap.push(movementInfo(0, 1, 0, 0));

        while (!minHeap.empty()) {
            auto [currentTime, currentMove, currX, currY] = minHeap.top();
            minHeap.pop();

            if (currX == n - 1 && currY == m - 1) return currentTime;

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto &dir : directions) {
                int newX = currX + dir.first;
                int newY = currY + dir.second;

                if (newX < 0 || newY < 0 || newX >= n || newY >= m) continue;

                int arrivalTime = max(moveTime[newX][newY], currentTime);
                int newTime = arrivalTime + currentMove;
                int newMove = (currentMove == 1) ? 2 : 1;

                if (newTime < dist[newX][newY]) {
                    dist[newX][newY] = newTime;
                    minHeap.push(movementInfo(newTime, newMove, newX, newY));
                }
            }
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/
Author: M.R.Naganathan
*/
