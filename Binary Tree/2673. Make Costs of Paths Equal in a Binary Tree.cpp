/*------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n) + O(h)
--------------------------------*/

class Solution {
public:
    int mapMaximumPaths(vector<int> &cost, int node, unordered_map<int, int> &maxPathCosts){
        if(node > cost.size()) return 0;

        int leftCost = mapMaximumPaths(cost, (2 * node), maxPathCosts);
        int rightCost = mapMaximumPaths(cost, (2 * node) + 1, maxPathCosts);
        maxPathCosts[node - 1] = cost[node - 1] + max(leftCost, rightCost);
        return maxPathCosts[node - 1];
    }

    void DFS(vector<int> &cost, int node, int currSum, int &maxPath, int &minIncrements, unordered_map<int, int> &maxPathCosts){
        if(node > cost.size()) return;

        int possibleMaximum = maxPathCosts[node - 1];
        int increment = (maxPath - possibleMaximum - currSum);
        currSum += (increment + cost[node - 1]);
        minIncrements += increment;

        DFS(cost, (2 * node), currSum, maxPath, minIncrements, maxPathCosts);
        DFS(cost, (2 * node) + 1, currSum, maxPath, minIncrements, maxPathCosts);
        return;
    }

    int minIncrements(int n, vector<int>& cost) {
        unordered_map<int, int> maxPathCosts;
        int maxPath = mapMaximumPaths(cost, 1, maxPathCosts);

        int minIncrements = 0;
        DFS(cost, 1, 0, maxPath, minIncrements, maxPathCosts);
        return minIncrements;
    }
};

/*
Question Link: https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/
Author: M.R.Naganathan
*/
