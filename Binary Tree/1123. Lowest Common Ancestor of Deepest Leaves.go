/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
----------------------------*/

func DFS(root *TreeNode) (int, *TreeNode) {
    if root == nil {
        return 0, nil;
    }

    leftDepth, leftAncestor := DFS(root.Left);
    rightDepth, rightAncestor := DFS(root.Right);

    if leftDepth == rightDepth {
        return 1 + leftDepth, root;
    }

    if leftDepth > rightDepth {
        return 1 + leftDepth, leftAncestor;
    }
    return 1 + rightDepth, rightAncestor;
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
    _, lca := DFS(root);
    return lca;
}

/*
Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
Author: M.R.Naganathan
*/
