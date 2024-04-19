/*----------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(V)
  Space Complexity: O(V)
-------------------------------------------*/

class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int color, int targetColor){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size()) return;
        if(image[i][j] != targetColor) return;
        image[i][j] = color;
        dfs(image, i - 1, j, color, targetColor);
        dfs(image, i, j - 1, color, targetColor);
        dfs(image, i + 1, j, color, targetColor);
        dfs(image, i, j + 1, color, targetColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};

/*
Question Link: https://leetcode.com/problems/flood-fill/
Author: M.R.Naganathan
*/
