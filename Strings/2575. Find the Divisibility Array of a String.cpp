/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------*/

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> divArray;
        long long currRem = 0;
        for(int i = 0; i <= word.length() - 1; i++){
            currRem = ((currRem * 10) + (word[i] - '0')) % m;
            divArray.push_back(currRem == 0);
        }
        return divArray;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-divisibility-array-of-a-string/
Author: M.R.Naganathan
*/
