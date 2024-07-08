/*--------------------------------
  Time Complexity: O(V + 2E)
  Space Complexity: O(V + E)
----------------------------------*/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        for(int i = 0; i < n; i++){
            if(i != headID) adjList[manager[i]].push_back(i);
        }

        queue<pair<int, int>> fifo;
        fifo.push({headID, 0});
        int maxTime = 0;

        while(!fifo.empty()){
            auto [node, time] = fifo.front();
            fifo.pop();

            for(int neighbour : adjList[node]){
                fifo.push({neighbour, time + informTime[node]});
                maxTime = max(maxTime, time + informTime[node]);
            }
        }
        return maxTime;
    }
};

/*
Question Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/
Author: M.R.Naganathan
*/
