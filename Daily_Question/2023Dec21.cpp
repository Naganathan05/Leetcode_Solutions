/*----------------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------------------------*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for(int i = 0; i <= points.size() - 1; i++){
            x.push_back(points[i][0]);
        }

        sort(x.begin(), x.end());
        int maxArea = INT_MIN;
        for(int i = 0; i < x.size() - 1; i++){
            if(x[i + 1] - x[i] > maxArea){
                maxArea = x[i + 1] - x[i];
            }
        }
        return maxArea;
    }
};

/*
Question Link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21
Author: M.R.Naganathan
*/
