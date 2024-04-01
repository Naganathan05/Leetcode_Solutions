/*------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------------------*/

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int tot_points = 0, dani_points = 0;
        for(int i : possible){
            if(i == 0) tot_points -= 1;
            if(i == 1) tot_points += 1;
        }

        for(int i = 0; i <= possible.size() - 1; i++){
            if(possible[i]) dani_points += 1;
            if(!possible[i]) dani_points -= 1;
            if(dani_points > (tot_points - dani_points) && i < possible.size() - 1) return i + 1;
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-levels-to-gain-more-points/
Author: M.R.Naganathan
*/
