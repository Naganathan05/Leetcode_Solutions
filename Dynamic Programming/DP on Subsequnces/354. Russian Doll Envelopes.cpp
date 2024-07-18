/*------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
---------------------------------*/

class Solution {
public:
    static bool comp(vector<int> &envelopeOne, vector<int> &envelopeTwo){
        if(envelopeOne[0] == envelopeTwo[0]) return envelopeOne[1] > envelopeTwo[1];
        return envelopeOne[0] < envelopeTwo[0]; 
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;
        for(int i = 0; i < envelopes.size(); i++){
            int currHeight = envelopes[i][1];
            auto it = lower_bound(dp.begin(), dp.end(), currHeight);
            if(it == dp.end()) dp.push_back(currHeight);
            else *it = currHeight;
        }
        return dp.size();
    }
};

/*
Question Link: https://leetcode.com/problems/russian-doll-envelopes/
Author: M.R.Naganathan
*/
