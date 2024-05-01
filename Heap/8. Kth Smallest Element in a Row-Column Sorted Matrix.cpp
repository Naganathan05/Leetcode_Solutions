/*-------------------------------------
  Time Complexity: O(n*log(k))
  Space Complexity: O(k)
----------------------------------------*/

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int> min_heap;
    for(int i = 0; i <= n - 1; i++){
        for(int j = 0; j <= n - 1; j++){
            min_heap.push(mat[i][j]);
            if(min_heap.size() > k) min_heap.pop();
        }
    }
    return min_heap.top();
}

/*
Question Link: https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1
Author: M.R.Naganathan
*/
