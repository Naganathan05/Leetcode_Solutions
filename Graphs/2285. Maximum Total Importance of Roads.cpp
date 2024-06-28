/*------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
--------------------------------*/

class Solution {
public:
    int getIndegree(vector<vector<int>> &adjList, int vertex){
        int indegree = 0;
        for(int i : adjList[vertex]) indegree += 1;
        return indegree;
    }

    long long maximumImportance(int n, vector<vector<int>>& roads) {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<vector<int>> adjList(n);
        for(int i = 0; i <= roads.size() - 1; i++){
            adjList[roads[i][0]].push_back(roads[i][1]);
            adjList[roads[i][1]].push_back(roads[i][0]);
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i <= n - 1; i++){
            int indegree = getIndegree(adjList, i);
            pq.push({indegree, i});
        }
        vector<int> Importance(n, 0);
        int currImportance = n;
        long long totalImportance = 0;
        while(!pq.empty()){
            auto city = pq.top();
            pq.pop();
            int vertex = city.second;
            Importance[vertex] = currImportance;
            currImportance -= 1;
        }
        for(int i = 0; i <= roads.size() - 1; i++){
            totalImportance += (Importance[roads[i][0]] + Importance[roads[i][1]]);
        }
        return totalImportance;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-total-importance-of-roads/
Author: M.R.Naganathan
*/
