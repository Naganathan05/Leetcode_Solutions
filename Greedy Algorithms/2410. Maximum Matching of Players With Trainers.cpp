/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, maxMatch = 0;
        while(i < players.size() && j < trainers.size()){
            if(players[i] <= trainers[j]){
                i += 1;
                j += 1;
                maxMatch += 1;
            }
            else j += 1;
        }
        return maxMatch;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
Author: M.R.Naganathan
*/
