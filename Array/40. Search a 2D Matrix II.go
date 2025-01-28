/*--------------------------
  Time Complexity: O(m + n)
  Space Complexity: O(1)
----------------------------*/

func searchMatrix(matrix [][]int, target int) bool {
    m, n := len(matrix), len(matrix[0]);
    i, j := 0, n - 1;

    for i < m && j >= 0 {
        if matrix[i][j] == target {
            return true;
        }

        if matrix[i][j] > target {
            j -= 1;
        } else {
            i += 1;
        }
    }
    return false;
}

/*
Question Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
Author: M.R.Naganathan
*/
