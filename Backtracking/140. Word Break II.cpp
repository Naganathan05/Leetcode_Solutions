/*-----------------------------------------
  Time Complexity: O(2^n)
  Space Complexity: O(n * 2^n)
-------------------------------------------*/

class Solution {
public:
    void Word(string &s, unordered_map<string, int> &dict, int i, string &currString, vector<string> &ans){
        if(i == s.length()){
            int length = 0;
            for(char c : currString){
                if(c != ' ') length += 1;
            }
            if(length == s.length()) ans.push_back(currString.substr(0, currString.length() - 1));
            return;
        }

        for(int j = i; j <= s.length() - 1; j++){
            string temp = currString;
            if(dict[s.substr(i, j - i + 1)] > 0){
                currString += (s.substr(i, j - i + 1) + " ");
                Word(s, dict, j + 1, currString, ans);
            }
            currString = temp;
        }
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string currString = "";
        unordered_map<string, int> dict;
        for(string str : wordDict) dict[str] += 1;
        Word(s, dict, 0, currString, ans);
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/word-break-ii/
Author: M.R.Naganathan
*/
