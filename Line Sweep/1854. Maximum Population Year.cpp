/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> lineSweep;
        for(auto &i : logs){
            lineSweep[i[0]] += 1;
            lineSweep[i[1]] -= 1;
        }

        int maxYear = -1, maxPop = 0, currPop = 0;
        for(auto &i : lineSweep){
            currPop += i.second;
            if(currPop > maxPop){
                maxPop = currPop;
                maxYear = i.first;
            }
        }
        return maxYear;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-population-year/
Author: M.R.Naganathan
*/
