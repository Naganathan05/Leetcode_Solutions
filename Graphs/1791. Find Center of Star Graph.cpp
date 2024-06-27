/*-----------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------------*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> freq;
        for(int i = 0; i <= edges.size() - 1; i++){
            freq[edges[i][0]] += 1;
            freq[edges[i][1]] += 1;
        }
        for(auto i : freq){
            if(i.second == edges.size()) return i.first;
        }
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/find-center-of-star-graph/
Author: M.R.Naganathan
*/
