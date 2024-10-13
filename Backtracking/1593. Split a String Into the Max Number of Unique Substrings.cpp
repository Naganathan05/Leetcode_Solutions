/*---------------------------
  Time Complexity: O(2 ^ n)
  Space Complexity: O(n * n)
------------------------------*/

class Solution {
public:
    void splitString(string &s, int i, unordered_set<string> &visitedStrings, int &currSplit, int &maxSplit){
        if(i >= s.length()){
            maxSplit = max(maxSplit, currSplit);
            return;
        }

        string currString = "";
        for(int j = i; j <= s.length() - 1; j++){
            currString += s[j];
            if(visitedStrings.find(currString) != visitedStrings.end()) continue;
            visitedStrings.insert(currString);
            currSplit += 1;
            splitString(s, j + 1, visitedStrings, currSplit, maxSplit);
            currSplit -= 1;
            visitedStrings.erase(currString);
        }
        return;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> visitedStrings;
        int currSplit = 0, maxSplit = 0;
        splitString(s, 0, visitedStrings, currSplit, maxSplit);
        return maxSplit;
    }
};

/*
Question Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/
Author: M.R.Naganathan
*/
