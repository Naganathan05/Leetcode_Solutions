/*-----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------------------*/

class Solution {
public:
    int numSplits(string s) {
        vector<int> leftUniq(s.length(), 0), rightUniq(s.length(), 0);
        unordered_set<char> Set;

        int goodSplits = 0;
        for(int i = 0; i <= s.length() - 1; i++){
            Set.insert(s[i]);
            leftUniq[i] = Set.size();
        }

        unordered_set<char> rightSet;
        for(int i = s.length() - 1; i >= 1; i--){
            rightSet.insert(s[i]);
            rightUniq[i] = rightSet.size();
        }

        for(int i = 0; i <= s.length() - 2; i++){
            if(leftUniq[i] == rightUniq[i + 1]) goodSplits += 1;
        }
        return goodSplits;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
Author: M.R.Naganathan
*/
