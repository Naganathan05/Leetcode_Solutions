/*-----------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------------------------*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapper1, mapper2;
        for(int i = 0; i <= s.length() - 1; i++){
            if(mapper1.find(s[i]) == mapper1.end()){
                if(mapper2.find(t[i]) != mapper2.end()) return false;
                mapper1[s[i]] = t[i];
                mapper2[t[i]] = s[i];
            }
            else{
                if(mapper1[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/isomorphic-strings/?envType=daily-question&envId=2024-04-02
Author: M.R.Naganathan
*/
