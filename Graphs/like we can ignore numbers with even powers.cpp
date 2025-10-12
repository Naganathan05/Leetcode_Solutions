/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    void DFS(vector<vector<int>> &adjList, int node, int parent, vector<int> &nums, unordered_map<long long, int> &factorFrequency, long long &totalPairs) {
        long long currNum = getSquareFreeForm(nums[node]);

        totalPairs += (factorFrequency[currNum]);
        factorFrequency[currNum] += 1;

        for(int neighbour : adjList[node]) {
            if(neighbour == parent) continue;
            DFS(adjList, neighbour, node, nums, factorFrequency, totalPairs);
        }

        factorFrequency[currNum] -= 1;
        return;
    }

    long long getSquareFreeForm(int num) {
        long long squareFree = 1;
        for(int i = 2; (1LL * i * i) <= num; i++) {
            int exponentCount = 0;
            while(num % i == 0) {
                num /= i;
                exponentCount += 1;
            }

            if(exponentCount % 2 == 1) squareFree *= i;
        }
        if(num > 1) squareFree *= num;
        return squareFree;
    }
    
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> adjList(n);
        for(auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        unordered_map<long long, int> factorFrequency;
        long long totalPairs = 0;

        DFS(adjList, 0, -1, nums, factorFrequency, totalPairs);
        return totalPairs;
    }
};

/*
Question Link: https://leetcode.com/problems/sum-of-perfect-square-ancestors/
Author: M.R.Naganathan
*/
