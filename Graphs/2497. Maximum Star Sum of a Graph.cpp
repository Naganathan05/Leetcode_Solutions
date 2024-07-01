/*---------------------------------
  Time Complexity: O(nlogk)
  Space Complexity: O(n)
------------------------------------*/

class Solution {
public:
    int getStarSum(vector<int> &vals, int vertex, vector<vector<int>> &adjList, int k){
        int starSum = vals[vertex];
        priority_queue<int> maxHeap;
        for(int neighbour : adjList[vertex]) maxHeap.push(vals[neighbour]);
        while(k && !maxHeap.empty()){
            int currVal = maxHeap.top();
            maxHeap.pop();
            if(currVal < 0) break;
            starSum += currVal;
            k -= 1;
        }
        return starSum;
    }

    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adjList(vals.size());
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int maxStarSum = INT_MIN;
        for(int i = 0; i <= vals.size() - 1; i++){
            maxStarSum = max(maxStarSum, getStarSum(vals, i, adjList, k));
        }
        return maxStarSum;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-star-sum-of-a-graph/
Author: M.R.Naganathan
*/
