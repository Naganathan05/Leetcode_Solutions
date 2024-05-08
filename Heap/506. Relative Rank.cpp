/*---------------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------------------------*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        priority_queue<pair<int, int>> q;
        for(int i = 0; i <= score.size() - 1; i++) q.push({score[i], i});

        int currRank = 1;
        while(!q.empty()){
            int ind = q.top().second;
            int s = q.top().first;
            q.pop();

            if(currRank == 1) ans[ind] = "Gold Medal";
            else if(currRank == 2) ans[ind] = "Silver Medal";
            else if(currRank == 3) ans[ind] = "Bronze Medal";
            else ans[ind] = to_string(currRank);
            currRank += 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/relative-ranks/?envType=daily-question&envId=2024-05-08
Author: M.R.Naganathan
*/
