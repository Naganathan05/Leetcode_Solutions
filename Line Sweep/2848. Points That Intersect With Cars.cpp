/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int maxPoint = -1e9;
        for(auto &i : nums) maxPoint = max(maxPoint, i[1]);
        vector<int> lineSweep(maxPoint + 2, 0);

        for(auto &i : nums){
            lineSweep[i[0]] += 1;
            lineSweep[i[1] + 1] -= 1;
        }

        int numPoints = 0;
        for(int i = 1; i <= maxPoint; i++){
            lineSweep[i] += lineSweep[i - 1];
            numPoints += (lineSweep[i] > 0);
        }
        return numPoints;
    }
};

/*
Question Link: https://leetcode.com/problems/points-that-intersect-with-cars/
Author: N.R.Naganathan
*/
