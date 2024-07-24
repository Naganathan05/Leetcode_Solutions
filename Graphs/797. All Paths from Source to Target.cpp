/*------------------------------
  Time Complexity: O(2^n * n)
  Space Complexity: O(n)
--------------------------------*/

class Solution {
public:
    void Traverse(vector<vector<int>> &adjList, int currVertex, int dest, vector<int> &currPath, vector<vector<int>> &validPaths){
        if(currVertex == dest){
            currPath.push_back(dest);
            validPaths.push_back(currPath);
            currPath.pop_back();
            return;
        }

        currPath.push_back(currVertex);
        for(int neighbour : adjList[currVertex]){
            Traverse(adjList, neighbour, dest, currPath, validPaths);
        }
        currPath.pop_back();
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> validPaths;
        vector<int> currPath;
        Traverse(graph, 0, graph.size() - 1, currPath, validPaths);
        return validPaths;
    }
};

/*
Question Link: https://leetcode.com/problems/all-paths-from-source-to-target/
Author: M.R.Naganathan
*/
