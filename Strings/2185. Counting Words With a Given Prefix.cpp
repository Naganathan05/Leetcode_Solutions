/*--------------------------
  Time Complxity: O(n * L)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    bool matchPrefix(string &word, string &prefix){
        if(prefix.length() > word.length()) return false;
        int i = 0, j = 0;
        while(j < prefix.length() && word[i] == prefix[j]){
            i += 1;
            j += 1;
        }
        return j == prefix.length();
    }

    int prefixCount(vector<string>& words, string pref) {
        int numMatches = 0;
        for(string &str : words){
            numMatches += matchPrefix(str, pref);
        }
        return numMatches;
    }
};

/*
Question Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/
Author: M.R.Naganathan
*/
