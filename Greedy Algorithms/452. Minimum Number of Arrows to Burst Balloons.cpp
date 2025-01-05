/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
------------------------------*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &point1, const vector<int> &point2){
            return point1[1] < point2[1]; 
        });
        int numArrows = 1, lastEndpoint = points[0][1];

        for(int i = 1; i <= points.size() - 1; i++){
            if(lastEndpoint < points[i][0]){
                numArrows += 1;
                lastEndpoint = points[i][1];
            }
        }
        return numArrows;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
Author: M.R.Naganathan
*/
