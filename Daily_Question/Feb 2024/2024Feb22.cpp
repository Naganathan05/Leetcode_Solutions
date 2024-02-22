/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------------*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> freq;
        if(trust.size() == 0){
            if(n == 1) return 1;
            return -1;
        }
        for(int i = 0; i <= trust.size() - 1; i++){
            freq[trust[i][0]] = -1;
            freq[trust[i][1]] += 1;
        }
        for(auto i : freq){
            if(i.second == n - 1){
                return i.first;
            }
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-town-judge/?envType=daily-question&envId=2024-02-22
Author: M.R.Naganathan
*/
