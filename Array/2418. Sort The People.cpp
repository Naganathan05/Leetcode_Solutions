/*----------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(1)
------------------------------*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for(int i = 0; i < names.size(); i++){
            int maxHeight = heights[i];
            int maxInd = i;
            for(int j = i + 1; j < names.size(); j++){
                if(maxHeight <= heights[j]){
                    maxHeight = heights[j];
                    maxInd = j;
                }
            }
            swap(heights[maxInd], heights[i]);
            swap(names[maxInd], names[i]);
        }
        return names;
    }
};

/*
Question Link: https://leetcode.com/problems/sort-the-people/
Author: M.R.Naganathan
*/
