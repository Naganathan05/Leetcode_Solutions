/*--------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(logn)
-----------------------------*/

class Solution {
public:
    Node* QuadTree(vector<vector<int>> &grid, int top_leftX, int top_leftY, int bot_rightX, int bot_rightY) {
        if (top_leftX == bot_rightX && top_leftY == bot_rightY) return new Node(grid[top_leftX][top_leftY], true);

        int midX = (top_leftX + bot_rightX) / 2;
        int midY = (top_leftY + bot_rightY) / 2;

        Node* topLeft = QuadTree(grid, top_leftX, top_leftY, midX, midY);
        Node* topRight = QuadTree(grid, top_leftX, midY + 1, midX, bot_rightY);
        Node* bottomLeft = QuadTree(grid, midX + 1, top_leftY, bot_rightX, midY);
        Node* bottomRight = QuadTree(grid, midX + 1, midY + 1, bot_rightX, bot_rightY);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        return QuadTree(grid, 0, 0, grid.size() - 1, grid[0].size() - 1);
    }
};

/*
Question Link: https://leetcode.com/problems/construct-quad-tree/?envType=problem-list-v2&envId=divide-and-conquer
Author: M.R.Naganathan
*/
