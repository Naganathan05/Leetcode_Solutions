/*----------------------------------------------------------
  Time Complexity: O(n) =>  n:Number of rows in the matrix
  Space Complexity: O(n)
----------------------------------------------------------*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winner_freq, loser_freq;
        vector<int> list;
        for(int i = 0; i <= matches.size() - 1; i++){
            winner_freq[matches[i][0]]++;
            loser_freq[matches[i][1]]++;
        }
        for(auto i : winner_freq){
            if(!loser_freq[i.first]){
                list.push_back(i.first);
            }
        }
        sort(list.begin(), list.end());
        vector<vector<int>> answer;
        answer.push_back(list);
        list.clear();
        for(auto i : loser_freq){
            if(i.second == 1){
                list.push_back(i.first);
            }
        }
        sort(list.begin(), list.end());
        answer.push_back(list);
        return answer;
    }
};

/*
Question Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/?envType=daily-question&envId=2024-01-15
Author: M.R.Naganathan
*/
