/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
--------------------------*/

func pathSum(root *TreeNode, maxSum *int) int {
    if root == nil {
        return -1e9;
    }

    var currSum int = root.Val;
    leftSum := pathSum(root.Left, maxSum);
    rightSum := pathSum(root.Right, maxSum);

    *maxSum = max(*maxSum, max(currSum, max(leftSum, max(rightSum, max(currSum + leftSum, max(currSum + rightSum, currSum + leftSum + rightSum))))));
    return max(currSum, max(currSum + leftSum, currSum + rightSum))
}

func maxPathSum(root *TreeNode) int {
    maxSum := math.MinInt32
    pathSum(root, &maxSum)
    return maxSum
}

/*
Question Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
Author: M.R.Naganathan
*/
