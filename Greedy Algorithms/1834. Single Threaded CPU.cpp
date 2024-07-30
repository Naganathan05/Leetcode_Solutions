/*---------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------------*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < tasks.size(); i++) tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end());

        vector<int> order;
        long long currentTime = 0, i = 0;

        while (!pq.empty() || i < tasks.size()) {
            if (pq.empty() && currentTime < tasks[i][0]) currentTime = tasks[i][0];

            while (i < tasks.size() && tasks[i][0] <= currentTime) {
                pq.push({tasks[i][1], tasks[i][2]});
                i += 1;
            }

            if (!pq.empty()) {
                auto [processingTime, taskId] = pq.top();
                pq.pop();
                currentTime += processingTime;
                order.push_back(taskId);
            }
        }
        return order;
    }
};

/*
Question Link: https://leetcode.com/problems/single-threaded-cpu/
Author: M.R.Naganathan
*/
