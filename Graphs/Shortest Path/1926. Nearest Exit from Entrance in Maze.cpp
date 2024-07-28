/*--------------------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(max(m, n))
-----------------------------------------------*/

class Solution {
public:
    int BFS(vector<vector<char>> &maze, vector<int> &entrance){
        int shortestPath = 0;
        vector<vector<bool>> visited(maze.size(), vector<bool> (maze[0].size(), false));
        queue<pair<int, int>> fifo;
        visited[entrance[0]][entrance[1]] = true;
        fifo.push({entrance[0], entrance[1]});
        while(!fifo.empty()){
            int size = fifo.size();
            for(int sz = 0; sz <= size - 1; sz++){
                auto coord = fifo.front();
                fifo.pop();
                int i = coord.first;
                int j = coord.second;
                if((i == 0 || j == 0 || i == maze.size() - 1 || j == maze[0].size() - 1) && !(i == entrance[0] && j == entrance[1])) return shortestPath;
                if(i + 1 < maze.size() && !visited[i + 1][j] && maze[i + 1][j] != '+'){
                    fifo.push({i + 1, j});
                    visited[i + 1][j] = true;
                }
                if(j + 1 < maze[i].size() && !visited[i][j + 1] && maze[i][j + 1] != '+'){
                    fifo.push({i, j + 1});
                    visited[i][j + 1] = true;
                }
                if(i - 1 >= 0 && !visited[i - 1][j] && maze[i - 1][j] != '+'){
                    fifo.push({i - 1, j});
                    visited[i - 1][j] = true;
                }
                if(j - 1 >= 0 && !visited[i][j - 1] && maze[i][j - 1] != '+'){
                    fifo.push({i, j - 1});
                    visited[i][j - 1] = true;
                }
            }
            shortestPath += 1;
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return BFS(maze, entrance);
    }
};

/*
Question Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
Author: M.R.Naganathan
*/
