/*----------------------------
  Time Complexity: O(V + E)
  Space Complexity: O(V + E)
-------------------------------*/

class Solution {
public:
    void DFS(vector<vector<int>> &adjList, int garden, vector<int> &graphColors){
        for(int i = 1; i <= 4; i++){
            bool validFlower = true;
            for(auto neighbour : adjList[garden]){
                if(i == graphColors[neighbour - 1]){
                    validFlower = false;
                    break;
                }
            }
            if(validFlower){
                graphColors[garden - 1] = i;
                break;
            }
        }

        for(auto neighbour : adjList[garden]){
            if(graphColors[neighbour - 1] != -1) continue;
            DFS(adjList, neighbour, graphColors);
        }
        return;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adjList(n + 1);
        for(auto path : paths){
            adjList[path[0]].push_back(path[1]);
            adjList[path[1]].push_back(path[0]);
        }
        vector<int> graphColors(n, -1);
        for(int i = 1; i <= n; i++){
            if(graphColors[i - 1] == -1) DFS(adjList, i, graphColors);
        }
        return graphColors;
    }
};

/*
Question Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/
Author: M.R.Naganathan
*/
