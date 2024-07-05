/*------------------------------------
Method: Union Find Algorithm - [DSU]
    Time Complexity: O(k * n * m)
    Space Complexity: O(m * n)
---------------------------------------*/

class DisJointSet {
public:
    vector<int> size, parent;

    DisJointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        return;
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int k = operators.size();
        vector<int> numIslands(k, 0);
        vector<vector<int>> visited(n, vector<int> (m, 0));
        DisJointSet ds = DisJointSet(n * m);
        
        for(int i = 0; i <= k - 1; i++){
            int row = operators[i][0];
            int col = operators[i][1];
            
            visited[row][col] = 1;
            
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = row + dir.first;
                int newY = col + dir.second;
                
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] == 1){
                    int u = row * m + col;
                    int v = newX * m + newY;
                    ds.UnionBySize(u, v);
                }
            }
            numIslands[i] = countIslands(ds, n, m, visited);
        }
        return numIslands;
    }
    
    int countIslands(DisJointSet &ds, int n, int m, vector<vector<int>> &visited){
        int numIslands = 0;
        for(int i = 0; i <= n - 1; i++){
            for(int j = 0; j <= m - 1; j++){
                int node = i * m + j;
                if(ds.findUParent(node) == node && visited[i][j] == 1) numIslands += 1;
            }
        }
        return numIslands;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/number-of-islands/1
Author: M.R.Naganathan
*/
