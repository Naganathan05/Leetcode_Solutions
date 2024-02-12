/*-----------------------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-------------------------------------------*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> result(m, vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int total_sum = 0;
                int cnt = 0;

                for(int k = max(0, i - 1); k < min(m, i + 2); k++){
                    for(int l = max(0, j - 1); l < min(n, j + 2); l++){
                        total_sum += img[k][l];
                        cnt++;
                    }
                }

                result[i][j] = total_sum/cnt;
            }
        }
        return result;
    }
};


/*
Question Link: https://leetcode.com/problems/image-smoother/?envType=daily-question&envId=2023-12-19
Author: M.R.Naganathan
*/
