/*---------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------*/

class DisJointSet {
public:
    vector<int> parent, size;

    DisJointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] >= size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else{
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        return;
    }
};

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        DisJointSet ds = DisJointSet(m * n);
        int numBattleShips = 0;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i <= n - 1; i++){
            for(int j = 0; j <= m - 1; j++){
                if(board[i][j] == 'X'){
                    int u = i * m + j;
                    for(auto dir : directions){
                        int newX = i + dir.first;
                        int newY = j + dir.second;
                        if(newX < 0 || newY < 0 || newX >= n || newY >= m || board[newX][newY] != 'X') continue;
                        int v = newX * m + newY;
                        ds.UnionBySize(u, v);
                    }
                }
            }
        }

        for(int i = 0; i <= n - 1; i++){
            for(int j = 0; j <= m - 1; j++){
                if(board[i][j] == 'X'){
                    int u = i * m + j;
                    numBattleShips += (ds.findUParent(u) == u);
                }
            }
        }
        return numBattleShips;
    }
};

/*
Question Link: https://leetcode.com/problems/battleships-in-a-board/
Author: M.R.Naganathan
*/
