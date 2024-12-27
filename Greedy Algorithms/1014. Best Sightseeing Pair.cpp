/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxFirstSpot = -1e9, maxScore = 0, spotIndex = -1;
        for(int i = 0; i <= values.size() - 1; i++){
            maxScore = max(maxScore, values[i] - i + maxFirstSpot);
            if(maxFirstSpot < values[i] + i){
                maxFirstSpot = values[i] + i;
            }
        }
        return maxScore;
    }
};

/*
Question Link: https://leetcode.com/problems/best-sightseeing-pair/
Author: M.R.Naganathan
*/
